cmake_minimum_required(VERSION 3.16)
project(Breakout)

set(
    BREAKOUT_SOURCE_FILES
    src/Breakout.cpp
    src/EventLoop.cpp
    src/factory/DynamicBodyFactory.cpp
    src/factory/StaticBodyFactory.cpp
    src/GameLoop.cpp
    src/GameWindow.cpp
    src/Initialize.cpp
    src/MainContrainer.cpp
    src/resource/Texture.cpp
    src/screen/DemoScreen.cpp
    src/screen/Screen.cpp
    src/screen/ScreenManager.cpp
    src/SpaceConverter.cpp
    src/Surface.cpp
    src/system/Systems.cpp
    src/TextureRepository.cpp
    src/tinyxml2/tinyxml2.cpp
    src/Utils.cpp
)

set(
    BREAKOUT_HEADER_FILES
    include/component/Components.h
    include/EventLoop.h
    include/factory/DynamicBodyFactory.h
    include/factory/StaticBodyFactory.h
    include/GameLoop.h
    include/GameWindow.h
    include/Initialize.h
    include/MainContrainer.h
    include/resource/Resource.h
    include/resource/Texture.h
    include/screen/DemoScreen.h
    include/screen/Screen.h
    include/screen/ScreenManager.h
    include/SpaceConverter.h
    include/Surface.h
    include/system/Systems.h
    include/TextureRepository.h
    include/tinyxml2/tinyxml2.h
    include/Utils.h
)

add_executable(
    Breakout
    ${BREAKOUT_SOURCE_FILES}
    ${BREAKOUT_HEADER_FILES}
)

target_include_directories(
    Breakout
    PUBLIC ${CMAKE_SOURCE_DIR}/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/include/component/
    PUBLIC ${CMAKE_SOURCE_DIR}/include/entt/
    PUBLIC ${CMAKE_SOURCE_DIR}/include/factory/
    PUBLIC ${CMAKE_SOURCE_DIR}/include/resource/
    PUBLIC ${CMAKE_SOURCE_DIR}/include/screen/
    PUBLIC ${CMAKE_SOURCE_DIR}/include/system/
    PUBLIC ${CMAKE_SOURCE_DIR}/include/tinyxml2/
)

set_target_properties(
    Breakout PROPERTIES
    CXX_STANDARD 17
)

add_subdirectory(box2d)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/sdl2-cmake-modules/")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

target_link_libraries(
    Breakout
    PUBLIC box2d
    PUBLIC SDL2::Main
    PUBLIC SDL2::Image
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" PREFIX "src" FILES ${BREAKOUT_SOURCE_FILES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/include" PREFIX "include" FILES ${BREAKOUT_HEADER_FILES})

if (WIN32) 
    add_custom_command(
        TARGET Breakout POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/SDL2/SDL2-2.0.10/lib/x64/SDL2.dll ${CMAKE_BINARY_DIR}/$<CONFIGURATION>/SDL2.dll 
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/SDL2/SDL2_Image-2.0.5/lib/x64/SDL2_Image.dll ${CMAKE_BINARY_DIR}/$<CONFIGURATION>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/SDL2/SDL2_Image-2.0.5/lib/x64/zlib1.dll ${CMAKE_BINARY_DIR}/$<CONFIGURATION>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/SDL2/SDL2_Image-2.0.5/lib/x64/libpng16-16.dll ${CMAKE_BINARY_DIR}/$<CONFIGURATION>
    )
endif ()