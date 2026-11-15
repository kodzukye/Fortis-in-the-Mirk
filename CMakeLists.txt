cmake_minimum_required(VERSION 3.20)
project(Fortis_in_the_Mirk)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

# Download raylib automatically
include(FetchContent)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 6.2
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(raylib)

add_executable(fortis_in_the_mirk
        src/main.cpp
        src/window.cpp
        src/window.h
        src/animation.h
        src/types.h
        src/animated_sprite.cpp
        src/animated_sprite.h
        src/texture_manager.cpp
        src/texture_manager.h
)
target_link_libraries(fortis_in_the_mirk PRIVATE raylib)

add_custom_command(TARGET fortis_in_the_mirk POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:fortis_in_the_mirk>/assets
)