cmake_minimum_required(VERSION 3.10)
project(main VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the precompiled header file
set(PCH_FILE "pch.h")                   # Name of the precompiled header
set(PCH_SOURCE "pch.cpp")               # Source file for the precompiled header

# Find packages (uncomment if needed)
# find_package(fmt REQUIRED)

# Create the main executable target
add_executable(main AsyncPrimeCheck.cpp)

# Link libraries (uncomment if needed)
# target_link_libraries(main PRIVATE fmt::fmt)

# Set compile options for the target (C++23 and multi-threading)
target_compile_options(main PRIVATE /MP)

# Add the precompiled header
target_precompile_headers(main PRIVATE ${PCH_FILE})
