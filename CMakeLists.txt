cmake_minimum_required (VERSION 3.21.1)
project (Chess LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(Boost REQUIRED)

include_directories(
	${Boost_INCLUDE_DIRS}
	${CMAKE_SOURCE_DIR})

link_directories(${Boost_LIBRARY_DIRS})

add_compile_definitions($<$<CONFIG:Debug>:DEBUG>)

add_executable(repl Chess.h Repl.cpp)
set_property(TARGET repl PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
