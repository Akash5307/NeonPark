#src/CMakeLists.txt
# Use target_include_directories to add include paths
include_directories(${PQXX_INCLUDE_DIR} ${CMAKE_SOURCE_DIR})

add_executable(unit_tests
    main_test.cpp
    ../PostgresDB.cpp
)

# Find and link GoogleTest properly
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(unit_tests
    ${PQXX_LIBRARY}
    pq
    Threads::Threads
    GTest::GTest
    GTest::Main
)

add_test(NAME unit_tests COMMAND unit_tests)
