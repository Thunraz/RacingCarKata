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

std::string TelemetryConnectionRandom::send() {
    return R"(LAST TX rate................ 100 MBPS
HIGHEST TX rate............. 100 MBPS
LAST RX rate................ 100 MBPS
HIGHEST RX rate............. 100 MBPS
BIT RATE.................... 100000000
WORD LEN.................... 16
WORD/FRAME.................. 511
BITS/FRAME.................. 8192
MODULATION TYPE............. PCM/FM
TX Digital Los.............. 0.75
RX Digital Los.............. 0.10
BEP Test.................... -5
Local Rtrn Count............ 00
Remote Rtrn Count........... 00)";
}
