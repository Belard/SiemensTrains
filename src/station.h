#include <string>

class Station {
private:
    std::string name;
    std::string location;

public:
    // Constructor
    Station(const std::string& stationName, const std::string& stationLocation);

    // Getters
    std::string getName() const;
    std::string getLocation() const;
};

