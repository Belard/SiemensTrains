cmake_minimum_required(VERSION 3.10)
project(SiemensTrains)

# Enable thread support
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Create the main executable
add_executable(SiemensTrains main.cpp)

# Link thread library
target_link_libraries(SiemensTrains PRIVATE Threads::Threads)
