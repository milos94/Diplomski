function(setup_gcc)
    string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast \
                                    -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic \
                                    -Wconversion -Wsign-conversion -Wnull-dereference \
                                    -Wdouble-promotion -Wformat=2 -Wduplicated-cond \
                                    -Wduplicated-branches -Wlogical-op -Wuseless-cast -Wattributes \
                                    -Wno-unknown-pragmas")
    string(APPEND CMAKE_CXX_FLAGS_DEBUG " -O0 -g")
    string(APPEND CMAKE_CXX_FLAGS_RELEASE " -O3")
    string(APPEND CMAKE_CXX_FLAGS_RELWITHDEBUGINFO " -O3 -g -DNDEBUG")
    string(APPEND CMAKE_CXX_FLAGS_MINSIZEREL " -0s")
endfunction()
