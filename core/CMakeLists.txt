cmake_minimum_required(VERSION 2.6)

add_definitions(-DWITH_ALLEGRO)

add_library(WombatCore alcore.cpp algfx.cpp gfx.cpp flyweight.cpp)

install(TARGETS WombatCore DESTINATION bin)
install(FILES core.hpp DESTINATION include)
