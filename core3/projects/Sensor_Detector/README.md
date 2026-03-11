# Sensor Data Manager

## Project Overview
This project demonstrates a step-by-step C++ programming exercise for managing sensor data in a safe and dynamic way. The system allows you to store, update, and display information from multiple sensors, each with a unique ID, a reading, and a battery level. Dynamic memory management and pointer safety are emphasized.

---

## Steps Implemented

### 1. Define a Sensor Structure
A `struct SensorData` holds the following information for each sensor:
- `string sensorId` – Unique ID of the sensor
- `double reading` – Current measurement
- `int batteryLevel` – Battery percentage (0–100)

### 2. Create a DataManager Class
The `DataManager` class manages multiple sensors using a `vector<SensorData*>`.

### 3. Add Sensor
Function:  
```cpp
bool addSensor(const string& id, double reading, int battery)
