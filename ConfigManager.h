#pragma once
#include <string>
#include <unordered_map>

class ConfigManager {
private:
    std::string configFilePath;
    std::unordered_map<std::string, std::string> settings;

public:
    ConfigManager(const std::string& path);
    ~ConfigManager();

    bool loadConfiguration();
    bool saveConfiguration();
    
    std::string getSetting(const std::string& key) const;
    void setSetting(const std::string& key, const std::string& value);
};