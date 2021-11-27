
#include "../include/Race.h"
#include "../include/SelfDrivingCar.h"
#include <map>
#include <stdexcept>
#include <typeinfo>

const int Race::POINTS[] = { 25, 18, 15 };

namespace {
template <template <class, class, class...> class C, typename K, typename V, typename... Args>
V GetWithDef(const C<K, V, Args...>& m, K const& key, const V& defval)
{
    typename C<K, V, Args...>::const_iterator it = m.find(key);
    if (it == m.end())
        return defval;
    return it->second;
}
} // namespace

Race::Race(std::string const& name, std::list<std::shared_ptr<Driver>> const& drivers)
    : m_name(name)
    , m_results(drivers)
{
}

int Race::position(std::shared_ptr<Driver> const& driver)
{
    if (std::find(m_results.begin(), m_results.end(), driver) == m_results.end()) {
        throw std::invalid_argument { "driver did not participate in race" };
    }
    int count = 0;
    for (auto const d : m_results) {
        if (d == driver) {
            break;
        }
        ++count;
    }
    return count;
}

int Race::getPoints(std::shared_ptr<Driver> driver)
{
    auto const driverPosition = position(driver);
    std::map<int, int> lookup { { 0, 25 }, { 1, 18 }, { 2, 15 } };
    return GetWithDef(lookup, driverPosition, 0);
}

std::list<std::shared_ptr<Driver>> Race::getResults() { return m_results; }

std::string Race::getDriverName(std::shared_ptr<Driver> driver) { return driver->getDisplayName(); }

std::string Race::toString() { return m_name; }
