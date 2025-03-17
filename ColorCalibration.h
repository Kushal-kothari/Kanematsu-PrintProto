#ifndef COLOR_CALIBRATION_H
#define COLOR_CALIBRATION_H

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class ColorCalibration {
private:
    std::map<std::string, std::string> colorProfiles;

public:
    ColorCalibration() {
        loadConfig("settings.config");
    }

    void loadConfig(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "[ERROR] Could not open config file: " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream is_line(line);
            std::string key, value;
            if (std::getline(is_line, key, '=') && std::getline(is_line, value)) {
                colorProfiles[key] = value;
            }
        }
        std::cout << "[INFO] Loaded color calibration profiles from " << filename << std::endl;
    }

    std::string getCalibratedColor(const std::string& color) {
        return colorProfiles.count(color) ? colorProfiles[color] : "Standard " + color;
    }
};

#endif
