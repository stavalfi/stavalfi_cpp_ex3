#ifndef STAVALFI_CPP_EX3_CONFIGURATIONWRITER_H
#define STAVALFI_CPP_EX3_CONFIGURATIONWRITER_H

#include <string>
#include "ConfigurationTypes.h"

class ConfigurationWriter {
public:
    virtual void write(ConfigurationTypes configurationTypes, std::string configuration) = 0;

    virtual ~ConfigurationWriter() = 0;
};


#endif //STAVALFI_CPP_EX3_CONFIGURATIONWRITER_H
