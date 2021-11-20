#include "TelemetryMessageReceiverRandom.hpp"

std::string TelemetryMessageReceiverRandom::receive()
{
    std::string message = "";
    int messageLength = std::uniform_int_distribution<>(0, 49)(m_generator) + 60;
    for (int i = messageLength; i >= 0; --i) {
        message += (char)std::uniform_int_distribution<>(0, 39)(m_generator) + 86;
    }
    return message;
}
TelemetryMessageReceiverRandom::TelemetryMessageReceiverRandom()
    : m_seed({ 42 })
    , m_generator(m_seed)
{
}
