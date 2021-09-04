#pragma once

class SensorInterface {
public:
    SensorInterface() = default;
    virtual ~SensorInterface() = default;

    virtual double popNextPressurePsiValue() const = 0;
};