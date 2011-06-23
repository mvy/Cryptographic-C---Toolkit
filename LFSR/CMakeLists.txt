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


# Add binary tree to search path for include files
include_directories(
    "${PROJECT_BINARY_DIR}/src"
)

file(
    GLOB_RECURSE
    lfsr_sources
    src/*
    )

SET(EXECUTABLE_OUTPUT_PATH bin/)
add_executable(BerlekampMassey
    tools/BerlekampMasseyMain.cc
    ${lfsr_sources}
)


# Tests executable
ENABLE_TESTING()
add_executable(testLFSR 
    test/LFSR_test.cc
    ${lfsr_sources}
)

add_executable(testBerlekampMassey
    test/BerlekampMassey_test.cc
    ${lfsr_sources}
)

add_executable(testShortLFSR
    test/ShortLFSR_test.cc
    ${lfsr_sources}
)

add_executable(testReductionEquality
    test/ReductionEquality_test.cc
    ${lfsr_sources}
)

add_executable(testMSeq
    test/mseq_test.cc
    ${lfsr_sources}
)

add_executable(testASyncShort
    test/aSync_test.cc
    ${lfsr_sources}
)


add_test(ShortLFSR bin/testShortLFSR)
add_test(LongLFSR bin/testLFSR)
add_test(EqualReductedLFSR bin/testReductionEquality)
add_test(BerlekampMassey bin/testBerlekampMassey)
add_test(ASyncShort bin/testASyncShort)
