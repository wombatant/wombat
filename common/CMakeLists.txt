cmake_minimum_required(VERSION 2.6)

add_library(
	WombatCommon OBJECT
		bounds.cpp
		point.cpp
)

#install(TARGETS WombatCommon DESTINATION lib)
install(
	FILES
		bounds.hpp
		common.hpp
		point.hpp
	DESTINATION
		include/wombat/common
)
