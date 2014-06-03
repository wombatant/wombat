cmake_minimum_required(VERSION 2.6)

add_library(
	WombatWorld OBJECT
		animlayer.cpp
		camera.cpp
		sprite.cpp
		spriteclass.cpp
		tile.cpp
		tileclass.cpp
		world.cpp
		zone.cpp
)

#install(TARGETS WombatWorld DESTINATION lib)
install(
	FILES
		camera.hpp
		tile.hpp
		tileclass.hpp
		world.hpp
		zone.hpp
	DESTINATION
		include/wombat/world
)
