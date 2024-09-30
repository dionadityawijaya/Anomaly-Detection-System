#include <gtest/gtest.h>

#include "SensorData.h"
#include "AnomalyDetector.h"

// Test for detecting anomalies correctly
TEST(AnomalyDetectorTest, DetectsAnomalies) {
    SensorData sensorData;
    AnomalyDetector anomalyDetector(2.0); // Ambang batas deteksi anomali

    // Simulated sensor data
    sensorData.addDataPoint(10.0);
    sensorData.addDataPoint(12.0);
    sensorData.addDataPoint(11.0);
    sensorData.addDataPoint(10.5);
    sensorData.addDataPoint(100.0); // Anomaly
    sensorData.addDataPoint(10.2);

    auto anomalies = anomalyDetector.detectAnomalies(sensorData);

    // Verify that the detected anomalies are correct
    EXPECT_EQ(anomalies.size(), 1);
    EXPECT_EQ(anomalies[0], 100.0);
}

// Test for no anomalies detected
TEST(AnomalyDetectorTest, NoAnomaliesDetected) {
    SensorData sensorData;
    AnomalyDetector anomalyDetector(2.0); // Ambang batas deteksi anomali

    // Normal sensor data
    sensorData.addDataPoint(10.0);
    sensorData.addDataPoint(11.0);
    sensorData.addDataPoint(10.5);
    sensorData.addDataPoint(12.0);
    sensorData.addDataPoint(10.2);

    auto anomalies = anomalyDetector.detectAnomalies(sensorData);

    // Verify that no anomalies are detected
    EXPECT_EQ(anomalies.size(), 0);
}

// Test for multiple anomalies detected
TEST(AnomalyDetectorTest, MultipleAnomaliesDetected) {
    SensorData sensorData;
    AnomalyDetector anomalyDetector(1.0); // Ambang batas deteksi anomali yang lebih sensitif

    // Simulated sensor data with multiple anomalies
    sensorData.addDataPoint(10.0);
    sensorData.addDataPoint(200.0); // Anomaly
    sensorData.addDataPoint(12.0);
    sensorData.addDataPoint(300.0); // Anomaly
    sensorData.addDataPoint(11.5);
    
    auto anomalies = anomalyDetector.detectAnomalies(sensorData);

    // Verify that the detected anomalies are correct
    EXPECT_EQ(anomalies.size(), 2);
    EXPECT_EQ(anomalies[0], 200.0);
    EXPECT_EQ(anomalies[1], 300.0);
}

// Main function for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
