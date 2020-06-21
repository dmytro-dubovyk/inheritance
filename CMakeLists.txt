cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "inheritance")

project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wshadow -Wundef -Wno-missing-field-initializers")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/virtual_worker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/worker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)
