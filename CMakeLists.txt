cmake_minimum_required(VERSION 3.28)
project(space-eaters CXX)

# C++ language version
set(CMAKE_CXX_STANDARD 17)

# set up the source directory for the project
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

# don't build the supplied examples
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# include raylib
add_subdirectory(vendor/raylib)

# create the executable
add_executable(
        ${PROJECT_NAME}
        src/main.cpp src/sprite/spritesheet.h src/sprite/spritesheet.cpp
        src/screen/screen.cpp src/screen/screen.h
        src/screen/menu.cpp src/screen/menu.h
        src/screen/game.cpp src/screen/game.h
        src/screen/leaderboard.cpp src/screen/leaderboard.h
        src/entity/entity.cpp src/entity/entity.h
        src/entity/component/controller.cpp src/entity/component/controller.h
        src/entity/component/component.h
        src/sprite/sprite.cpp
        src/sprite/sprite.h
        src/entity/component/render.cpp
        src/entity/component/render.h
)

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