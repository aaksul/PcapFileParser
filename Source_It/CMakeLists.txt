


add_library(Iterator iterator.cpp)


target_include_directories(Iterator
                PUBLIC
                ${CMAKE_CURRENT_SOURCE_DIR}
                ${PROJECT_SOURCE_DIR}/my_include)


target_link_libraries(Iterator Source)