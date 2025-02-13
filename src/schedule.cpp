#include "schedule.h"

void Schedule::addTrain(const Train& train) {
    trains.push_back(train);
}

bool Schedule::removeTrain(int trainNumber) {
    auto it = std::remove_if(trains.begin(), trains.end(),
                             [trainNumber](const Train& t) {
                                 return t.getTrainNumber() == trainNumber;
                             });
    if (it != trains.end()) {
        trains.erase(it, trains.end());
        return true;
    }
    return false;
}

std::vector<Train> Schedule::queryTrains(const std::string& sourceStation,
                                         const std::string& destStation,
                                         const std::string& departureTime) const
{
    std::vector<Train> result;

    for (const auto& train : trains) {
        const auto& route = train.getRoute();
        if (route.size() < 2) {
            // Must have at least a source and a destination
            continue;
        }

        const auto& firstStop = route.front();
        const auto& lastStop  = route.back();

        bool sourceMatches = (firstStop.station.getName() == sourceStation &&
                              firstStop.departureTime == departureTime);
        bool destinationMatches = (lastStop.station.getName() == destStation);

        if (sourceMatches && destinationMatches) {
            result.push_back(train);
        }
    }
    return result;
}

void Schedule::displaySchedule() const {
    for (const auto& train : trains) {
        std::cout << "Train Number: " << train.getTrainNumber()
                  << ", Name: " << train.getTrainName()
                  << ", Type: "
                  << ((train.getTrainType() == TrainType::PASSENGER)
                      ? "Passenger"
                      : "Freight")
                  << std::endl;

        for (const auto& stop : train.getRoute()) {
            std::cout << "  Station: " << stop.station.getName()
                      << " (" << stop.station.getLocation() << ")"
                      << ", Arrival: " << stop.arrivalTime
                      << ", Departure: " << stop.departureTime
                      << std::endl;
        }
        std::cout << std::endl;
    }
}
