cmake_minimum_required(VERSION 3.14)
project(openmpDemo)
set(CMAKE_CXX_STANDARD 14)

# MPI
#find_package(MPI REQUIRED)
# openmp
find_package(OpenMP)
#include_directories(${MPI_INCLUDE_PATH})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")


#SET(CMAKE_CXX_COMPILER mpicxx)

set(SOURCE_FILES main.cpp)




add_executable(openmpDemo ${SOURCE_FILES})

#add_custom_command(TARGET ${PROJECT_NAME}
#        POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/res
#        $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)



