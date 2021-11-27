#include "Race.h"
#include <SelfDrivingCar.h>
#include <gtest/gtest.h>

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

TEST(RaceTest, GetDriverNameForSelfDrivingCarDriver)
{
    std::string const algorithmVersion = "1.0.0";
    std::string const companyName = "CrashemFast";
    auto const expectedName = "Self Driving Car - " + companyName + " (" + algorithmVersion + ")";

    std::shared_ptr<SelfDrivingCar> const selfDrivingCar
        = std::make_shared<SelfDrivingCar>(algorithmVersion, companyName);
    std::list<std::shared_ptr<Driver>> const drivers { selfDrivingCar };

    Race race("whocares", drivers);

    EXPECT_EQ(race.getDriverName(selfDrivingCar), expectedName);
}

TEST(RaceTest, PositionReturnsCorrectValue)
{
    auto driver = std::make_shared<Driver>("name", "country");
    Race race("whocares", { driver });

    EXPECT_EQ(race.position(driver), 0);
}

TEST(RaceTest, PositionReturnsCorrectValueWithMultipleDrivers)
{
    auto driver1 = std::make_shared<Driver>("name", "country");
    auto driver2 = std::make_shared<Driver>("name2", "country2");
    auto selfDriver = std::make_shared<SelfDrivingCar>("1.0", "Company");
    Race race("whocares", { driver1, driver2, selfDriver });

    EXPECT_EQ(race.position(driver2), 1);
    EXPECT_EQ(race.position(selfDriver), 2);
}

TEST(RaceTest, PointsForPosition0)
{
    auto driver1 = std::make_shared<Driver>("name", "country");
    auto driver2 = std::make_shared<Driver>("name2", "country2");
    auto selfDriver = std::make_shared<SelfDrivingCar>("1.0", "Company");
    Race race("whocares", { driver1, driver2, selfDriver });

    EXPECT_EQ(race.getPoints(driver1), 25);
}

TEST(RaceTest, PointsForPosition1)
{
    auto driver1 = std::make_shared<Driver>("name", "country");
    auto driver2 = std::make_shared<Driver>("name2", "country2");
    auto selfDriver = std::make_shared<SelfDrivingCar>("1.0", "Company");
    Race race("whocares", { driver1, driver2, selfDriver });

    EXPECT_EQ(race.getPoints(driver2), 18);
}

TEST(RaceTest, PointsForPosition2)
{
    auto driver1 = std::make_shared<Driver>("name", "country");
    auto driver2 = std::make_shared<Driver>("name2", "country2");
    auto selfDriver = std::make_shared<SelfDrivingCar>("1.0", "Company");
    Race race("whocares", { driver1, driver2, selfDriver });

    EXPECT_EQ(race.getPoints(selfDriver), 15);
}

TEST(RaceTest, PositionForDriverNotInRaiseRaisesException)
{
    auto driver1 = std::make_shared<Driver>("name", "country");
    auto driver2 = std::make_shared<Driver>("name2", "country2");
    auto selfDriver = std::make_shared<SelfDrivingCar>("1.0", "Company");
    Race race("whocares", { driver1, driver2 });

    ASSERT_ANY_THROW(race.position(selfDriver));
}
