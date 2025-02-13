#include <iostream>
#include "schedule.h"

int main() {
    Schedule schedule;

    // Create a passenger train
    Train passengerTrain(101, "Morning Express", TrainType::PASSENGER);
    passengerTrain.addStationToRoute(Station("StationA", "LocationA"), "08:00", "08:15");
    passengerTrain.addStationToRoute(Station("StationB", "LocationB"), "09:30", "09:45");
    passengerTrain.addStationToRoute(Station("StationC", "LocationC"), "10:30", "10:45");
    schedule.addTrain(passengerTrain);

    // Create a freight train
    Train freightTrain(202, "Cargo Hauler", TrainType::FREIGHT);
    freightTrain.addStationToRoute(Station("StationA", "LocationA"), "06:00", "06:15");
    freightTrain.addStationToRoute(Station("StationD", "LocationD"), "07:00", "07:15");
    schedule.addTrain(freightTrain);

    // Display all trains in the schedule
    std::cout << "Full Schedule:\n";
    schedule.displaySchedule();

    // Query trains (e.g., from StationA to StationC departing at 08:00)
    std::vector<Train> results = schedule.queryTrains("StationA", "StationC", "08:00");
    std::cout << "Query Results: " << results.size() << " train(s) found.\n";
    for (const auto& t : results) {
        std::cout << "  Train " << t.getTrainNumber() << ": " << t.getTrainName() << "\n";
    }

    // Remove a train from the schedule
    bool removed = schedule.removeTrain(101);
    std::cout << (removed ? "Train 101 removed.\n" : "Train 101 not found.\n");

    // Display schedule again
    std::cout << "\nUpdated Schedule:\n";
    schedule.displaySchedule();

    return 0;
}
