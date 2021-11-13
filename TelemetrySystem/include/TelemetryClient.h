#pragma once

#include "TelemetryClientInterface.hpp"
#include <random>
#include <string>

class TelemetryClient : public TelemetryClientInterface
{
    bool m_onlineStatus;
    std::string m_diagnosticMessageResult;
    std::seed_seq m_seed;
    std::mt19937 m_generator;

public:
    static std::string const DIAGNOSTIC_MESSAGE;
    
    TelemetryClient();

    bool getOnlineStatus() override;

    void connect(std::string const& telemetryServerConnectionString) override;

    void disconnect() override;

    void send(std::string const& message) override;

    std::string receive() override;
};
