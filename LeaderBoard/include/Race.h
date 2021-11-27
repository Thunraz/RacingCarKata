#pragma once

#include "Driver.h"

#include <string>
#include <list>
#include <unordered_map>
#include <memory>


class Race
{
    static const int POINTS[];

    std::string m_name;
    std::list<std::shared_ptr<Driver>> m_results;

public: 
    Race(std::string const& name, std::list<std::shared_ptr<Driver>> const& drivers);

    int position(std::shared_ptr<Driver> const& driver);

    int getPoints(std::shared_ptr<Driver> driver);

    std::list<std::shared_ptr<Driver>> getResults();

    std::string getDriverName(std::shared_ptr<Driver> driver);
    
    std::string toString();
};
