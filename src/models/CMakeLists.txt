cmake_minimum_required(VERSION 2.6)

add_library(WombatModels OBJECT generated.cpp)

#install(TARGETS WombatModels DESTINATION lib)
install(FILES enums.hpp generated.hpp models.hpp DESTINATION include/wombat/models)
