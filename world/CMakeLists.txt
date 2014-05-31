cmake_minimum_required(VERSION 2.6)

add_library(
	WombatWorld OBJECT
		animlayer.cpp
		camera.cpp
		tile.cpp
		tileinstance.cpp
		world.cpp
		zone.cpp
)

#install(TARGETS WombatWorld DESTINATION lib)
install(
	FILES
		camera.hpp
		tile.hpp
		tileinstance.hpp
		world.hpp
		zone.hpp
	DESTINATION
		include/wombat/world
)
