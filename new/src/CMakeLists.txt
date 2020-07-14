cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(diplomski VERSION 0 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(common_setup)
setup_common()

include(doxygen_setup)
enable_doxygen(OFF)

if(CXX_COMPILER_ID STREQUAL GNU)
    include(gcc_setup)
    setup_gcc()
elseif(CXX_COMPIER_ID STREQUAL CLANG)
    include(clang_setup)
    setup_clang()
elseif(CXX_COMPILERID STREQUAL MSVC)
    include(msvc_setup)
    setup_msvc()
endif()


add_subdirectory(client)

add_subdirectory(server)

add_subdirectory(lib)