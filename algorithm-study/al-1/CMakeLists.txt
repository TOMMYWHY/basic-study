cmake_minimum_required(VERSION 3.14)
project(algorithm1)

include_directories(include/)
file(GLOB PROJECT_HEADERS include/*.h)

# debug
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")


#DFS BFS
#set(SOURCE_FILES src/main.cpp include/MyTree.h include/MyStack.h)
#set(SOURCE_FILES src/Astar.cpp)
set(SOURCE_FILES src/LPAstar.cpp src/TreeNode.h)

add_executable(algorithm1 ${SOURCE_FILES} ${PROJECT_HEADERS} )



