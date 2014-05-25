cmake_minimum_required(VERSION 2.6)

if(WOMBAT_BUILD_TYPE STREQUAL "GBA")
	add_definitions(-DUSE_GBA)
elseif(WOMBAT_BUILD_TYPE STREQUAL "Native")
	add_definitions(-DWITH_SDL)
endif()

add_library(
	WombatCore
		event.cpp
		gfx.cpp
		misc.cpp
		modelio.cpp
		task.cpp
		sync.cpp
		_cliprectstack.cpp
		_submgr.cpp
		sdl/core.cpp
		sdl/event.cpp
		sdl/gfx.cpp
		sdl/sync.cpp
		sdl/_threads.cpp
		sdl/_tls.cpp
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
