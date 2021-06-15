cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(LCSS VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(Config.h.in Config.h)

# add the executable
add_executable(LCSS main.cpp)

# add the binary tree to the search path for include files
# so that we will find Config.h
target_include_directories(LCSS PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

install(TARGETS LCSS DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/Config.h"
  DESTINATION include
  )
