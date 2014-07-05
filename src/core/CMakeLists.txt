cmake_minimum_required(VERSION 2.8.8)

set(
	CPP
		event.cpp
		gfx.cpp
		misc.cpp
		modelio.cpp
		task.cpp
		sync.cpp
		_cliprectstack.cpp
		_memfs.cpp
		_submgr.cpp
)

if(WOMBAT_BUILD_TYPE STREQUAL "GBA")
	set(
		CPP
			${CPP}
			gba/core.cpp
			gba/corecapabilities.cpp
			gba/event.cpp
			gba/gfx.cpp
			gba/sync.cpp
			gba/_misc.cpp
			gba/_threads.cpp
			gba/_tls.cpp
	)
	include_directories("gba")
elseif(WOMBAT_BUILD_TYPE STREQUAL "Native")
	set(
		CPP
			${CPP}
			sdl/core.cpp
			sdl/corecapabilities.cpp
			sdl/event.cpp
			sdl/gfx.cpp
			sdl/sync.cpp
			sdl/_misc.cpp
			sdl/_threads.cpp
			sdl/_tls.cpp
	)
	include_directories("sdl")
endif()

add_library(WombatCore OBJECT ${CPP})

install(
	FILES
		channel.hpp
		core.hpp
		corecapabilities.hpp
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
