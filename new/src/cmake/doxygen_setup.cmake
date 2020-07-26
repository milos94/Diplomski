function(enable_doxygen)
    option(ENABLE_DOXYGEN "Enable doxygen doc builds of source" ON)
    if(ENABLE_DOXYGEN)
        set(DOXYGEN_CALLER_GRAPH YES)
        set(DOXYGEN_CALL_GRAPH YES)
        set(DOXYGEN_EXTRACT_ALL YES)
        find_package(Doxygen REQUIRED dot OPTIONAL_COMPONENTS mscgen dia)
        doxygen_add_docs(doxygen ${PROJECT_SOURCE_DIR})
    endif()
endfunction()