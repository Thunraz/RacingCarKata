#include "Race.h"
#include <gtest/gtest.h>

TEST(RaceTest, GetResultsReturnsInitialEmptyList)
{
    std::list<Driver> const drivers;
    Race race("whocares", drivers);

    EXPECT_TRUE(race.getResults().empty());
}

TEST(RaceTest, GetResultsReturnsInitialListWithOneDriverReturnsCorrectSize)
{
    Driver const driver { "name", "country" };
    std::list<Driver> const drivers { driver };

    Race race("whocares", drivers);

    EXPECT_EQ(race.getResults().size(), 1);
}

TEST(RaceTest, GetResultsReturnsInitialListWithOneDriverIsEqual)
{
    Driver const driver { "name", "country" };
    std::list<Driver> const drivers { driver };

    Race race("whocares", drivers);

    EXPECT_EQ(race.getResults(), drivers);
}

TEST(RaceTest, GetDriverNameForRegularDriver)
{
    auto const expectedName = "name";
    Driver const driver { expectedName, "country" };
    std::list<Driver> const drivers { driver };

    Race race("whocares", drivers);

    EXPECT_EQ(race.getDriverName(driver), expectedName);
}

TEST(RaceTest, GetDriverNameForSelfDrivingCarDriver)
{
    FAIL();
    //    auto const expectedName = "name";
    //    Driver const driver { expectedName, "country" };
    //    std::list<Driver> const drivers {
    //        driver
    //    };
    //
    //    Race race("whocares", drivers);
    //
    //    EXPECT_EQ(race.getDriverName(driver), expectedName);
}
