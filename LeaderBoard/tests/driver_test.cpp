#include <gtest/gtest.h>
#include "Driver.h"

TEST(DriverTest, GetNameReturnsCorrectValue)
{
    auto expectedResult = "name";
    Driver driver { expectedResult, "Germany" };

    EXPECT_EQ(driver.getName(), expectedResult);
}