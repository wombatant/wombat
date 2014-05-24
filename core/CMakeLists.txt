cmake_minimum_required(VERSION 2.6)

if(WOMBATCORE_TYPE STREQUAL "SDL")
	add_definitions(-DWITH_SDL)
endif()

add_library(
	WombatCore
		event.cpp
		gfx.cpp
		misc.cpp
		modelio.cpp
		task.cpp
		sdlcore.cpp
		sdlevent.cpp
		sdlgfx.cpp
		sdlsync.cpp
		sync.cpp
		_cliprectstack.cpp
		_sdlthreads.cpp
		_sdltls.cpp
		_submgr.cpp
)

install(TARGETS WombatCore DESTINATION lib)
install(
	FILES
		channel.hpp
		core.hpp
		event.hpp
		gfx.hpp
		modelio.hpp
		sync.hpp
		task.hpp
		tls.hpp
		types.hpp
		_cliprectstack.hpp
		_submgr.hpp
		_threads.hpp
	DESTINATION
		include/wombat/core
)
