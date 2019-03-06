cmake_minimum_required (VERSION 3.2 FATAL_ERROR)
project (zserio-template)

add_subdirectory (3rd-party/zserio-runtime)
set_property (TARGET ZserioCppRuntime PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property (TARGET ZserioCppRuntime PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_subdirectory (demo)

