cmake_minimum_required(VERSION 2.6)

add_library(
	WombatWorld
		animlayer.cpp
		tile.cpp
		tileinstance.cpp
		world.cpp
		zone.cpp
)

install(TARGETS WombatWorld DESTINATION lib)
install(FILES tileclass.hpp DESTINATION include/wombat/world)
