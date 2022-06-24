cmake_minimum_required(VERSION 3.0.0)
project(Cubic-Equation-Solver VERSION 1.0.0)

include(CTest)
enable_testing()

# Main library
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(Cubic-Equation-Solver STATIC ${SOURCES})

target_include_directories(Cubic-Equation-Solver PRIVATE ${PROJECT_SOURCE_DIR}/src PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Testing executable
file(GLOB_RECURSE TEST_SOURCES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(Cubic-Equation-Solver-Tester ${TEST_SOURCES})

target_include_directories(Cubic-Equation-Solver-Tester PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(Cubic-Equation-Solver-Tester PRIVATE Cubic-Equation-Solver)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
