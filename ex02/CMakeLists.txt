project( ex02 )
cmake_minimum_required( VERSION 3.0 )

set( CMAKE_BUILD_TYPE Debug )
set( CMAKE_VERBOSE_MAKEFILE OFF )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -std=c++98" )

include_directories( src )
subdirs( src )
