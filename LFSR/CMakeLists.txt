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
include_directories(
    "${PROJECT_BINARY_DIR}/src"
)

file(
    GLOB_RECURSE
    lfsr_sources
    src/*
    )

# Tests executable
ENABLE_TESTING()
add_executable(test/runLFSR 
    test/LFSR_test.cc
    ${lfsr_sources}
)

add_executable(test/runBerlekampMassey
    test/BerlekampMassey_test.cc
    ${lfsr_sources}
)

add_executable(test/runShortLFSR
    test/ShortLFSR_test.cc
    ${lfsr_sources}
)

add_test(ShortLFSR test/runShortLFSR)
add_test(LongLFSR test/runLFSR)
