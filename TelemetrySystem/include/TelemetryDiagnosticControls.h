#pragma once

#include "TelemetryClient.h"
#include "TelemetryClientInterface.hpp"
#include <memory>
#include <string>

class TelemetryDiagnosticControls {
    std::string m_diagnosticChannelConnectionString;
    TelemetryClient m_telemetryClient;

    std::shared_ptr<TelemetryClientInterface> m_telemetryClientNew;
    std::string m_diagnosticInfo;

public:
    TelemetryDiagnosticControls();
    TelemetryDiagnosticControls(std::shared_ptr<TelemetryClientInterface> telemetryClient);

    std::string getDiagnosticInfo();

    void setDiagnosticInfo(std::string const& diagnosticInfo);

    void checkTransmission();
};
