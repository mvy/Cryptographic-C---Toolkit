cmake_minimum_required (VERSION 2.6)
project (CCTk)
# Version number
set (CCTk_VERSION_MAJOR 1)
set (CCTk_VERSION_MINOR 0)


# Compiler flags
set(CMAKE_CXX_FLAGS "-g -Wall")

# Headers settings (variables)
configure_file (
    "${PROJECT_SOURCE_DIR}/src/CCTkConfig.hh.in"
    "${PROJECT_BINARY_DIR}/src/CCTkConfig.hh"
)


# Add binary tree to search path for include files
include_directories("${PROJECT_BINARY_DIR}")

file(
    GLOB_RECURSE
    lfsr_sources
    src/*
    )

add_executable(test/TestLFSR 
    test/testLFSR.cc
    ${lfsr_sources}
    )
