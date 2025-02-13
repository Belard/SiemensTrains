#include "train.h"

// Constructor
Train::Train(int number, const std::string& name, TrainType t)
    : trainNumber(number), trainName(name), type(t) {}

// Getter for train number
int Train::getTrainNumber() const {
    return trainNumber;
}

// Getter for train name
std::string Train::getTrainName() const {
    return trainName;
}

// Getter for train type
TrainType Train::getTrainType() const {
    return type;
}

// Add station stop (arrival, departure)
void Train::addStationToRoute(const Station& station,
                              const std::string& arrival,
                              const std::string& departure) {
    RouteStop stop{ station, arrival, departure };
    route.push_back(stop);
}

// Return the entire route
const std::vector<RouteStop>& Train::getRoute() const {
    return route;
}
