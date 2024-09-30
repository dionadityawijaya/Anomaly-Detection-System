# Sensor Anomaly Detection System

This project implements a simple sensor data anomaly detection system using C++. The system collects sensor data points and detects anomalies based on the statistical properties of the data (mean and standard deviation). It also includes unit tests using Google Test (gtest) to ensure correctness.

## Features
- Collect and store sensor data points.
- Detect anomalies in the data using statistical analysis (mean and standard deviation).
- Customizable anomaly detection threshold.
- Unit tests to verify the functionality.

## Directory Structure


## How to Build and Run

### Prerequisites
- `g++` compiler with C++17 support.
- `Google Test (gtest)` library installed.
- Make sure the `gtest` library is linked properly in the Makefile.

### Build the Main Application
To build the main application, run the following command:
```bash
$ make
