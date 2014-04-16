cmake_minimum_required(VERSION 2.6)

add_definitions(-DWITH_SDL)

add_library(WombatWorld tileclass.cpp tile.cpp)

install(TARGETS WombatWorld DESTINATION lib)
install(FILES tileclass.hpp DESTINATION include/wombat/world)
