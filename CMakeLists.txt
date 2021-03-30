cmake_minimum_required(VERSION 3.7.0)

if(${CMAKE_VERSION} VERSION_LESS 3.20)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.20)
endif()

set(CMAKE_CUDACXX_COMPILER "/usr/bin/clang++-12")
#set(CUDA_TOOLKIT_ROOT_DIR "/usr/local/cuda/")
project(cuda_tutorial VERSION 1.0 
                      DESCRIPTION "cuda tutorial project"
                      LANGUAGES CXX CUDACXX)



include(CTest)
enable_testing()

# options for generating export header
include(GenerateExportHeader)

# options for which library to use
option(USE_CH4 "Use chapter_4 tutorial implementations" "ON")
option(USE_CUDA "Use cuda implementation" "OFF")


# configure file for stating version of project
configure_file(cuda_tutorial_config.h.in cuda_tutorial_config.h)

# restrict CXX standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# list of libraries that implementing tutorials in cuda cook book
# appended in to EXTRA_LIBS 
if(USE_CH4)
    add_library(chapter_4 SHARED chapter_4/vector_sum.cpp chapter_4/add.cu chapter_4/vector_sum.hpp)
    generate_export_header(chapter_4)
    add_subdirectory(chapter_4)
    list(APPEND EXTRA_LIBS chapter_4)
    target_include_directories(chapter_4
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )
endif()

# add the excutable, libraries and link them
add_executable(cuda_tutorial main.cpp)
target_link_libraries(cuda_tutorial PRIVATE ${EXTRA_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)



target_include_directories(cuda_tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

