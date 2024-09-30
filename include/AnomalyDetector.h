#ifndef ANOMALYDETECTOR_H
#define ANOMALYDETECTOR_H

#include "SensorData.h"
#include <vector>

class AnomalyDetector {
    public:
        AnomalyDetector(double threshold);
        std::vector<double> detectAnomalies(const SensorData& data) const;

    private:
        double calculateMean(const std::vector<double>& data) const;
        double calculateStandardDeviation(const std::vector<double>& data, double mean) const;

        double threshold;
};

#endif