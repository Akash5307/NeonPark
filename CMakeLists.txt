#CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(ParkingLotSystem)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

find_path(PQXX_INCLUDE_DIR NAMES pqxx/pqxx)
find_library(PQXX_LIBRARY NAMES pqxx)

include_directories(${PQXX_INCLUDE_DIR})

add_executable(parking_lot main.cpp PostgresDB.cpp ParkingLot.cpp)

target_link_libraries(parking_lot
    ${PQXX_LIBRARY} pq Threads::Threads
)

enable_testing()
add_subdirectory(tests)
