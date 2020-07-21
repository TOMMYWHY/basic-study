cmake_minimum_required(VERSION 3.14)
project(Demo)
set(CMAKE_CXX_STANDARD 14)

# MPI
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})


SET(CMAKE_CXX_COMPILER mpicxx)

#set(SOURCE_FILES src/main.cpp)
set(SOURCE_FILES src/first.cpp)




add_executable(Demo ${SOURCE_FILES})

#add_custom_command(TARGET ${PROJECT_NAME}
#        POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/res
#        $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)



