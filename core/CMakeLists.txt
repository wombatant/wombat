cmake_minimum_required(VERSION 2.6)

add_definitions(-DWITH_SDL)

add_library(WombatCore sdlcore.cpp misc.cpp sdlgfx.cpp gfx.cpp sdlevent.cpp sdlthreads.cpp modelio.cpp threads.cpp)

install(TARGETS WombatCore DESTINATION lib)
install(
	FILES
		core.hpp
		event.hpp
		gfx.hpp
		modelio.hpp
		threads.hpp
		types.hpp
	DESTINATION
		include/wombat/core
)
