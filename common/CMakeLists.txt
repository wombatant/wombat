cmake_minimum_required(VERSION 2.6)

add_library(WombatCommon flyweight.cpp)

install(TARGETS WombatCommon DESTINATION lib)
install(FILES flyweight.hpp DESTINATION include/wombat/common)
