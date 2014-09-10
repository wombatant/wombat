cmake_minimum_required(VERSION 2.8.8)

add_library(
	WombatUI OBJECT
		textpane.cpp
		ui.cpp
)

install(
	FILES
		textpane.hpp
		ui.hpp
	DESTINATION
		include/wombat/ui
)
