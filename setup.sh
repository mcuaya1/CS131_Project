#!/bin/bash

echo "Building container..."
sudo docker build -t cs131_main:latest .

echo "Starting contaienr..."
sudo docker run --privileged -it --rm --network=host cs131_main
