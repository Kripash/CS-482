cmake_minimum_required (VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (2-Spam)

include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(training src/training.cc)
add_executable(classify src/classify.cc)

