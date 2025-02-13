#include "station.h"

// Constructor
Station::Station(const std::string& stationName, const std::string& stationLocation)
    : name(stationName), location(stationLocation) {}

// Getter for station name
std::string Station::getName() const {
    return name;
}

// Getter for station location
std::string Station::getLocation() const {
    return location;
}
