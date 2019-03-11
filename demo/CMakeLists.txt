cmake_minimum_required (VERSION 3.5.0 FATAL_ERROR)
project (demo)
set (CMAKE_INCLUDE_CURRENT_DIR on)

add_executable (${PROJECT_NAME} 
    src/ext/Ext.cpp
    src/ext/Ext.h
    src/ext/Type.cpp
    src/ext/Type.h
    src/ext/ValueChoice.cpp
    src/ext/ValueChoice.h
    src/host/Header.cpp
    src/host/Header.h
    src/host/Map.h

    src/main.cpp
)

set_target_properties (${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS NO
    )

target_include_directories(${PROJECT_NAME} 
PUBLIC
    src
)

target_link_libraries (${PROJECT_NAME} LINK_PUBLIC ZserioCppRuntime)
