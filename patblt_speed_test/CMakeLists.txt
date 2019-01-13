# CMakeList.txt : CMake project for speedTest, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.11)

include(GNUInstallDirs)


# define a variable of project name
set(projectName speedTest)

# define a project name
project (${projectName})

# set the project as the startup project
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${projectName})

# define variables by file GLOB
file(GLOB_RECURSE cppHeaders src/*.h)
file(GLOB_RECURSE cppSources src/*.cpp)

# Add source to this project's executable.
add_executable(${projectName} WIN32 ${cppHeaders} ${cppSources})

# add definitions
target_compile_definitions(${projectName} PUBLIC UNICODE _UNICODE)
