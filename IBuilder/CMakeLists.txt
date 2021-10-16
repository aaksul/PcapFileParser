add_library(Builder packet_builder.cpp)

target_include_directories(Builder INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})