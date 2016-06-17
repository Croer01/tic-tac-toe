cmake_minimum_required(VERSION 3.5)
project(sdl_hello_world)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static")
set(SOURCE_FILES src/main.cpp src/core/Texture.cpp src/core/Texture.h src/game/TableBoard.cpp src/game/TableBoard.h src/game/GameTicTacToe.cpp src/game/GameTicTacToe.h src/core/Game.cpp src/core/Game.h src/core/InputManager.cpp src/core/InputManager.h src/game/Cell.cpp src/game/Cell.h src/core/ImageManager.cpp src/core/ImageManager.h)

#region sdl2 library
set(SDL2_ROUTE C:/vs_dev_lib)

include_directories(${SDL2_ROUTE}/include)
link_directories(${SDL2_ROUTE}/lib/x86)
#endregion

#game executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#Link shared libraries
target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image)

#Copy files to runtime directory
file(GLOB SDL2_DLLS "${SDL2_ROUTE}/lib/x86/*.dll")
file(COPY ${SDL2_DLLS} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

file(GLOB IMAGES "${CMAKE_CURRENT_SOURCE_DIR}/assets/images/*.*")
file(COPY ${IMAGES} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets/images)