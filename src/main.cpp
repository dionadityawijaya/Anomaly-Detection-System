#include <iostream>
#include "SensorData.h"
#include "AnomalyDetector.h"

int main(int argc, char const *argv[])
{
    SensorData sensorData;
    AnomalyDetector anomalyDetector(2.0);

    sensorData.addDataPoint(10.0);
    sensorData.addDataPoint(12.0);
    sensorData.addDataPoint(11.5);
    sensorData.addDataPoint(10.5);
    sensorData.addDataPoint(100.0);
    sensorData.addDataPoint(10.2);

    auto anomalies = anomalyDetector.detectAnomalies(sensorData);


    std::cout << "Detected anomalies: ";
    for (double anomaly  : anomalies) {
        std::cout << anomaly << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
