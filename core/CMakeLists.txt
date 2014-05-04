cmake_minimum_required(VERSION 2.6)

add_definitions(-DWITH_SDL)

add_library(
	WombatCore
		event.cpp
		gfx.cpp
		misc.cpp
		modelio.cpp
		task.cpp
		threads.cpp
		sdlcore.cpp
		sdlevent.cpp
		sdlgfx.cpp
		sdlthreads.cpp
		_sdltls.cpp
		_submgr.cpp
		_viewportmgr.cpp
)

install(TARGETS WombatCore DESTINATION lib)
install(
	FILES
		core.hpp
		event.hpp
		gfx.hpp
		modelio.hpp
		task.hpp
		tls.hpp
		threads.hpp
		types.hpp
		_submgr.hpp
		_viewportmgr.hpp
	DESTINATION
		include/wombat/core
)
