#include <gmock/gmock.h>
#include "LeaderBoard.h"

namespace {
  TEST(LeaderBoard, EmptyListOfRacesReturnsEmptyResults) {
      Leaderboard board{ {} };

      ASSERT_TRUE(board.driverResults().empty());
  }

  TEST(LeaderBoard, EmptyListOfRacesReturnsEmptyRankings) {
        Leaderboard board{ {} };

        ASSERT_TRUE(board.driverRankings().empty());
    }

    TEST(LeaderBoard, SingleDriverAppearsInResults) {
        auto driver1 = std::make_shared<Driver>("name", "country");
        Race race("whocares", { driver1 });
        Leaderboard board{ {race} };

        ASSERT_EQ(board.driverResults().count("name"), 1);
    }

    TEST(LeaderBoard, SingleDriverHasCorrectNumberOfPoints) {
        auto driver1 = std::make_shared<Driver>("name", "country");
        Race race("whocares", { driver1 });
        Leaderboard board{ {race} };

        ASSERT_EQ(board.driverResults().at("name"), 25);
    }

}

