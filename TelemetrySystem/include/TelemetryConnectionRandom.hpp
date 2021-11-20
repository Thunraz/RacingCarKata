#include "TelemetryConnectionInterface.hpp"
#include <random>
#include <string>

#ifndef RACING_CAR_GMOCK_TELEMETRYMESSAGERECEIVERRANDOM_HPP
#define RACING_CAR_GMOCK_TELEMETRYMESSAGERECEIVERRANDOM_HPP

class TelemetryConnectionRandom : public TelemetryConnectionInterface {
public:
    TelemetryConnectionRandom();

    bool connect() override;

    std::string receive() override;

    std::string send() override;

private:
    std::seed_seq m_seed;
    std::mt19937 m_generator;
};

#endif // RACING_CAR_GMOCK_TELEMETRYMESSAGERECEIVERRANDOM_HPP
