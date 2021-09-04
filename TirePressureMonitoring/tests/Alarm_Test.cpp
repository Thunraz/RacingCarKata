#include <gmock/gmock.h>
#include "Alarm.h"

namespace {
  TEST(Alarm, InitialAlarmValueIsOff) {
    Alarm const alarm{};
    ASSERT_EQ(false, alarm.isAlarmOn());
  }
}
