#include "AnomalyDetector.h"
#include <cmath>

AnomalyDetector::AnomalyDetector(double threshold) : threshold(threshold) {}

std::vector<double> AnomalyDetector::detectAnomalies(const SensorData& data) const {
    std::vector<double> anomalies;
    const auto& dataPoints = data.getDataPoints();

    double mean = calculateMean(dataPoints);
    double stdDev = calculateStandardDeviation(dataPoints, mean);

    for (double value : dataPoints) {
        if (std::abs(value - mean) > threshold * stdDev) {
            anomalies.push_back(value);
        }
    }

    return anomalies;
}

double AnomalyDetector::calculateMean(const std::vector<double>& data) const {
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    return sum / data.size();
}

double AnomalyDetector::calculateStandardDeviation(const std::vector<double>& data, double mean) const {
    double sum = 0.0;
    for (double value : data) {
        sum += (value - mean) * (value - mean);
    }
    return std::sqrt(sum / data.size());
}
