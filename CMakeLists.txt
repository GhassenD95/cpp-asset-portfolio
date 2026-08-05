cmake_minimum_required(VERSION 4.3)
project(asset_portfolio)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Werror -pedantic)
add_executable(asset_portfolio main.cpp)
