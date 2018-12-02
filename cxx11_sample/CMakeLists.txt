# CMakeList.txt : CMake project for cxx11_sample, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.11)

include(GNUInstallDirs)

if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # CMake compile with /MT instead of /MD
  # https://stackoverflow.com/questions/14172856/cmake-compile-with-mt-instead-of-md
  #set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
  #set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif(NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")


# setup pre-compiled header
function(target_use_pre_compile_header projectName PreCompiledHeader PreCompiledHeaderSource)
  if (CMAKE_GENERATOR MATCHES "Visual Studio")
    #target_compile_options(${projectName} PRIVATE /Yu"${PreCompiledHeader}")
	#set_source_files_properties(${PreCompiledHeaderSource}
    #  PROPERTIES
    #    COMPILE_FLAGS /Yc"${PreCompiledHeader}"
    #)
  endif(CMAKE_GENERATOR MATCHES "Visual Studio")
endfunction(target_use_pre_compile_header)


# define a variable of project name
set(projectName cxx11_sample)

# define a project name
project (${projectName})

# set the project as the startup project
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${projectName})

# define variables by file GLOB
file(GLOB_RECURSE cppHeaders src/*.h)
file(GLOB_RECURSE cppSources src/*.cpp)

# Add source to this project's executable.
add_executable(${projectName} ${cppHeaders} ${cppSources})

# add definitions
target_compile_definitions(${projectName} PUBLIC _CONSOLE UNICODE _UNICODE)

# add pre-compiled header to executable.
target_use_pre_compile_header(${projectName} StdAfx.h src/StdAfx.cpp)

# add library modules
target_link_libraries(${projectName} Shlwapi.lib)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set_target_properties(${projectName}
    PROPERTIES LINK_FLAGS "-municode")
endif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
