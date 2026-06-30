#include "ConfigManager.h"
#include <iostream>
#include <fstream>

ConfigManager::ConfigManager(const std::string& path) : configFilePath(path) {}

ConfigManager::~ConfigManager() {}

bool ConfigManager::loadConfiguration() {
    std::ifstream file(configFilePath);
    if (!file.is_open()) {
        std::cerr << "[Error] Could not open configuration file." << std::endl;
        return false;
    }

    std::string key, value;
    while (file >> key >> value) {
        settings[key] = value;
    }
    
    file.close();
    return true;
}

bool ConfigManager::saveConfiguration() {
    std::ofstream file(configFilePath);
    if (!file.is_open()) {
        std::cerr << "[Error] Could not save configuration file." << std::endl;
        return false;
    }

    for (const auto& pair : settings) {
        file << pair.first << " " << pair.second << "\n";
    }

    file.close();
    return true;
}

std::string ConfigManager::getSetting(const std::string& key) const {
    auto it = settings.find(key);
    if (it != settings.end()) {
        return it->second;
    }
    return "";
}

void ConfigManager::setSetting(const std::string& key, const std::string& value) {
    settings[key] = value;
}