#include "Driver.h"
#include <gtest/gtest.h>

TEST(DriverTest, GetNameReturnsCorrectValue)
{
    auto const expectedResult = "name";
    Driver const driver { expectedResult, "Germany" };

    EXPECT_EQ(driver.getName(), expectedResult);
}

TEST(DriverTest, GetCountryReturnsCorrectValue)
{
    auto const expectedResult = "Germany";
    Driver const driver { "name", expectedResult };

    EXPECT_EQ(driver.getCountry(), expectedResult);
}

TEST(DriverCompareTest, SelfComparison)
{
    Driver const driver { "name", "UK" };
    ASSERT_EQ(driver, driver);
}

TEST(DriverCompareTest, ValueComparison)
{
    Driver const driver1 { "name", "UK" };
    Driver const driver2 { "name", "UK" };
    ASSERT_EQ(driver1, driver2);
}

TEST(DriverCompareTest, ValueComparisonDifferentDrivers)
{
    Driver const driver1 { "name", "UK" };
    Driver const driver2 { "not_same", "___DefinitelyNotSame___" };
    ASSERT_FALSE(driver1 == driver2);
}

TEST(DriverHashTest, HashValuesForDifferentdriversAreDifferent)
{
    std::hash<Driver> hasher;
     Driver driver1 { "name", "UK" };
     Driver driver2 { "not_same", "___DefinitelyNotSame___" };

     ASSERT_NE(hasher(driver1), hasher(driver2));
}

TEST(DriverHashTest, HashValuesForDifferentDriversWithSameDataAreEqual)
{
    std::hash<Driver> hasher;
    Driver driver1 { "name", "Japan" };
    Driver driver2 { "name", "Japan" };

    ASSERT_EQ(hasher(driver1), hasher(driver2));
}

TEST(DriverTest, DisplayName)
{
    auto const expectedDisplayName = "display name";
    Driver const driver { expectedDisplayName, "country" };

    EXPECT_EQ(driver.getDisplayName(), expectedDisplayName);
}