cmake_minimum_required(VERSION 2.6)

project(wombat)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

add_definitions(
	-std=c++11
	#-g
	#--analyze
)

#setup libraries

find_package(Jansson REQUIRED)
include_directories(${JANSSON_INCLUDE_DIR})
set(LIBS ${LIBS} ${JANSSON_LIBRARY})

find_package(SDL REQUIRED)
include_directories(${SDL_INCLUDE_DIR})
set(LIBS ${LIBS} ${SDL_LIBRARY})

find_package(SDL_IMAGE REQUIRED)
include_directories(${SDL_IMAGE_INCLUDE_DIR})
set(LIBS ${LIBS} ${SDL_IMAGE_LIBRARY})


#project packages

include_directories(".")

add_subdirectory(models)
set(LIBS WombatModels ${LIBS})

add_subdirectory(core)
set(LIBS WombatCore ${LIBS})

add_subdirectory(world)
set(LIBS WombatWorld ${LIBS})

add_executable(
	wombat
		app.cpp
		main.cpp
		tests.cpp
)

target_link_libraries(wombat ${LIBS})
