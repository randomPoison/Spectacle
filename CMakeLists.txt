cmake_minimum_required (VERSION 2.8.12)

project (Spectacle CXX C)

# Avoid source tree pollution
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
	message (FATAL_ERROR "In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files already created:\nrm -rf CMakeCache.txt CMakeFiles")
endif (CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)

# Include path for additional CMake library finding scripts
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# load gunship
set(GUNSHIP_BUILD_EXE OFF
    CACHE BOOL "Tells gunship to not build the exectuable (should be set to OFF).")
add_subdirectory(${GUNSHIP_HOME} ${CMAKE_BINARY_DIR}/Gunship)
get_directory_property(GUNSHIP_INCLUDE_DIRS
                       DIRECTORY ${GUNSHIP_HOME}
                       DEFINITION GUNSHIP_INCLUDE_DIRS)

# The project's sources
file(GLOB PROJECT_SOURCES
     source/Spectacle.cpp)

# configure executable
add_executable (Spectacle ${PROJECT_SOURCES})
target_link_libraries(Spectacle LibGunship)
target_include_directories(Spectacle PUBLIC include)
target_include_directories(Spectacle SYSTEM PUBLIC ${GUNSHIP_INCLUDE_DIRS})

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")
endif(CMAKE_COMPILER_IS_GNUCXX)
