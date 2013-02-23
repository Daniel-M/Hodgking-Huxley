CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)


INCLUDE_DIRECTORIES( include )

#ADD_DEFINITIONS( -std=c++0x )
#ADD_DEFINITIONS( -std=c++0x -lmgl)

#add_library(customer SHARED
#include/Customer.hpp
#src/Customer.cpp
#)

ADD_EXECUTABLE( hh-model HH-model.cpp )

target_link_libraries( hh-model mgl gsl)
