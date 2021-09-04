#include "Alarm.h"
#include "sensor_interface.hpp"
#include <gmock/gmock.h>
#include <utility>

using namespace ::testing;

namespace {

class SensorMock : public SensorInterface {
public:
  MOCK_METHOD(double, popNextPressurePsiValue, (), (const, override));
};

class AlarmTest : public Test {
protected:
  SensorMock const pressure_sensor;
  Alarm alarm{pressure_sensor};
};

TEST_F(AlarmTest, InitialAlarmValueIsOff) {
  ASSERT_EQ(false, alarm.isAlarmOn());
}

class AlarmTestDefaultLowThresholdTestFixture
    : public AlarmTest,
      public WithParamInterface<double> {};

TEST_P(AlarmTestDefaultLowThresholdTestFixture,
       AlarmIsOnWhenPressureIsBelowDefaultLowThreshold) {
  EXPECT_CALL(pressure_sensor, popNextPressurePsiValue())
      .WillOnce(Return(GetParam()));

  alarm.check();
  ASSERT_EQ(true, alarm.isAlarmOn());
}

INSTANTIATE_TEST_SUITE_P(AlarmTestLowThresholdTest,
                         AlarmTestDefaultLowThresholdTestFixture,
                         Values(3.0, 0.0, 16.999));

class AlarmTestSetLowThresholdTestFixture
    : public AlarmTest,
      public WithParamInterface<std::pair<double, double>> {};

TEST_P(AlarmTestSetLowThresholdTestFixture,
       AlarmIsOnWhenPressureIsBelowSetLowThreshold) {
  alarm.setLowPressureThreshold(GetParam().first);
  EXPECT_CALL(pressure_sensor, popNextPressurePsiValue())
      .WillOnce(Return(GetParam().second));

  alarm.check();
  ASSERT_EQ(true, alarm.isAlarmOn());
}

INSTANTIATE_TEST_SUITE_P(AlarmTestSetLowThresholdTest,
                         AlarmTestSetLowThresholdTestFixture,
                         Values(std::make_pair(11.0, 10.0),
                                std::make_pair(0.0, -1.0),
                                std::make_pair(1000.0, 999.9)));

class AlarmTestDefaultHighThresholdTestFixture
    : public AlarmTest,
      public WithParamInterface<double> {};

TEST_P(AlarmTestDefaultHighThresholdTestFixture,
       AlarmIsOnWhenPressureIsAboveDefaultHighThreshold) {
  EXPECT_CALL(pressure_sensor, popNextPressurePsiValue())
      .WillOnce(Return(GetParam()));

  alarm.check();
  ASSERT_EQ(true, alarm.isAlarmOn());
}

INSTANTIATE_TEST_SUITE_P(AlarmTestDefaultHighThresholdTest,
                         AlarmTestDefaultHighThresholdTestFixture,
                         Values(33.0, 21.01, 150.0));

class AlarmTestSetHighThresholdTestFixture
    : public AlarmTest,
      public WithParamInterface<std::pair<double, double>> {};

TEST_P(AlarmTestSetHighThresholdTestFixture, AlarmIsOnWhenPressureIsAboveSetHighThreshold) {
  alarm.setHighPressureThreshold(GetParam().first);
  EXPECT_CALL(pressure_sensor, popNextPressurePsiValue())
      .WillOnce(Return(GetParam().second));

  alarm.check();
  ASSERT_EQ(true, alarm.isAlarmOn());
}

INSTANTIATE_TEST_SUITE_P(AlarmTestSetHighThresholdTest,
                         AlarmTestSetHighThresholdTestFixture,
                         Values(std::make_pair(10.0, 11.0),
                                std::make_pair(-1.0, 0.0),
                                std::make_pair(999.0, 1000.0)));


} // namespace
