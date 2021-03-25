cmake_minimum_required(VERSION 3.0.0)
project(cuda_tutorial VERSION 1.0)

include(CTest)
enable_testing()

# options for which library to use
#option(USE_CH4 "Use chapter_4 tutorial implementations" ON)

# configure file for stating version of project
configure_file(cuda_tutorial_config.h.in cuda_tutorial_config.h)

# list of libraries that implementing tutorials in cuda cook book
# appended in to EXTRA_LIBS and EXTRA_INCLUDES
if(USE_CH4)
    #add_subdirectory(chapter_4)
    list(APPEND EXTRA_LIBS chapter_4)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/chapter_4")
endif()

# add the excutable 
add_executable(cuda_tutorial main.cpp)

target_link_libraries(cuda_tutorial PUBLIC chapter_4)

# restrict CXX standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_include_directories(cuda_tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )