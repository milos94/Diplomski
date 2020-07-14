function(setup_clang)
    string(APPEND CMAKE_CXX_FLAGS " -Werror -Weverything -pedantic -Wsystem-headers")
    string(APPEND CMAKE_CXX_FLAGS_DEBUG " -O0 -g")
    string(APPEND CMAKE_CXX_FLAGS_RELEASE " -O3")
    string(APPEND CMAKE_CXX_FLAGS_RELWITHDEBUGINFO " -O3 -g -DNDEBUG")
    string(APPEND CMAKE_CXX_FLAGS_MINSIZEREL " -0s")
endfunction()
