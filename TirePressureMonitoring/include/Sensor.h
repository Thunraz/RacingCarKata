#pragma once

#include "sensor_interface.hpp"
#include <random>
#include <cstdlib>
#include <time.h>

class Sensor : public SensorInterface {
public:
    explicit Sensor(unsigned seed = static_cast<unsigned>(time(0U)));
    double popNextPressurePsiValue() const override;
private:
    std::default_random_engine mutable m_random_engine;
};
