#include <gmock/gmock.h>
#include "TelemetryClient.h"

namespace {
    TEST(TelemetryClient, InitialStatusIsOffline) {
        TelemetryClient tc;

        ASSERT_FALSE(tc.getOnlineStatus());
    }
}

