#include <string>
#include <vector>
#include "station.h"

// Enum to distinguish train types
enum class TrainType {
    PASSENGER,
    FREIGHT
};

// A structure representing one stop on the route
struct RouteStop {
    Station station;
    std::string arrivalTime;
    std::string departureTime;
};

class Train {
private:
    int trainNumber;
    std::string trainName;
    TrainType type;
    std::vector<RouteStop> route; // List of stops

public:
    // Constructor
    Train(int number, const std::string& name, TrainType t);

    // Getters
    int getTrainNumber() const;
    std::string getTrainName() const;
    TrainType getTrainType() const;

    // Add a station to the train route
    void addStationToRoute(const Station& station,
                           const std::string& arrival,
                           const std::string& departure);

    // Retrieve the entire route
    const std::vector<RouteStop>& getRoute() const;
};
