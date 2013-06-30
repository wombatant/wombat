cmake_minimum_required(VERSION 2.6)

add_library(models modelmakerdefs.cpp enginemodels.cpp)

install(TARGETS models DESTINATION bin)
install(FILES modelmakerdefs.hpp enginemodels.hpp DESTINATION include)
