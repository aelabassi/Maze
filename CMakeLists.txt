cmake_minimum_required(VERSION 3.10)

# Project name
project(Maze)
# Set C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add SDL2 package
find_package(SDL2 REQUIRED COMPONENTS SDL2)

# Include directories
include_directories(${SDL2_INCLUDE_DIRS})

# Source files
file(GLOB SOURCES "src/*.c")
file(GLOB HEADERS "include/*.h")
# Create executable
add_executable(Maze ${SOURCES} ${HEADERS})
# Link SDL2
target_link_libraries(Maze PRIVATE SDL2::SDL2)

# If you're using SDL2_image, SDL2_ttf, or SDL2_mixer, add them like this:
# find_package(SDL2_image REQUIRED)
# find_package(SDL2_ttf REQUIRED)
# find_package(SDL2_mixer REQUIRED)
# target_link_libraries(3D_Maze ${SDL2_IMAGE_LIBRARIES})
# target_link_libraries(3D_Maze ${SDL2_TTF_LIBRARIES})
# target_link_libraries(3D_Maze ${SDL2_MIXER_LIBRARIES})

# Set include directories
target_include_directories(Maze PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# If you have a specific build type, you can set it like this:
# set(CMAKE_BUILD_TYPE Release)

# If you want to add compiler flags:
if(MSVC)
    target_compile_options(Maze PRIVATE /W4)
else()
    target_compile_options(Maze PRIVATE -Wall -g -Werror -Wextra -Wpedantic)
endif()

