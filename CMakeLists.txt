## Helpers
if(NOT WIN32)
	string(ASCII 27 Esc)
	set(ColorReset  "${Esc}[m")
	set(ColorBold   "${Esc}[1m")
	set(Red         "${Esc}[31m")
	set(Green       "${Esc}[32m")
	set(Yellow      "${Esc}[33m")
	set(Blue        "${Esc}[34m")
	set(Magenta     "${Esc}[35m")
	set(Cyan        "${Esc}[36m")
	set(White       "${Esc}[37m")
	set(BoldRed     "${Esc}[1;31m")
	set(BoldGreen   "${Esc}[1;32m")
	set(BoldYellow  "${Esc}[1;33m")
	set(BoldBlue    "${Esc}[1;34m")
	set(BoldMagenta "${Esc}[1;35m")
	set(BoldCyan    "${Esc}[1;36m")
	set(BoldWhite   "${Esc}[1;37m")
endif()
## CMake Policy
cmake_policy(SET CMP0005 NEW)
## CMake Minimum Version
cmake_minimum_required(VERSION 3.2)
## Project Name
project(qt-syllogism)
## CMake Settings & Configuration
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++11")
## Source Headers & Files
set(SOURCE_FILES
	Syllogism/Equivalence.hpp
	Syllogism/Meme.hpp
	Syllogism/Context.hpp
	Syllogism/Context.cpp
	main.cpp
)
## Automoc
set(CMAKE_AUTOMOC ON)
## Auto RCC files
set(CMAKE_AUTORCC ON)
## Qt5 Packages
find_package(Qt5Core)
## Executable
add_executable(qt-syllogism ${SOURCE_FILES})
## Links
target_link_libraries(qt-syllogism Qt5::Core)
