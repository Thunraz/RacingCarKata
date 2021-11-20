
#include "../include/TelemetryClient.h"

#include "TelemetryConnectionRandom.hpp"
#include <stdexcept>

std::string const TelemetryClient::DIAGNOSTIC_MESSAGE = "AT#UD";

TelemetryClient::TelemetryClient(std::shared_ptr<TelemetryConnectionInterface> telemetryConnection)
    : m_telemetryConnection(telemetryConnection)
    , m_onlineStatus(false)
    , m_diagnosticMessageResult()
{
    if (telemetryConnection == nullptr) {
        m_telemetryConnection = std::make_shared<TelemetryConnectionRandom>();
    }
}

bool TelemetryClient::getOnlineStatus() { return m_onlineStatus; }

void TelemetryClient::connect(std::string const& telemetryServerConnectionString)
{
    if (telemetryServerConnectionString.empty()) {
        throw std::invalid_argument("Telemetry server connection string is empty");
    }

    m_onlineStatus = m_telemetryConnection->connect();
}

void TelemetryClient::disconnect() { m_onlineStatus = false; }

void TelemetryClient::send(std::string const& message)
{
    if (message.empty()) {
        throw std::invalid_argument("Message to be sent is empty");
    }

    if (message == DIAGNOSTIC_MESSAGE) {
        // simulate a status report
        m_diagnosticMessageResult = m_telemetryConnection->send();
        return;
    }

    // here should go the real Send operation (not needed for this exercise)
}

std::string TelemetryClient::receive()
{
    std::string message;

    if (m_diagnosticMessageResult.empty()) {

        message = m_telemetryConnection->receive();
    } else {
        message = m_diagnosticMessageResult;
        m_diagnosticMessageResult = "";
    }

    return message;
}
