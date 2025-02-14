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

        // If there's no route data at all, skip this train
        if (route.empty()) {
            continue;
        }

        bool match = true;

        // 1) Check source station (if provided)
        if (!sourceStation.empty()) {
            // Compare with the first stop’s station name
            const auto& firstStop = route.front();
            if (firstStop.station.getName() != sourceStation) {
                match = false;
            }
        }

        // 2) Check departure time (if provided)
        if (match && !departureTime.empty()) {
            // Compare with the first stop’s departure time
            const auto& firstStop = route.front();
            if (firstStop.arrivalTime != departureTime) {
                match = false;
            }
        }

        // 3) Check destination station (if provided)
        if (match && !destStation.empty()) {
            // Compare with the last stop’s station name
            const auto& lastStop = route.back();
            if (lastStop.station.getName() != destStation) {
            match = false;
            }
        }

        // If all non-empty filters matched, add to result
        if (match) {
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
