#pragma once

#include "sensor_interface.hpp"

class Sensor : public SensorInterface {
public:
    Sensor();
    double popNextPressurePsiValue() const override;
};
