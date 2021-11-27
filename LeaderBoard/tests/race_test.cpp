#include <gtest/gtest.h>
#include "Race.h"


TEST(RaceTest, GetResultsReturnsInitialList)
{
    std::list<Driver> const drivers;
    Race race("whocares", drivers);

    EXPECT_TRUE(race.getResults().empty());
}
