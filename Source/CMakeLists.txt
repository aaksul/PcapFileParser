

add_library(Source source.cpp)


target_include_directories(Source
                PUBLIC
                ${CMAKE_CURRENT_SOURCE_DIR})



target_link_libraries(Source Iterator pcap)

