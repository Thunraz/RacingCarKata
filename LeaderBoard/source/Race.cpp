
#include "../include/Race.h"
#include "../include/SelfDrivingCar.h"

#include <typeinfo>

const int Race::POINTS[] = { 25, 18, 15 };

Race::Race(std::string const& name, std::list<std::shared_ptr<Driver>> const& drivers)
    : m_name(name)
    , m_results(drivers)
{
}

int Race::position(std::shared_ptr<Driver> const& driver)
{
    int count = 0;
    for (auto const d : m_results) {
        if (d == driver) {
            break;
        }
        ++count;
    }
    return count;
}

int Race::getPoints(std::shared_ptr<Driver> driver) { return POINTS[position(driver)]; }

std::list<std::shared_ptr<Driver>> Race::getResults() { return m_results; }

std::string Race::getDriverName(std::shared_ptr<Driver> driver) { return driver->getDisplayName(); }

std::string Race::toString() { return m_name; }
