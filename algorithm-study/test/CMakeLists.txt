cmake_minimum_required(VERSION 3.16)
project(test)

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

include_directories(include/)
file(GLOB PROJECT_HEADERS include/*.h)


source_group("Headers" FILES ${PROJECT_HEADERS})


add_executable(test src/main.cpp)

set(SOURCE_FILES main.cpp )


add_executable(barcodes ${SOURCE_FILES} ${PROJECT_HEADERS} )
target_link_libraries(barcodes ${OpenCV_LIBS})

