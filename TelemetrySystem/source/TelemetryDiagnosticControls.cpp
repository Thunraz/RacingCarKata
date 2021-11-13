
#include "../include/TelemetryDiagnosticControls.h"
#include "TelemetryClientInterface.hpp"
#include <stdexcept>
#include <utility>

TelemetryDiagnosticControls::TelemetryDiagnosticControls(
    std::shared_ptr<TelemetryClientInterface> telemetryClient)
    : m_diagnosticChannelConnectionString("*111#")
    , m_telemetryClient()
    , m_telemetryClientNew { telemetryClient }
    , m_diagnosticInfo()
{
}

TelemetryDiagnosticControls::TelemetryDiagnosticControls()
    : m_diagnosticChannelConnectionString("*111#")
    , m_telemetryClient()
    , m_diagnosticInfo()
{
}

std::string TelemetryDiagnosticControls::getDiagnosticInfo() { return m_diagnosticInfo; }

void TelemetryDiagnosticControls::setDiagnosticInfo(std::string const& diagnosticInfo)
{
    m_diagnosticInfo = diagnosticInfo;
}

void TelemetryDiagnosticControls::checkTransmission()
{
    m_diagnosticInfo = "";

    m_telemetryClientNew->disconnect();

    int retryLeft = 3;
    while (m_telemetryClientNew->getOnlineStatus() == false && retryLeft > 0) {
        m_telemetryClientNew->connect(m_diagnosticChannelConnectionString);
        retryLeft -= 1;
    }

    if (m_telemetryClientNew->getOnlineStatus() == false) {
        throw std::invalid_argument("Unable to connect");
    }

    m_telemetryClientNew->send(TelemetryClient::DIAGNOSTIC_MESSAGE);
    m_diagnosticInfo = m_telemetryClientNew->receive();
}
