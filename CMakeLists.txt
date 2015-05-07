cmake_minimum_required (VERSION 2.8.12)

project (Spectacle CXX C)

function(source_group_setup PROJECT_ROOT)
	foreach(FILE ${ARGN})
		get_filename_component(FILE_DIR "${FILE}" DIRECTORY)

		# skip src or include and changes /'s to \\'s
		string(REPLACE "${PROJECT_ROOT}" "" FILE_DIR "${FILE_DIR}")
		string(REGEX REPLACE "(\\./)?(source|include)/?" "" GROUP "${FILE_DIR}")
		string(REPLACE "/" "\\" GROUP "${GROUP}")

		# group into "Source Files" and "Header Files"
		if ("${FILE}" MATCHES ".*\\.cpp")
			set(GROUP "Source Files\\${GROUP}")
		elseif("${FILE}" MATCHES ".*\\.h")
			set(GROUP "Header Files\\${GROUP}")
		endif()

		source_group("${GROUP}" FILES "${FILE}")
	endforeach()
endfunction(source_group_setup)

# Avoid source tree pollution
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
	message (FATAL_ERROR "In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files already created:\nrm -rf CMakeCache.txt CMakeFiles")
endif(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)

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
file(GLOB_RECURSE PROJECT_SOURCES
     source/*.cpp)

file(GLOB_RECURSE PROJECT_INCLUDES
    include/*.h)

set(SPECTACLE_SOURCES ${PROJECT_SOURCES} ${PROJECT_INCLUDES})

# setup VS filters (and I guess it also does something for XCode?)
source_group_setup(${CMAKE_CURRENT_SOURCE_DIR} ${SPECTACLE_SOURCES})

# configure executable
add_executable(Spectacle ${SPECTACLE_SOURCES})
target_link_libraries(Spectacle LibGunship)
target_include_directories(Spectacle PUBLIC include)
#target_include_directories(Spectacle SYSTEM PUBLIC ${GUNSHIP_INCLUDE_DIRS})

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter -std=c++11")
endif(CMAKE_COMPILER_IS_GNUCXX)
