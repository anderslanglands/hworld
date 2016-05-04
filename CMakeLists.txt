project(helloworld)

add_executable(hwserver hwserver.cpp)
target_link_libraries(hwserver zmq)
add_executable(hwclient hwclient.cpp)
target_link_libraries(hwclient zmq)
