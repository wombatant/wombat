cmake_minimum_required(VERSION 2.6)

add_library(WombatModels modelmakerdefs.cpp enginemodels.cpp)

install(TARGETS WombatModels DESTINATION bin)
install(FILES modelmakerdefs.hpp enginemodels.hpp DESTINATION include)
