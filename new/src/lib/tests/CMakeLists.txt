set(TARGET_NAME kerb_lib_tests)

set(HEADRES
    tests_common.hpp
    caeserencryptor_test.hpp
)

set(SOURCES 
    tests.cpp
)

set(LIBS 
    kerber_lib
    pthread)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INLCUDER_DIRS})
add_executable(${TARGET_NAME} ${HEADRES} ${SOURCES})

target_link_libraries(${TARGET_NAME} ${GTEST_LIBRARIES} ${LIBS})