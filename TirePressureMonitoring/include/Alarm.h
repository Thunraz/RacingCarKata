#pragma once

#include "sensor_interface.hpp"

class Alarm {
public:
    Alarm(SensorInterface const& sensor);
    void check();
    bool isAlarmOn() const;

    void setLowPressureThreshold(double newThreshold);
    void setHighPressureThreshold(double newThreshold);


protected:
    SensorInterface const& m_sensor;
    double m_lowPressureThreshold;
    double m_highPressureThreshold;
    bool m_alarmOn;
};
