cmake_minimum_required(VERSION 2.8.8)

project(wombat)

set(WOMBAT_BUILD_TYPE "Native" CACHE STRING "The type of build to produce(Native/GBA)")


add_executable(
	wombat
		app.cpp
		main.cpp
		tests.cpp
		${OBJS}
)

target_link_libraries(wombat ${LIBS})
#set_target_properties(wombat
#	PROPERTIES
#	LINK_FLAGS ${LINKER_FLAGS}
#	COMPILER_FLAGS "-mthumb -mthumb-interwork"
#)
#objcopy_file(wombat)
