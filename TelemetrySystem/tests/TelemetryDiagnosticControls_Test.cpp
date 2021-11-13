#include "TelemetryDiagnosticControls.h"
#include <gmock/gmock.h>

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
