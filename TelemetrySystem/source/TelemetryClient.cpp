
#include "../include/TelemetryClient.h"

#include "TelemetryConnectionRandom.hpp"
#include <stdexcept>

std::string const TelemetryClient::DIAGNOSTIC_MESSAGE = "AT#UD";

TelemetryClient::TelemetryClient(std::shared_ptr<TelemetryConnectionInterface> telemetryConnection)
    : m_telemetryConnection(telemetryConnection)
    , m_onlineStatus(false)
    , m_diagnosticMessageResult()
    , m_seed({ 42 })
    , m_generator(m_seed)
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
        m_diagnosticMessageResult = std::string() + "LAST TX rate................ 100 MBPS\r\n"
            + "HIGHEST TX rate............. 100 MBPS\r\n"
            + "LAST RX rate................ 100 MBPS\r\n"
            + "HIGHEST RX rate............. 100 MBPS\r\n"
            + "BIT RATE.................... 100000000\r\n" + "WORD LEN.................... 16\r\n"
            + "WORD/FRAME.................. 511\r\n" + "BITS/FRAME.................. 8192\r\n"
            + "MODULATION TYPE............. PCM/FM\r\n" + "TX Digital Los.............. 0.75\r\n"
            + "RX Digital Los.............. 0.10\r\n" + "BEP Test.................... -5\r\n"
            + "Local Rtrn Count............ 00\r\n" + "Remote Rtrn Count........... 00";

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
