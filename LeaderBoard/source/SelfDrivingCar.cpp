
#include "../include/SelfDrivingCar.h"

SelfDrivingCar::SelfDrivingCar(std::string algorithmVersion, std::string company)
    : Driver(algorithmVersion, company)
    , m_algorithmVersion(algorithmVersion)
{
}

std::string SelfDrivingCar::getAlgorithmVersion() { return m_algorithmVersion; }

void SelfDrivingCar::setAlgorithmVersion(std::string algorithmVersion)
{
    // TODO does not update driver name from base class
    m_algorithmVersion = algorithmVersion;
}
