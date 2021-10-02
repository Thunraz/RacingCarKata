#include "sensor_interface.hpp"
#include <gmock/gmock.h>
#include "Sensor.h"

using namespace ::testing;

TEST(SensorTest,DifferentRandomSeedsYieldDifferentPressureValues){
    Sensor A{ 10};
    Sensor B{42};
    double const value_A = A.popNextPressurePsiValue();
    double const value_B = B.popNextPressurePsiValue();
    EXPECT_NE(value_A,value_B);
}

TEST(SensorTest,SameRandomSeedYieldsSamePressureValues){
    Sensor A{10};
    Sensor B{10};
    double const value_A = A.popNextPressurePsiValue();
    double const value_B = B.popNextPressurePsiValue();
    EXPECT_EQ(value_A,value_B);
}