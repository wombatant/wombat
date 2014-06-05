cmake_minimum_required(VERSION 2.6)

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
		worldobject.cpp
		zone.cpp
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
		worldobject.hpp
		zone.hpp
	DESTINATION
		include/wombat/world
)
