#include "TelemetryClient.h"
#include "TelemetryClientInterface.hpp"
#include "TelemetryConnectionInterface.hpp"
#include <gmock/gmock.h>
#include <memory>

namespace {
class TelemetryConnectionMock : public TelemetryConnectionInterface {
public:
    MOCK_METHOD(std::string, receive, (), (override));
    MOCK_METHOD(bool, connect, (), (override));
};

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

TEST(TelemetryClient, OnlineStatusAfterConnect)
{
    auto connectionMock = std::make_shared<TelemetryConnectionMock>();
    TelemetryClient tc(connectionMock);

    EXPECT_CALL(*connectionMock, connect).WillOnce(::testing::Return(true));
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



TEST(TelemetryClient, ReceiveWithoutSend)
{
    auto connectionMock = std::make_shared<TelemetryConnectionMock>();

    auto const expectedString = "ABCD1234";
    EXPECT_CALL(*connectionMock, receive).WillOnce(::testing::Return(expectedString));

    TelemetryClient tc {connectionMock };
    auto const received_message = tc.receive();

    ASSERT_EQ(received_message, expectedString);
}

} // namespace
