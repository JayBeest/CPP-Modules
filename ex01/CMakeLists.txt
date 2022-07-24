project( P-42 )
cmake_minimum_required( VERSION 3.0 )

set( CMAKE_BUILD_TYPE Debug )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -std=c++98" )

include_directories( src )
subdirs( src )
