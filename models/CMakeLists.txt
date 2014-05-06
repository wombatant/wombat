cmake_minimum_required(VERSION 2.6)

add_library(WombatModels models.cpp)

install(TARGETS WombatModels DESTINATION lib)
install(FILES models/models.hpp DESTINATION include/wombat/models)
