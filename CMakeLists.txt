cmake_minimum_required(VERSION 3.5)
project(EmineUdpSockets)

set(CMAKE_C_STANDARD 11)

set(CLIENT_SOURCE_FILES client/client.c)
add_executable(client ${CLIENT_SOURCE_FILES})

set(SERVER_SOURCE_FILES server/server.c)
add_executable(server ${SERVER_SOURCE_FILES})
