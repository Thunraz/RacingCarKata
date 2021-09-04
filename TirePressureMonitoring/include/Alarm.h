#pragma once

#include "Sensor.h"

class Alarm
{
public:
    Alarm(Sensor const& sensor);
    void check();
    bool isAlarmOn() const;

protected:
    Sensor const& m_sensor;
    double m_lowPressureThreshold;
    double m_highPressureThreshold;
    bool m_alarmOn;
};
