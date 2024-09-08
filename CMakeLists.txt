cmake_minimum_required(VERSION 3.10)

# Project name and language
project(GBAEmulator 
    VERSION 1.0
    DESCRIPTION "Game Boy Advance Emulator"
    LANGUAGES CXX
)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(gba_emulator 
    src/main.cpp
    src/ARM7TDMI_S.cpp
)

# Include directories
target_include_directories(gba_emulator PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Compiler warnings
if(MSVC)
    target_compile_options(gba_emulator PRIVATE /W4)
else()
    target_compile_options(gba_emulator PRIVATE -Wall -Wextra -Wpedantic)
endif()