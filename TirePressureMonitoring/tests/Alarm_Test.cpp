#include <gmock/gmock.h>
#include "Alarm.h"

namespace {
  TEST(Alarm, InitialAlarmValueIsOff) {
    Sensor const pressue_sensor;
    Alarm const alarm{pressue_sensor};
    ASSERT_EQ(false, alarm.isAlarmOn());
  }
}
