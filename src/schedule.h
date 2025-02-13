#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "train.h"

class Schedule {
private:
    std::vector<Train> trains;

public:
    // Add a new train to the schedule
    void addTrain(const Train& train);

    // Remove a train by its train number
    bool removeTrain(int trainNumber);

    // Query trains by source station, destination station, and departure time
    std::vector<Train> queryTrains(const std::string& sourceStation,
                                   const std::string& destStation,
                                   const std::string& departureTime) const;

    // Display the schedule of all trains
    void displaySchedule() const;
};
