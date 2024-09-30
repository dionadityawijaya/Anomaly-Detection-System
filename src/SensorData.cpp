#include "SensorData.h"


SensorData::SensorData() {}

void SensorData::addDataPoint(double value) {
    dataPoints.push_back(value);
}

const std::vector<double>& SensorData::getDataPoints() const {
    return dataPoints;
}

