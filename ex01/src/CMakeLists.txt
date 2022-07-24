project( P-42 )
cmake_minimum_required( VERSION 3.0 )

set( CMAKE_BUILD_TYPE Debug )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable( P-42 )
include( sourcelist.cmake )

set_target_properties( P-42
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )
