cmake_minimum_required(VERSION 2.6)

add_definitions(-DWITH_ALLEGRO)

add_library(core alcore.cpp algfx.cpp)

install(TARGETS core DESTINATION bin)
install(FILES core.hpp DESTINATION include)
