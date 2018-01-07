#include "ConfigurationFile.h"

#define FILE_NAME my-heap-configuration.txt

std::string ConfigurationFile::read(ConfigurationTypes configurationTypes) const {
    return nullptr;
}

void ConfigurationFile::write(ConfigurationTypes configurationTypes, std::string configuration) {

}

ConfigurationFile::~ConfigurationFile() {

}

ConfigurationFile &ConfigurationFile::getInstance() {
    static ConfigurationFile configurationFile;
    return configurationFile;
}
