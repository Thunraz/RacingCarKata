
#include "../include/Sensor.h"

Sensor::Sensor(unsigned const seed)
{
    m_random_engine.seed(seed);
}

double Sensor::popNextPressurePsiValue() const
{
    // placeholder implementation that simulates a real sensor in a real tire
    std::uniform_real_distribution<double> distribution {16.0,22.0};
    double pressure = distribution(m_random_engine);
    return pressure;
}
