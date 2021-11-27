#pragma once

#include "Driver.h"

#include <string>

class SelfDrivingCar : public Driver {
    std::string m_algorithmVersion;

public:
    SelfDrivingCar(std::string algorithmVersion, std::string company);

    std::string getAlgorithmVersion() const;

    void setAlgorithmVersion(std::string algorithmVersion);
    std::string getDisplayName() const override;
};
