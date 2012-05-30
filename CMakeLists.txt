# Set the minimum version of CMake required
cmake_minimum_required(VERSION 2.8)

# Set the project name
project(NUI)

# Defines options
option(BUILD_SAMPLES "Also build the nui samples" ON)

# Sets where to put the output files
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Add include directories based on the platform on which we are compiling this project
if(WIN32)
	include_directories(${PROJECT_SOURCE_DIR}/src/native/win32)
elseif(UNIX)
	include_directories(${PROJECT_SOURCE_DIR}/src/native/gtk3)
endif(WIN32)

# Add subdirectories
add_subdirectory(${PROJECT_SOURCE_DIR}/src)

# Checks if we should build the samples
if(BUILD_SAMPLES)
	include_directories(${PROJECT_SOURCE_DIR}/src)
	add_subdirectory(${PROJECT_SOURCE_DIR}/samples/basic)
endif(BUILD_SAMPLES)