#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Step 1: Sensor structure
struct SensorData {
    string sensorId;
    double reading;
    int batteryLevel;
};

// Step 2: DataManager class
class DataManager {
private:
    vector<SensorData*> sensors;  // store pointers to SensorData

public:
    // Step 3: Add sensor
    bool addSensor(const string& id, double reading, int battery) {
        if (id.empty() || battery < 0 || battery > 100) {
            cout << "Invalid sensor data provided" << endl;
            return false;
        }
        SensorData* newSensor = new SensorData{id, reading, battery};
        sensors.push_back(newSensor);
        cout << "Added sensor: " << id << endl;
        return true;
    }

    // Step 4: Find sensor
    SensorData* findSensor(const string& id) {
        for (SensorData* sensor : sensors) {
            if (sensor != nullptr && sensor->sensorId == id) {
                return sensor;
            }
        }
        return nullptr; // not found
    }

    // Step 5: Update sensor reading
    bool updateSensorReading(const string& id, double newReading) {
        SensorData* sensor = findSensor(id);
        if (sensor != nullptr) {
            sensor->reading = newReading;
            cout << "Updated " << id << " reading to " << newReading << endl;
            return true;
        }
        cout << "Sensor " << id << " not found" << endl;
        return false;
    }

    // Step 6: Display all sensors
    void displayAllSensors() const {
        cout << "\n=== All Sensors ===" << endl;
        for (const SensorData* sensor : sensors) {
            if (sensor != nullptr) {
                cout << "ID: " << sensor->sensorId
                     << " | Reading: " << sensor->reading
                     << " | Battery: " << sensor->batteryLevel << "%" << endl;
            }
        }
    }

    // Step 7: Destructor - clean up memory
    ~DataManager() {
        cout << "Cleaning up DataManager..." << endl;
        for (SensorData* sensor : sensors) {
            delete sensor;
        }
        sensors.clear();
    }
};

// Step 8: Testing in main()
int main() {
    DataManager manager;

    // Add sensors
    manager.addSensor("TEMP001", 23.5, 85);
    manager.addSensor("HUM001", 60.2, 92);
    manager.addSensor("", 15.0, 50);       // Invalid
    manager.addSensor("PRESS001", 1013.25, 105); // Invalid

    manager.displayAllSensors();

    // Update readings
    manager.updateSensorReading("TEMP001", 24.8);
    manager.updateSensorReading("NONEXISTENT", 0.0); // Should handle safely

    manager.displayAllSensors();

    // Safe pointer usage
    SensorData* tempSensor = manager.findSensor("TEMP001");
    if (tempSensor != nullptr) {
        cout << "\nFound temperature sensor: " << tempSensor->reading << "°C" << endl;
    } else {
        cout << "Temperature sensor not found" << endl;
    }

    // Destructor automatically cleans up memory
    return 0;
}
