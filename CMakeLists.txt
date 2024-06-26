cmake_minimum_required(VERSION 3.28)
project(space-eaters CXX)

# C language version
set(CMAKE_C_STANDARD 99)

# set up the source directory for the project
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

# don't build the supplied examples
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# include raylib
add_subdirectory(vendor/raylib)

# get all the source files
file(GLOB_RECURSE SOURCE_LIST "./src/*.c" "./src/*.h")

# create the executable
add_executable(${PROJECT_NAME} ${SOURCE_LIST})

# link raylib with the project
target_link_libraries(${PROJECT_NAME} raylib)

# add the source directory as an include
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

# web configurations
if (${PLATFORM} STREQUAL "Web")
    # tell emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif ()

# checks if osx and links appropriate frameworks (only required on macos)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif ()

# copy over the assets directory into the output directory
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
        COMMENT "Copying assets into the build directory"
)