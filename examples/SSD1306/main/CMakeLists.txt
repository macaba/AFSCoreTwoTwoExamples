# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
#cmake_minimum_required(VERSION 3.5)

#include($ENV{IDF_PATH}/tools/cmake/project.cmake)
#project(sine)

idf_component_register(SRCS main.cpp fonts.c ssd1306.c xi2c.c
                    INCLUDE_DIRS ".")

#set(COMPONENT_SRCS "main.cpp")
#set(COMPONENT_ADD_INCLUDEDIRS ".")

#register_component()