#include "TelemetryDiagnosticControls.h"
#include <gmock/gmock.h>

class TelemetryClientMock : public TelemetryClientInterface {
public:
    MOCK_METHOD(bool, getOnlineStatus, (), (override));
    MOCK_METHOD(void, connect, (std::string const& telemetryServerConnectionString), (override));
    MOCK_METHOD(void, disconnect, (), (override));
    MOCK_METHOD(void, send, (std::string const& message), (override));
    MOCK_METHOD(std::string, receive, (), (override));
};

namespace {
TEST(TelemetrySystem, GetDiagnosticInfoReturnsEmptyString)
{
    auto client_mock = std::make_shared<TelemetryClientMock>();
    TelemetryDiagnosticControls controls { std::move(client_mock) };

    EXPECT_EQ(controls.getDiagnosticInfo(), "");
}

TEST(TelemetrySystem, GetDiagnosticInfoReturnsSetString)
{
    auto client_mock = std::make_shared<TelemetryClientMock>();
    TelemetryDiagnosticControls controls { std::move(client_mock) };

    const auto diagnosticInfo = "Hello, World!";
    controls.setDiagnosticInfo(diagnosticInfo);

    EXPECT_EQ(controls.getDiagnosticInfo(), diagnosticInfo);
}

TEST(TelemetrySystem, CheckTransmissionCallsDisconnect)
{
    auto client_mock = std::make_shared<::testing::NiceMock<TelemetryClientMock>>();
    EXPECT_CALL(*client_mock, disconnect).Times(1);
    EXPECT_CALL(*client_mock, getOnlineStatus).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*client_mock, receive).WillOnce(::testing::Return("not empty"));
    TelemetryDiagnosticControls controls { client_mock };

    controls.checkTransmission();

    const auto diagnosticInfo = controls.getDiagnosticInfo();

    EXPECT_EQ(diagnosticInfo, "not empty");
}

} // namespace
