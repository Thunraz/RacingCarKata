
#include "../include/SelfDrivingCar.h"

SelfDrivingCar::SelfDrivingCar(std::string algorithmVersion, std::string company)
    : Driver(algorithmVersion, company)
    , m_algorithmVersion(algorithmVersion)
{
}

std::string SelfDrivingCar::getAlgorithmVersion() const { return m_algorithmVersion; }

void SelfDrivingCar::setAlgorithmVersion(std::string algorithmVersion)
{
    // TODO does not update driver name from base class
    m_algorithmVersion = algorithmVersion;
}

std::string SelfDrivingCar::getDisplayName() const
{
    return "Self Driving Car - " + getCountry() + " (" + getAlgorithmVersion() + ")";
}
