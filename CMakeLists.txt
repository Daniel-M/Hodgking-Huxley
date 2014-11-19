CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)

PROJECT("Hodgkin-Huxley")

INCLUDE_DIRECTORIES( include )

ADD_DEFINITIONS( --std=c++11 )

#add_library(customer SHARED
#include/Customer.hpp
#src/Customer.cpp
#)

ADD_EXECUTABLE(hh-model src/HH-model )

target_link_libraries(hh-model mgl)
