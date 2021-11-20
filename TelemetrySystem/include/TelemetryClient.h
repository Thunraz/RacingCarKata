#pragma once

#include "TelemetryClientInterface.hpp"
#include "TelemetryConnectionInterface.hpp"
#include <memory>
#include <random>
#include <string>

class TelemetryClient : public TelemetryClientInterface {
    std::shared_ptr<TelemetryConnectionInterface> m_telemetryConnection;
    bool m_onlineStatus;
    std::string m_diagnosticMessageResult;

public:
    static std::string const DIAGNOSTIC_MESSAGE;

    TelemetryClient(std::shared_ptr<TelemetryConnectionInterface> telemetryConnection = nullptr);

    bool getOnlineStatus() override;

    void connect(std::string const& telemetryServerConnectionString) override;

    void disconnect() override;

    void send(std::string const& message) override;

    std::string receive() override;
};
