


add_library(Collection collection.cpp collection.h)

target_include_directories(Collection PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/my_include)