function(setup_msvc)
    string(APPEND CMAKE_CXX_FLAGS " /Wall /WX /sdl")
    string(APPEND CMAKE_CXX_FLAGS_DEBUG " /Od")
    string(APPEND CMAKE_CXX_FLAGS_RELEASE " /O2")
    string(APPEND CMAKE_CXX_FLAGS_RELWITHDEBUGINFO " -O2 -g -DNDEBUG")
    string(APPEND CMAKE_CXX_FLAGS_MINSIZEREL " /01")
endfunction()

