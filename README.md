# CS131_Project

## Use Case
The problem we are addressing is the lack of better navigation and assistive devices for blind individuals. The industry our problem belongs to is the healthcare industry. Some challenges we foresee include but are not limited to: the need for accessible data/fast decision-making, for haptic feedback to be subtle yet noticeable, demanding navigation/computations which may affect latency, a device that must be lightweight and portable, for our device to be intuitive to use and practical, for our operations to be non-conflicting and concurrent, powerful sensors to drive our operations, persistent access to APIs that will drive our computations, efficient management of our data to monitor performance, and for our device to be as non-obtrusive as possible (such as incorporating headphones for audio updates). Below, we discuss our solution to the problem introduced above.

## Solution
This low-cost smart walking cane addresses navigation challenges faced by visually impaired individuals. The cane enhances spatial awareness and mobility with a combination of real-time sensing, haptic feedback, and intelligent edge-based decision making. All computation occurs on the device to ensure low latency and privacy. This is important because the user requires instant responsiveness as well as making sure individuals are not tracked without their consent. The cane is also lightweight and extremely practical for everyday use, making it a good alternative to a regular walking cane.

## Demo
Our system would be composed of a Jetson nano, a microcontroller device, a LIDAR sensor, and a bluetooth module . The Jetson Nano would be connected to a microcontroller device, which itself is connected to the LIDAR sensor. The LIDAR sensor would be attached to the walking cane, measuring the distance between the cane and obstacles such as pedestrians, cars, etc. This data would then be collected/filtered by the microcontroller device and sent over to the Jetson nano to be processed completely.

The Jetson nano will process this information and then alert the user about any objects detected via text to speech (delivering this information via a bluetooth module), which would ideally be paired with a user’s headset or earpiece device. On top of processing the data collected by the microcontroller, the Jetson nano would also be connected to Google map’s API which the user will be able to interact via speech prompts, asking the nano for directions to certain locations. 

The nano would also be providing directions and feedback throughout the journey to the user via text to speech. The nano will also be collecting other data such as distance travelled, average heart rate, and more. This data will then be sent over to the cloud, where it will be displayed via a front end such as a website or app in an easy to navigate way, so the user’s healthcare provider or family can view this data.  
## Task Distribution
### Edge Devices:
 - Jetson Nano: The Jetson Nano will be the central unit in which all the data comes in and is processed. The Jetson Nano will connect to the Google Maps API to create a navigation path for the user to get from 
 their current location to their final destination. Information such as when to turn a certain direction will be transmitted to the user of the cane from the Jetson Nano using the Text-to-Speech API. The camera 
 will also be connected to the Jetson Nano, as it is ideal for video processing. To process video inputs on the Jetson Nano, we will use OpenCV.
 Second Edge Device: This edge device will be a microcontroller that has a LiDAR sensor connected to it. The data from the lidar sensor will be pre-processed and sent over the Jetson Nano to be used in 
 conjunction with the other data. 

 - Cloud:
 On the cloud, we will store the crucial information collected and processed by the edge devices. This data will include total distance traveled, time and distance traveled on previous trips, current software 
 version of the stick, and other data deemed useful. The cloud will not, however, store private information such as the live location of the user or the exact GPS coordinates of previous trips.  
 Single Pane Of Glass:
 For our monitoring system, we will use a mobile app that can allow family members and healthcare providers to view information such as total distance travelled and previous trips taken. 
