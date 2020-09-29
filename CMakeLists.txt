cmake_minimum_required(VERSION 3.4)

project(SimpleCountPass)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

add_definitions(${LLVM_DEFINITIONS})
include_directories(
        ${LLVM_INCLUDE_DIRS}
)
link_directories(${LLVM_LIBRARY_DIRS})
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(SimpleCountPass)