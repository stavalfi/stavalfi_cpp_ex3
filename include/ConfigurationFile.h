#ifndef STAVALFI_CPP_EX3_CONFIGURATION_FILE_H
#define STAVALFI_CPP_EX3_CONFIGURATION_FILE_H

#include "ConfigurationReader.h"
#include "ConfigurationWriter.h"

class ConfigurationFile : public ConfigurationReader, public ConfigurationWriter {

    ConfigurationFile() {}

    ConfigurationFile(const ConfigurationFile &) = delete;

public:
    static ConfigurationFile &getInstance();

    std::string read(ConfigurationTypes configurationTypes) const override;

    ~ConfigurationFile() override;

    void write(ConfigurationTypes configurationTypes, std::string configuration) override;

};


#endif //STAVALFI_CPP_EX3_CONFIGURATION_FILE_H
