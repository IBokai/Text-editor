cmake_minimum_required(VERSION 3.28.3)

include_directories(.)

project(vi)
set(CMAKE_CXX_STANDARD 11) 

add_executable(vi
    core/vi.cpp 
    core/editor/editor.cpp
    core/editor/print.cpp
    core/editor/run.cpp
    core/text/text.cpp 
    core/text/add.cpp 
    core/text/insert.cpp 
    core/text/registerchange.cpp
    core/text/remove.cpp 
    core/text/replace.cpp
    core/util/util.cpp
    core/parser/parser.cpp
    core/parser/parsercommandinfo.cpp 
    core/parser/parserparameter.cpp
)
