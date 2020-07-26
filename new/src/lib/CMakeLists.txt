set(lib_name kerber_lib)

set(HEADERS
    common.hpp
    caeserencryptor.hpp
    )

add_library(${lib_name} INTERFACE)

target_sources(${lib_name} INTERFACE ${HEADERS})

target_include_directories(${lib_name} INTERFACE "${PROJECT_SOURCE_DIR}/lib")

add_subdirectory(tests)