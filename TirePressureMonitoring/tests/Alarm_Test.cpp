#include "Alarm.h"
#include "sensor_interface.hpp"
#include <gmock/gmock.h>

namespace {

class SensorMock : public SensorInterface {
public:
    MOCK_METHOD(double, popNextPressurePsiValue, (), (const, override));
};

TEST(Alarm, InitialAlarmValueIsOff)
{
    SensorMock const pressure_sensor;
    Alarm const alarm { pressure_sensor };
    ASSERT_EQ(false, alarm.isAlarmOn());
}
}
