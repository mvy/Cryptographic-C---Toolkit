cmake_minimum_required (VERSION 2.6)
project (CCTk)
# Version number
set (CCTk_VERSION_MAJOR 1)
set (CCTk_VERSION_MINOR 0)


# Compiler flags for Debug (appended to CMAKE_CXX_FLAGS)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall")

# Headers settings (variables)
configure_file (
    "${PROJECT_SOURCE_DIR}/src/CCTkConfig.hh.in"
    "${PROJECT_BINARY_DIR}/src/CCTkConfig.hh"
)


SET(EXECUTABLE_OUTPUT_PATH test/)
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
add_executable(runLFSR 
    test/LFSR_test.cc
    ${lfsr_sources}
)

add_executable(runBerlekampMassey
    test/BerlekampMassey_test.cc
    ${lfsr_sources}
)

add_executable(runShortLFSR
    test/ShortLFSR_test.cc
    ${lfsr_sources}
)

add_executable(runReductionEquality
    test/ReductionEquality_test.cc
    ${lfsr_sources}
)

add_executable(runMSeq
    test/mseq_test.cc
    ${lfsr_sources}
)

add_test(ShortLFSR test/runShortLFSR)
add_test(LongLFSR test/runLFSR)
add_test(EqualReductedLFSR test/runReductionEquality)
add_test(BerlekampMassey test/runBerlekampMassey)
