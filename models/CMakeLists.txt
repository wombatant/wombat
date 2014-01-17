cmake_minimum_required(VERSION 2.6)

add_library(WombatModels models/enginemodels.cpp)

install(TARGETS WombatModels DESTINATION lib)
install(FILES models/enginemodels.hpp DESTINATION include/wombat/models)
