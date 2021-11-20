#include "TelemetryClient.h"
#include "TelemetryClientInterface.hpp"
#include "TelemetryMessageReceiverInterface.hpp"
#include <gmock/gmock.h>
#include <memory>

namespace {
TEST(TelemetryClient, InitialStatusIsOffline)
{
    TelemetryClient tc;

    ASSERT_FALSE(tc.getOnlineStatus());
}

TEST(TelemetryClient, ConnectWithEmptyConnectStringRaisesException)
{
    TelemetryClient tc;

    EXPECT_THROW(tc.connect(""), std::invalid_argument);
}

// TODO Will fail randomly
TEST(TelemetryClient, OnlineStatusAfterConnect)
{
    TelemetryClient tc;
    tc.connect("abcd");

    ASSERT_TRUE(tc.getOnlineStatus());
}

TEST(TelemetryClient, OnlineStatusAfterDisconnect)
{
    TelemetryClient tc;
    tc.connect("abcd");
    tc.disconnect();

    ASSERT_FALSE(tc.getOnlineStatus());
}

TEST(TelemetryClient, SendEmptyMessageWillRaiseException)
{
    TelemetryClient tc;
    EXPECT_THROW(tc.send(""), std::invalid_argument);
}

TEST(TelemetryClient, SendMessageWithContentWillNotRaiseException)
{
    TelemetryClient tc;
    EXPECT_NO_THROW(tc.send("abcd"));
}

class TelemetryMessageReceiverMock : public TelemetryMessageReceiverInterface {
public:
    MOCK_METHOD(std::string, receive, (), (override));
};

TEST(TelemetryClient, ReceiveWithoutSend)
{
    auto messageReceiver = std::make_shared<::testing::NiceMock<TelemetryMessageReceiverMock>>();
    TelemetryClient tc { messageReceiver };
    auto const received_message = tc.receive();

    ASSERT_EQ(received_message, "");
}

} // namespace
