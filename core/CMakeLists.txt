cmake_minimum_required(VERSION 2.6)

add_definitions(-DWITH_ALLEGRO)

add_library(WombatCore alcore.cpp core.cpp algfx.cpp gfx.cpp flyweight.cpp)

install(TARGETS WombatCore DESTINATION lib)
install(FILES core.hpp DESTINATION include/wombat/core)
