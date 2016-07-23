cmake_minimum_required(VERSION 3.5)
project(sdl_hello_world)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static")
set(SOURCE_FILES src/main.cpp src/core/Texture.cpp src/core/Texture.h src/game/TableBoard.cpp src/game/TableBoard.h src/game/SceneTicTacToe.cpp src/game/SceneTicTacToe.h src/core/Game.cpp src/core/Game.h src/core/InputManager.cpp src/core/InputManager.h src/game/Cell.cpp src/game/Cell.h src/core/ImageManager.cpp src/core/ImageManager.h src/core/Scene.cpp src/core/Scene.h src/game/SceneMainMenu.cpp src/game/SceneMainMenu.h src/ui/UIElement.h src/ui/Text.cpp src/ui/Text.h src/ui/UIElement.cpp src/core/SceneManager.cpp src/core/SceneManager.h)

#region sdl2 library
set(SDL2_ROUTE C:/vs_dev_lib)

include_directories(${SDL2_ROUTE}/include)
link_directories(${SDL2_ROUTE}/lib/x86)
#endregion

#game executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#Link shared libraries
target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image SDL2_ttf)

#Copy files to runtime directory
file(GLOB SDL2_DLLS "${SDL2_ROUTE}/lib/x86/*.dll")
file(COPY ${SDL2_DLLS} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

#images
file(GLOB IMAGES "${CMAKE_CURRENT_SOURCE_DIR}/assets/images/*.*")
file(COPY ${IMAGES} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets/images)

#fonts
file(GLOB IMAGES "${CMAKE_CURRENT_SOURCE_DIR}/assets/fonts/*.*")
file(COPY ${IMAGES} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets/fonts)