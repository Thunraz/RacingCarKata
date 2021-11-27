#include "LeaderBoard.h"
#include <gmock/gmock.h>

namespace {
TEST(LeaderBoard, EmptyListOfRacesReturnsEmptyResults)
{
    Leaderboard board { {} };

    ASSERT_TRUE(board.driverResults().empty());
}

TEST(LeaderBoard, EmptyListOfRacesReturnsEmptyRankings)
{
    Leaderboard board { {} };

    ASSERT_TRUE(board.driverRankings().empty());
}

TEST(LeaderBoard, OneRaceReturnsCorrectRankings)
{
    auto driver1 = std::make_shared<Driver>("name", "country");
    Race race("whocares", { driver1 });
    Leaderboard board { { race } };

    auto rankings = board.driverRankings();
    auto it = rankings.begin();

    EXPECT_EQ(*it, "name");
}

TEST(LeaderBoard, SingleDriverAppearsInResults)
{
    auto driver1 = std::make_shared<Driver>("name", "country");
    Race race("whocares", { driver1 });
    Leaderboard board { { race } };

    ASSERT_EQ(board.driverResults().count("name"), 1);
}

TEST(LeaderBoard, SingleDriverHasCorrectNumberOfPoints)
{
    auto driver1 = std::make_shared<Driver>("name", "country");
    Race race("whocares", { driver1 });
    Leaderboard board { { race } };

    ASSERT_EQ(board.driverResults().at("name"), 25);
}

TEST(LeaderBoardBossMonster, BossMonsterTest)
{
    auto driver1 = std::make_shared<Driver>("name", "country");
    Race race1("whocares", { driver1 });

    auto driver2 = std::make_shared<Driver>("name2", "country2");
    Race race2("whocares2", { driver1, driver2 });

    Leaderboard board { { race1, race2 } };

    std::list<std::string> expectedRanking { "name", "name2" };

    EXPECT_EQ(board.driverRankings(), expectedRanking);
}

} // namespace
