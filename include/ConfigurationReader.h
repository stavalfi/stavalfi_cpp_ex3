#ifndef STAVALFI_CPP_EX3_CONFIGURATION_READER_H
#define STAVALFI_CPP_EX3_CONFIGURATION_READER_H

#include <string>
#include "ConfigurationTypes.h"

class ConfigurationReader {
public:
    virtual std::string read(ConfigurationTypes configurationTypes) const = 0;

    virtual ~ConfigurationReader() = 0;
};


#endif //STAVALFI_CPP_EX3_CONFIGURATION_READER_H
