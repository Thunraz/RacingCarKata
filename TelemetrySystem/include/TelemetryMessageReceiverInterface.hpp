#ifndef RACING_CAR_GMOCK_TELEMETRYMESSAGERECEIVERINTERFACE_HPP
#define RACING_CAR_GMOCK_TELEMETRYMESSAGERECEIVERINTERFACE_HPP

#include <string>

class TelemetryMessageReceiverInterface {
public:
    virtual ~TelemetryMessageReceiverInterface() = default;

    virtual std::string receive() = 0;
};

#endif // RACING_CAR_GMOCK_TELEMETRYMESSAGERECEIVERINTERFACE_HPP
