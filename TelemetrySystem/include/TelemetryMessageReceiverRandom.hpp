#include "TelemetryMessageReceiverInterface.hpp"
#include <random>
#include <string>

#ifndef RACING_CAR_GMOCK_TELEMETRYMESSAGERECEIVERRANDOM_HPP
#define RACING_CAR_GMOCK_TELEMETRYMESSAGERECEIVERRANDOM_HPP

class TelemetryMessageReceiverRandom : public TelemetryMessageReceiverInterface {
public:
    std::string receive() override;

    TelemetryMessageReceiverRandom();

private:
    std::seed_seq m_seed;
    std::mt19937 m_generator;
};

#endif // RACING_CAR_GMOCK_TELEMETRYMESSAGERECEIVERRANDOM_HPP
