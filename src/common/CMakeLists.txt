cmake_minimum_required(VERSION 2.8.8)

add_library(
	WombatCommon OBJECT
		bounds.cpp
		flyweight.cpp
		point.cpp
)

#install(TARGETS WombatCommon DESTINATION lib)
install(
	FILES
		bounds.hpp
		common.hpp
		flyweight.hpp
		point.hpp
	DESTINATION
		include/wombat/common
)
