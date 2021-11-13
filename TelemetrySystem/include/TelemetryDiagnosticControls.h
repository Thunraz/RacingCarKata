#pragma once

#include "TelemetryClient.h"
#include "TelemetryClientInterface.hpp"
#include <memory>
#include <string>

class TelemetryDiagnosticControls {
    std::string m_diagnosticChannelConnectionString;
    TelemetryClient m_telemetryClient;

    std::unique_ptr<TelemetryClientInterface> m_telemetryClientNew;
    std::string m_diagnosticInfo;

public:
    TelemetryDiagnosticControls();
    TelemetryDiagnosticControls(std::unique_ptr<TelemetryClientInterface> telemtryClient);

    std::string getDiagnosticInfo();

    void setDiagnosticInfo(std::string const& diagnosticInfo);

    void checkTransmission();
};
