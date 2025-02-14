# Train Schedule Management System

This project implements a simple train schedule management system in C++. It allows users to:

- Add trains (passenger or freight) to a schedule  
- Remove trains by train number  
- Query trains based on station information and departure times  
- Display all trains currently in the schedule, including their routes  

---

## Table of Contents

1. [How to Compile and Run](#how-to-compile-and-run)  
   - [Using CMake (Recommended)](#1-using-cmake-recommended)  
   - [Using-g-directly-without-cmake](#2-using-g-directly-without-cmake)  
2. [Design Choices](#design-choices)  
3. [Assumptions and Limitations](#assumptions-and-limitations)  


---

## How to Compile and Run

1. **Build code**  

    - `./build.sh`

2. **Run code**  

    - `./build/src/Debug/SiemensTrains.exe`

---

## Design Choices

1. **Class Separation**  
   - **Station**: Represents a train station with a name and location.  
   - **Train**: Contains a train number, train name, train type (passenger or freight), and a list of route stops. Each route stop includes a `Station` plus arrival/departure times.  
   - **Schedule**: Manages a collection of `Train` objects. Provides methods to add, remove, query, and display schedules.

2. **Enum Class for TrainType**  
   - `enum class TrainType { PASSENGER, FREIGHT }` clearly distinguishes between passenger and freight trains.

3. **Data Structures**  
   - Uses `std::vector` to store the list of trains in `Schedule`, and also uses `std::vector` within each `Train` to store its route stops.

4. **Query Mechanism**  
   - The `queryTrains` function can filter trains by source station, destination station, and departure time. Each filter can be applied independently if a parameter is non-empty.

---

## Assumptions and Limitations

1. **Time Handling**  
   - Arrival and departure times are stored as simple strings (e.g., `"08:00"`). There is no validation or parsing to ensure correct time formats or chronological order.

2. **Basic Query Logic**  
   - By default, the query checks only the first and last stops in a route for matching source/destination stations. Intermediate station matching is not included (but can be added).

3. **No Duplicate Checks**  
   - The implementation does not prevent adding two trains with the same train number.

4. **Minimal Error Handling**  
   - The code does not extensively validate inputs (e.g., station names, times). A production system would typically require more robust error handling.

5. **Single Executable**  
   - Only one `.exe` or binary is generated because there is only one `main()` function. The other `.cpp` files are class implementations.

