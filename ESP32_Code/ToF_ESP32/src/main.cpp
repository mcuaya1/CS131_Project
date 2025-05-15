#include <SPI.h>
#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();
double distance = -2;

#define PIN_MISO 19
#define PIN_MOSI 23
#define PIN_SCK 18
#define PIN_SS 5

volatile boolean dataReceived = false;
char receivedData;
char sendBuffer[10];

void IRAM_ATTR onDataReceive() {
  dataReceived = true;
}

void sendDistanceUART(double distanceToSend) {
  char buffer[20];
  snprintf(buffer, sizeof(buffer), "%.2f\n", distanceToSend);
  Serial.write(buffer);
}

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(1);

  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }

  pinMode(PIN_MISO, OUTPUT);
  pinMode(PIN_SS, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_SS), onDataReceive, FALLING);

  SPI.begin(PIN_SCK, PIN_MISO, PIN_MOSI, PIN_SS);
  SPI.setHwCs(false); 

  Serial.println("SPI Slave ready");
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);

  if (measure.RangeStatus != 4) {
    double distanceInches = measure.RangeMilliMeter / 25.4;
    distance = (distanceInches < 1) ? 0 : distanceInches;
  } else {
    distance = -1;
  }

  //Serial Output
  Serial.print("Distance (in): ");
  Serial.println(distance);

  //SENDS DATA VIA UART
  sendDistanceUART(distance);
  
  //SENDS DATA VIA SPI
  if (dataReceived) {
    dataReceived = false;

    snprintf(sendBuffer, sizeof(sendBuffer), "%.2f", distance);
    
    SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
    for (int i = 0; i < strlen(sendBuffer); i++) {
      SPI.transfer(sendBuffer[i]);
    }
    SPI.endTransaction();
  }

  delay(100);
}