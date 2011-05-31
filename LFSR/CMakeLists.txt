cmake_minimum_required (VERSION 2.6)
project (CCTk)
# Version number
set (CCTk_VERSION_MAJOR 1)
set (CCTk_VERSION_MINOR 0)


# Compiler flags
set(CMAKE_CXX_FLAGS "-g -Wall")

# Headers settings (variables)
configure_file (
    "${PROJECT_SOURCE_DIR}/CCTkConfig.hh.in"
    "${PROJECT_BINARY_DIR}/CCTkConfig.hh"
)


# Add binary tree to search path for include files
include_directories("${PROJECT_BINARY_DIR}")

add_executable(TestLFSR 
    testLFSR.cc
    LFSR.hh
    LFSR.cc
    aSyncLFSR.hh
    aSyncLFSR.cc)
