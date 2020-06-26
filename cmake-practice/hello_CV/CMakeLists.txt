cmake_minimum_required(VERSION  2.8.3)
project(hello_cv_8_find_outer_lib)

add_compile_options(-std=c++11) # 引入规则

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../hello_cv_7_install_lib/install/cmake/)
find_package(hello_cv_7_install_lib REQUIRED)

