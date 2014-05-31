cmake_minimum_required(VERSION 2.6)

add_library(WombatModels OBJECT models.cpp)

#install(TARGETS WombatModels DESTINATION lib)
install(FILES models.hpp DESTINATION include/wombat/models)
