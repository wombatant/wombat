cmake_minimum_required(VERSION 2.6)

add_library(WombatModels enginemodels.cpp)

install(TARGETS WombatModels DESTINATION lib)
install(FILES enginemodels.hpp DESTINATION include/wombat/models)
