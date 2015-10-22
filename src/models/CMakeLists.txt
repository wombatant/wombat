cmake_minimum_required(VERSION 2.8.8)

add_library(
	WombatModels OBJECT
		generated.cpp
		json_read.cpp
		json_write.cpp
		ptr.cpp
		types.cpp
		unknown.cpp
)

add_executable(
	json_test
		json_test.cpp
		$<TARGET_OBJECTS:WombatModels>
)

target_link_libraries(json_test ${JANSSON_LIBRARY})

add_test("json_test" json_test)

#install(TARGETS WombatModels DESTINATION lib)
install(
	FILES
		generated.hpp
		error.hpp
		json_read.hpp
		json_write.hpp
		ptr.hpp
		types.hpp
		unknown.hpp
	DESTINATION
		include/wombat/models
)
