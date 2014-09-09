cmake_minimum_required(VERSION 2.8.8)

add_library(
	WombatEntities OBJECT
		creature.cpp
		person.cpp
)

install(
	FILES
		creature.hpp
		person.hpp
	DESTINATION
		include/wombat/entities
)
