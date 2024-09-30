#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <vector>

class SensorData {
    public:
        SensorData();
        void addDataPoint(double value);
        const std::vector<double>& getDataPoints() const;

    private:
        std::vector<double> dataPoints;
};


#endif