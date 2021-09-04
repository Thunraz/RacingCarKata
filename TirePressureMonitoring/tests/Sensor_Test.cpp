#include "sensor_interface.hpp"
#include <gmock/gmock.h>
#include "Sensor.h"
#include <utility>
#include <thread>
#include <chrono>

using namespace ::testing;

TEST(SensorTest,DefaultSeedRandomness){
    Sensor A;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000U));
    Sensor B;
    std::vector<double> values_A;
    std::vector<double> values_B;
    values_A.push_back(A.popNextPressurePsiValue());
    values_B.push_back(B.popNextPressurePsiValue());
    EXPECT_NE(values_A,values_B);
}

TEST(SensorTest,SeedRandomness){
    Sensor A{10};
    Sensor B{10};
    std::vector<double> values_A;
    std::vector<double> values_B;
    values_A.push_back(A.popNextPressurePsiValue());
    values_B.push_back(B.popNextPressurePsiValue());
    EXPECT_EQ(values_A,values_B);
}