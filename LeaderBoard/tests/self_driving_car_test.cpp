#include "SelfDrivingCar.h"
#include <gtest/gtest.h>

TEST(SelfDrivingCarTest, CorrectAlgorithmVersion)
{
    auto const expectedVersion = "1.0.0";
    SelfDrivingCar selfDrivingCar { expectedVersion, "ShadyCompany" };

    ASSERT_EQ(selfDrivingCar.getAlgorithmVersion(), expectedVersion);
}

TEST(SelfDrivingCarTest, CorrectCountry)
{
    auto const expectedCountry = "ShadyCompany";
    SelfDrivingCar selfDrivingCar { "1.0.0", expectedCountry };

    ASSERT_EQ(selfDrivingCar.getCountry(), expectedCountry);
}

TEST(SelfDrivingCarTest, AlgorithmIsDriverName)
{
    auto const expectedVersion = "1.0.0";
    SelfDrivingCar selfDrivingCar { expectedVersion, "ShadyCompany" };

    ASSERT_EQ(selfDrivingCar.getName(), expectedVersion);
}

TEST(SelfDrivingCarTest, AlgorithmAfterSetAlgorithm)
{
    SelfDrivingCar selfDrivingCar { "1.0.0", "ShadyCompany" };

    auto const expectedVersion = "1.1.0";
    selfDrivingCar.setAlgorithmVersion(expectedVersion);

    ASSERT_EQ(selfDrivingCar.getAlgorithmVersion(), expectedVersion);
}
