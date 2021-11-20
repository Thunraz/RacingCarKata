#include "TelemetryConnectionRandom.hpp"

TelemetryConnectionRandom::TelemetryConnectionRandom()
    : m_seed({ 42 })
    , m_generator(m_seed)
{
}

bool TelemetryConnectionRandom::connect()
{
    // simulate the operation on a real modem
    return std::uniform_int_distribution<>(0, 9)(m_generator) <= 8;
}

std::string TelemetryConnectionRandom::receive()
{
    // simulate a received message (just for illustration - not needed for this exercise)
    std::string message = "";
    int messageLength = std::uniform_int_distribution<>(0, 49)(m_generator) + 60;
    for (int i = messageLength; i >= 0; --i) {
        message += (char)std::uniform_int_distribution<>(0, 39)(m_generator) + 86;
    }
    return message;
}
