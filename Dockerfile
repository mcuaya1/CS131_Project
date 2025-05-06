FROM ubuntu:22.04

# Update and upgrade package list. Install necessary packages for enviornment
RUN DEBIAN_FRONTEND=noninteractive apt-get update -y && apt-get -y upgrade \
    && apt-get install --no-install-recommends -y build-essential python3 python3.10-venv pip \
    && rm -rf /var/lib/apt/lists/*

# Set work directory
WORKDIR /srv/

# Create python virtual enviornment
RUN python3 -m venv .venv
ENV PATH=$PWD/.venv/bin:$PATH

# Install necessary python packages
RUN pip install --no-cache-dir googlemaps Jetson.GPIO
