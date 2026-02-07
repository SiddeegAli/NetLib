cmake_minimum_required(VERSION 3.10)
project(NetLib VERSION 0.1 DESCRIPTION "A simple cross-platform networking library" HOMEPAGE_URL "https://github.com/SiddeegAli/NetLib")

option(BUILD_EXAMPLES "Build the example projects" ON)

add_library(NetLib
    src/Platform.cpp
    src/Socket.cpp
    src/Address.cpp
    src/TcpSocket.cpp
)

if(BUILD_EXAMPLES)
    add_executable(server example/server.cpp)
    add_executable(client example/client.cpp)

    target_link_libraries(server NetLib)
    target_link_libraries(client NetLib)

    target_include_directories(server PUBLIC include)
    target_include_directories(client PUBLIC include)
endif()


#include the header files for the library
target_include_directories(NetLib PUBLIC include)

#link the library with the necessary system libraries
if (WIN32)
    target_link_libraries(NetLib ws2_32)
endif()

#set the output directory for the library
set_target_properties(NetLib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)