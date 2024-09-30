cmake_minimum_required(VERSION 3.28.3)

include_directories(.)

project(vi)
set(CMAKE_CXX_STANDARD 11) 

add_executable(vi core/vi.cpp core/editor/editor.cpp core/text/add.cpp core/text/del.cpp core/text/insert.cpp core/text/remove.cpp core/text/text.cpp core/util/util.cpp)
