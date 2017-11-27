cmake_minimum_required(VERSION 2.6.0)

project(StringCalculator)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -Wall -std=c89")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O1 -g -Wall -std=c89")

# used for ycm
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(StringCalculator Main.c Str.c Utils.c)
