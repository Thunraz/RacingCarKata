#ifndef RACING_CAR_GMOCK_TELEMETRYCLIENTINTERFACE_HPP
#define RACING_CAR_GMOCK_TELEMETRYCLIENTINTERFACE_HPP

#include <random>
#include <string>
class TelemetryClientInterface {
public:
    virtual bool getOnlineStatus() = 0;
    virtual void connect(std::string const& telemetryServerConnectionString) = 0;
    virtual void disconnect() = 0;
    virtual void send(std::string const& message) = 0;
    virtual std::string receive() = 0;
};

#endif // RACING_CAR_GMOCK_TELEMETRYCLIENTINTERFACE_HPP
