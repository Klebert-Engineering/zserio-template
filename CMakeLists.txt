cmake_minimum_required (VERSION 3.2 FATAL_ERROR)
project (zserio-template)



add_subdirectory (runtime)
set_property (TARGET ZserioCppRuntime PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property (TARGET ZserioCppRuntime PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS ON)

file (GLOB_RECURSE SOURCES_HOST_LIB "${CMAKE_CURRENT_SOURCE_DIR}/gen/host/*.cpp")
file (GLOB_RECURSE HEADERS_HOST_LIB "${CMAKE_CURRENT_SOURCE_DIR}/gen/host/*.h")

	add_library (hostlib STATIC
		${SOURCES_HOST_LIB}
		${HEADERS_HOST_LIB}
		)

	target_include_directories (hostlib PUBLIC gen)
	target_link_libraries (hostlib ZserioCppRuntime)
	set_property (TARGET hostlib PROPERTY POSITION_INDEPENDENT_CODE ON)
	set_property (TARGET hostlib PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS ON)
	

  file (GLOB_RECURSE SOURCES_EXT_LIB "${CMAKE_CURRENT_SOURCE_DIR}/gen/ext/*.cpp")
  file (GLOB_RECURSE HEADERS_EXT_LIB "${CMAKE_CURRENT_SOURCE_DIR}/gen/ext/*.h")

  	add_library (extlib STATIC
  		${SOURCES_EXT_LIB}
  		${HEADERS_EXT_LIB}
  		)

  	target_include_directories (extlib PUBLIC gen)
  	target_link_libraries (extlib ZserioCppRuntime)
  	set_property (TARGET extlib PROPERTY POSITION_INDEPENDENT_CODE ON)
	set_property (TARGET extlib PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS ON)

	
	add_executable (zserio-template
		src/main.cpp
	)

	target_link_libraries (zserio-template hostlib extlib)
















