#include "Race.h"
#include <gtest/gtest.h>
#include <SelfDrivingCar.h>

TEST(RaceTest, GetResultsReturnsInitialEmptyList)
{
    std::list<std::shared_ptr<Driver>> const drivers;
    Race race("whocares", drivers);

    EXPECT_TRUE(race.getResults().empty());
}

TEST(RaceTest, GetResultsReturnsInitialListWithOneDriverReturnsCorrectSize)
{
    std::shared_ptr<Driver> const driver = std::make_shared<Driver>("name", "country");
    std::list<std::shared_ptr<Driver>> const drivers { driver };

    Race race("whocares", drivers);

    EXPECT_EQ(race.getResults().size(), 1);
}

TEST(RaceTest, GetResultsReturnsInitialListWithOneDriverIsEqual)
{
    std::shared_ptr<Driver> const driver = std::make_shared<Driver>("name", "country");
    std::list<std::shared_ptr<Driver>> const drivers { driver };

    Race race("whocares", drivers);

    EXPECT_EQ(race.getResults(), drivers);
}

TEST(RaceTest, GetDriverNameForRegularDriver)
{
    auto const expectedName = "name";
    std::shared_ptr<Driver> const driver = std::make_shared<Driver>(expectedName, "country");
    std::list<std::shared_ptr<Driver>> const drivers { driver };

    Race race("whocares", drivers);

    EXPECT_EQ(race.getDriverName(driver), expectedName);
}
//
//TEST(RaceTest, GetDriverNameForSelfDrivingCarDriver)
//{
//    auto const expectedName = "1.0";
//    SelfDrivingCar const selfDrivingCar(expectedName, "CrashemFast");
//    std::list<std::shared_ptr<Driver>> const drivers {
//        selfDrivingCar
//    };
//
//    Race race("whocares", drivers);
//
//    EXPECT_EQ(race.getDriverName(selfDrivingCar), expectedName);
//}

//TEST(RaceTest, GetDriverNameForSelfDrivingCarDriverHowItShouldWork)
//{
//    std::string const algorithmVersion = "1.0.0";
//    std::string const companyName = "CrashemFast";
//    auto const expectedName = "Self Driving Car - " + companyName + " (" + algorithmVersion + ")";
//
//    SelfDrivingCar const selfDrivingCar(algorithmVersion, companyName);
//    std::list<std::shared_ptr<Driver>> const drivers {
//        selfDrivingCar
//    };
//
//    Race race("whocares", drivers);
//
//    EXPECT_EQ(race.getDriverName(selfDrivingCar), expectedName);
//}