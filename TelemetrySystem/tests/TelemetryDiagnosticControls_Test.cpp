#include "TelemetryDiagnosticControls.h"
#include <gmock/gmock.h>

class TelemetryClientMock : public TelemetryClientInterface
{
public:
    TelemetryClientMock();

    MOCK_METHOD(bool, getOnlineStatus, (), (override));
    MOCK_METHOD(void, connect, (std::string const& telemetryServerConnectionString), (override));
    MOCK_METHOD(void, disconnect, (), (override));
    MOCK_METHOD(void, send, (std::string const& message), (override));
    MOCK_METHOD(std::string, receive, (), (override));
};

namespace {
TEST(TelemetrySystem, GetDiagnosticInfoReturnsEmptyString)
{
    TelemetryDiagnosticControls controls;

    EXPECT_EQ(controls.getDiagnosticInfo(), "");
}

TEST(TelemetrySystem, GetDiagnosticInfoReturnsSetString)
{
    TelemetryDiagnosticControls controls;

    const auto diagnosticInfo = "Hello, World!";
    controls.setDiagnosticInfo(diagnosticInfo);

    EXPECT_EQ(controls.getDiagnosticInfo(), diagnosticInfo);
}

TEST(TelemetrySystem, CheckTransmission)
{
    TelemetryDiagnosticControls controls;
    controls.checkTransmission();

    const auto diagnosticInfo = controls.getDiagnosticInfo();

    EXPECT_NE(diagnosticInfo, "");
}
} // namespace
