cmake_minimum_required(VERSION 3.7)
project(llvm_old_example)

set(CMAKE_CXX_STANDARD 11)

include_directories(/Users/kieranrimmer/packages/llvm/include /Users/kieranrimmer/packages/build/include)

set(SOURCE_FILES main.cpp)
add_executable(llvm_old_example ${SOURCE_FILES})