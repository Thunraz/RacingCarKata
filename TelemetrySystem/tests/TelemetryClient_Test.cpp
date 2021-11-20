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
    MOCK_METHOD(std::string, send, (), (override));
};

class BasicTelemetryClientTest : public ::testing::Test {
public:
    TelemetryClient tc;
};

TEST_F(BasicTelemetryClientTest, InitialStatusIsOffline) { ASSERT_FALSE(tc.getOnlineStatus()); }

TEST_F(BasicTelemetryClientTest, ConnectWithEmptyConnectStringRaisesException)
{
    EXPECT_THROW(tc.connect(""), std::invalid_argument);
}

TEST_F(BasicTelemetryClientTest, OnlineStatusAfterDisconnect)
{
    tc.connect("abcd");
    tc.disconnect();

    ASSERT_FALSE(tc.getOnlineStatus());
}

TEST_F(BasicTelemetryClientTest, SendEmptyMessageWillRaiseException)
{
    EXPECT_THROW(tc.send(""), std::invalid_argument);
}

TEST_F(BasicTelemetryClientTest, SendMessageWithContentWillNotRaiseException)
{
    EXPECT_NO_THROW(tc.send("abcd"));
}

class MockedTelemetryClientTest : public ::testing::Test {
public:
    std::unique_ptr<TelemetryClient> tc;
    std::shared_ptr<TelemetryConnectionMock> connectionMock;
    void SetUp() override
    {
        connectionMock = std::make_shared<TelemetryConnectionMock>();
        tc = std::make_unique<TelemetryClient>(connectionMock);
    }
};

TEST_F(MockedTelemetryClientTest, OnlineStatusAfterConnect)
{
    EXPECT_CALL(*connectionMock, connect).WillOnce(::testing::Return(true));
    tc->connect("abcd");

    ASSERT_TRUE(tc->getOnlineStatus());
}

TEST(TelemetryClient, OnlineStatusAfterConnectFails)
{
    auto connectionMock = std::make_shared<TelemetryConnectionMock>();
    TelemetryClient tc(connectionMock);

    EXPECT_CALL(*connectionMock, connect).WillOnce(::testing::Return(false));
    tc.connect("abcd");

    ASSERT_FALSE(tc.getOnlineStatus());
}

TEST(TelemetryClient, ReceiveAfterSend)
{
    auto connectionMock = std::make_shared<TelemetryConnectionMock>();
    auto const expectedSendDiagnosticMessage = "ABCD1111";
    EXPECT_CALL(*connectionMock, send).WillOnce(::testing::Return(expectedSendDiagnosticMessage));
    TelemetryClient tc { connectionMock };
    tc.send(TelemetryClient::DIAGNOSTIC_MESSAGE);
    auto const received_message = tc.receive();

    EXPECT_EQ(received_message, expectedSendDiagnosticMessage);
}

TEST(TelemetryClient, ReceiveWithoutSend)
{
    auto connectionMock = std::make_shared<TelemetryConnectionMock>();

    auto const expectedString = "ABCD1234";
    EXPECT_CALL(*connectionMock, receive).WillOnce(::testing::Return(expectedString));

    TelemetryClient tc { connectionMock };
    auto const received_message = tc.receive();

    ASSERT_EQ(received_message, expectedString);
}

} // namespace
