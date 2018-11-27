cmake_minimum_required(VERSION 3.12)
project(CircutRunners)

set(CMAKE_CXX_STANDARD 17)

add_executable(CircutRunners main.cpp Renderer.cpp Renderer.h GameObject.cpp GameObject.h Scene.cpp Scene.h ObjectPart.cpp ObjectPart.h Physics.cpp Physics.h)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})


find_package(Boost COMPONENTS system filesystem REQUIRED)
target_link_libraries(${PROJECT_NAME} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})