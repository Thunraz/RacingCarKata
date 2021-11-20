#ifndef RACING_CAR_GMOCK_TELEMETRYCONNECTIONINTERFACE_HPP
#define RACING_CAR_GMOCK_TELEMETRYCONNECTIONINTERFACE_HPP

#include <string>

class TelemetryConnectionInterface {
public:
    virtual ~TelemetryConnectionInterface() = default;

    virtual bool connect() = 0;

    virtual std::string receive() = 0;
};

#endif // RACING_CAR_GMOCK_TELEMETRYCONNECTIONINTERFACE_HPP
