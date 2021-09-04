#include "Alarm.h"
#include "sensor_interface.hpp"
#include <gmock/gmock.h>

using namespace ::testing;

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

TEST(Alarm, AlarmIsOnWhenPressureIsBelowDefaultLowThreshold)
{
    SensorMock const pressure_sensor;
    Alarm alarm { pressure_sensor };

    EXPECT_CALL(pressure_sensor, popNextPressurePsiValue())
        .WillOnce(Return(3));

    alarm.check();
    ASSERT_EQ(true, alarm.isAlarmOn());
}

TEST(Alarm, AlarmIsOnWhenPressureIsBelowSetLowThreshold)
{
    SensorMock const pressure_sensor;
    Alarm alarm { pressure_sensor };

    alarm.setLowPressureThreshold(10.0);
    EXPECT_CALL(pressure_sensor, popNextPressurePsiValue())
        .WillOnce(Return(9.0));

    alarm.check();
    ASSERT_EQ(true, alarm.isAlarmOn());
}

TEST(Alarm, AlarmIsOnWhenPressureIsAboveDefaultHighThreshold)
{
    SensorMock const pressure_sensor;
    Alarm alarm { pressure_sensor };

    EXPECT_CALL(pressure_sensor, popNextPressurePsiValue())
    .WillOnce(Return(33.0));

    alarm.check();
    ASSERT_EQ(true, alarm.isAlarmOn());
}

TEST(Alarm, AlarmIsOnWhenPressureIsAboveSetHighThreshold)
{
    SensorMock const pressure_sensor;
    Alarm alarm { pressure_sensor };

    alarm.setHighPressureThreshold(100.0);
    EXPECT_CALL(pressure_sensor, popNextPressurePsiValue())
    .WillOnce(Return(101.0));

    alarm.check();
    ASSERT_EQ(true, alarm.isAlarmOn());
}

}
