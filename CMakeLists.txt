# Author: Julian Yi
# Date: 14 July 2017


# A simple example CMake Setup for Compiling C Programs. This setup utilizes a single
# subdirectory (src) in which all C++ source (.cpp) and header (.h) files within that
# directory are included within the project.

# CMake projects are forward compatible, but may not be backwards compatible. This
# commands defines the version of CMake used for the current setup.

cmake_minimum_required(VERSION 2.6)

# Define the project name.

project ( Chess )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

configure_file(font/FSEX300.ttf ${CMAKE_BINARY_DIR}/bin/font/FSEX300.ttf COPYONLY)

# Add a subdirectory to the project. The CMakeLists.txt file in that subdirectory
# will be used for further setting up the project.
add_subdirectory( src )
INCLUDE_DIRECTORIES( ${CMAKE_BINARY_DIR}/inc )
LINK_DIRECTORIES( ${CMAKE_BINARY_DIR}/res )
#TARGET_LINK_LIBRARIES( Chess BearLibTerminal )
