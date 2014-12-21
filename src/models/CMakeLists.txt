cmake_minimum_required(VERSION 2.8.8)

add_library(
	WombatModels OBJECT
		generated.cpp
		json_read.cpp
		json_write.cpp
		types.cpp
)

add_executable(
	json_test
		json_test.cpp
		$<TARGET_OBJECTS:WombatModels>
)

target_link_libraries(json_test ${JANSSON_LIBRARY})

#install(TARGETS WombatModels DESTINATION lib)
install(
	FILES
		generated.hpp
		error.hpp
		json_read.hpp
		json_write.hpp
		types.hpp
	DESTINATION
		include/wombat/models
)
