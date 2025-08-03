#include <iostream>
#include <string>
#include <vector>
#include <map>

// IoT Device class
class IoTDevice {
private:
    std::string deviceId;
    std::string deviceType;
    std::vector<std::string> sensors;
public:
    IoTDevice(std::string id, std::string type, std::vector<std::string> sens) : deviceId(id), deviceType(type), sensors(sens) {}
    void printDeviceInfo() {
        std::cout << "Device ID: " << deviceId << std::endl;
        std::cout << "Device Type: " << deviceType << std::endl;
        std::cout << "Sensors: ";
        for (const auto& sensor : sensors) {
            std::cout << sensor << " ";
        }
        std::cout << std::endl;
    }
};

// IoT Device Generator class
class IoTDeviceGenerator {
private:
    std::map<std::string, IoTDevice> devices;
    int deviceIdCounter;
public:
    IoTDeviceGenerator() : deviceIdCounter(0) {}
    void generateDevice(std::string type, std::vector<std::string> sens) {
        std::string deviceId = "DEV_" + std::to_string(deviceIdCounter++);
        IoTDevice device(deviceId, type, sens);
        devices[deviceId] = device;
        std::cout << "Generated device: " << deviceId << std::endl;
    }
    void printAllDevices() {
        for (const auto& device : devices) {
            device.second.printDeviceInfo();
        }
    }
};

int main() {
    IoTDeviceGenerator generator;
    generator.generateDevice("TemperatureSensor", {"Temperature", "Humidity"});
    generator.generateDevice("MotionSensor", {"MotionDetection"});
    generator.printAllDevices();
    return 0;
}