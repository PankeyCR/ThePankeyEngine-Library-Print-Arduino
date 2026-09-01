cmake_minimum_required(VERSION 3.15)

project(ThePankeyEngine_Library_Print_Arduino)

if(NOT TARGET ThePankeyEngine_Library_Print_Arduino)

    add_library(ThePankeyEngine_Library_Print_Arduino INTERFACE)

    target_include_directories(
        ThePankeyEngine_Library_Print_Arduino
          INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}
    )

endif()
