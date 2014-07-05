cmake_minimum_required(VERSION 2.8.8)

add_library(
	WombatWorld OBJECT
		animlayer.cpp
		camera.cpp
		person.cpp
		personclass.cpp
		sprite.cpp
		spriteclass.cpp
		tile.cpp
		tileclass.cpp
		world.cpp
		zone.cpp
		_etc.cpp
)

#install(TARGETS WombatWorld DESTINATION lib)
install(
	FILES
		animlayer.hpp
		camera.hpp
		person.hpp
		sprite.hpp
		spriteclass.hpp
		tile.hpp
		tileclass.hpp
		world.hpp
		zone.hpp
		_etc.hpp
	DESTINATION
		include/wombat/world
)
