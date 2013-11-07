cmake_minimum_required(VERSION 2.6)

project(wombat)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

#setup libraries

find_package(Jansson REQUIRED)
include_directories(${Jansson_INCLUDE_DIRS})
set(LIBS ${LIBS} ${JANSSON_LIBRARY})

find_package(Allegro REQUIRED)
include_directories(${Allegro_INCLUDE_DIRS})
set(LIBS ${LIBS} ${ALLEGRO_LIBRARIES})


#project packages

include_directories(".")

add_subdirectory(models)
set(LIBS ${LIBS} WombatModels)

add_subdirectory(core)
set(LIBS ${LIBS} WombatCore)

add_executable(wombat main.cpp tests.cpp)
target_link_libraries(wombat ${LIBS})
