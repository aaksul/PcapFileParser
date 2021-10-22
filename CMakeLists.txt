cmake_minimum_required(VERSION 3.0.0)
project(Project1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(Source_It)
add_subdirectory(Source)
add_subdirectory(Collection)


add_executable(Project1 main.cpp)

target_include_directories(Project1 PUBLIC ${CMAKE_PROJECT_DIR}/my_include)

target_link_libraries(Project1 pcap Source Iterator Collection)

add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
