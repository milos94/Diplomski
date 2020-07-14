set(executable_name kerberized_server)

set(headres
)

set(sources 
   main.cpp
)

set(private_libraries
)

set(public_libraries
)

set(interface_libraries
)

add_executable(${executable_name} ${headers} ${sources})

target_link_libraries(${executable_name} PUBLIC ${public_libraries}
                                         PRIVATE ${private_libraries}
                                         INTERFACE ${interface_libraries})