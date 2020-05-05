cmake_minimum_required(VERSION 3.10)
project(20S-3353-PA04)
set (EXE_NAME FinalProject)

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O3 -g")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O3 -g")
add_executable(${EXE_NAME} main.cpp TrivialSolution.h BacktrackingSolution.h BacktrackingSolution.cpp TrivialSolution.cpp)
