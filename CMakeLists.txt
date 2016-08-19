cmake_minimum_required(VERSION 3.5)
project(tic_tac_toe)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static")
set(SOURCE_FILES src/main.cpp src/components/ui/Image.cpp src/components/ui/Image.h src/components/Font.cpp src/components/Font.h src/game/GoToScene.cpp src/game/GoToScene.h src/core/Texture.cpp src/core/Texture.h src/game/TableBoard.cpp src/game/TableBoard.h src/core/Game.cpp src/core/Game.h src/services/implementations/KeyboardInputServiceImpl.cpp src/services/implementations/KeyboardInputServiceImpl.h src/game/Cell.cpp src/game/Cell.h src/services/implementations/SDLImageServiceImpl.cpp src/services/implementations/SDLImageServiceImpl.h src/core/Scene.cpp src/core/Scene.h src/components/ui/Text.cpp src/components/ui/Text.h src/services/implementations/SceneServiceImpl.cpp src/services/implementations/SceneServiceImpl.h src/core/Logger.cpp src/core/Logger.h src/services/GameServices.cpp src/services/GameServices.h src/services/interfaces/ImageService.h src/services/interfaces/InputService.h src/services/null-services/NullImageService.h src/services/null-services/NullInputService.h src/elements/Element.cpp src/elements/Element.h src/components/Component.cpp src/components/Component.h src/core/Object.h src/components/Transform2D.cpp src/components/Transform2D.h src/elements/WorldElement.cpp src/elements/WorldElement.h src/serialization/Serializer.h src/core/Object.cpp src/components/ui/Button.cpp src/components/ui/Button.h src/services/implementations/SDLCursorServiceImpl.cpp src/services/implementations/SDLCursorServiceImpl.h src/services/null-services/NullCursorService.h src/services/interfaces/CursorService.h src/serialization/SerializerBase.h src/serialization/SerializationConfig.h src/serialization/Metadata.h src/serialization/Metadata.cpp src/serialization/Serializer.cpp src/serialization/Register.cpp src/serialization/Register.h src/services/interfaces/SceneService.h src/services/null-services/NullSceneService.h src/services/interfaces/ScreenService.h src/services/implementations/ScreenServiceImpl.cpp src/services/implementations/ScreenServiceImpl.h src/services/null-services/NullScreenService.h)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DENABLE_DEBUG_MACRO")



#region sdl2 library
set(SDL2_ROOT C:/cpp_libraries/SDL2)

include_directories(${SDL2_ROOT}/include)

set(SDL2_COMPONENTS SDL2main SDL2 SDL2_image SDL2_ttf)

foreach (LIBRARY ${SDL2_COMPONENTS})
    find_library(SDL2_LIBRARY-${LIBRARY} ${LIBRARY} PATHS ${SDL2_ROOT}/lib/x86 NO_DEFAULT_PATH)
    LIST(APPEND SDL2_LIBRARIES ${SDL2_LIBRARY-${LIBRARY}})

endforeach (LIBRARY)
#endregion



#region boost libraries
set(BOOST_ROOT C:/cpp_libraries/boost_installation)

set(Boost_USE_STATIC_LIBS OFF) # enable dynamic linking
set(Boost_USE_MULTITHREAD ON)  # enable multithreading
find_package(Boost 1.61.0 COMPONENTS system date_time filesystem REQUIRED)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif ()
#endregion



#region YAML-cpp
set(YAML-CPP_ROOT C:/cpp_libraries/yaml-cpp)
include_directories(${YAML-CPP_ROOT}/include)
set(YAML-CPP_LIBRARIES ${YAML-CPP_ROOT}/build/libyaml-cpp.a)
#endregion



#game executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#Link shared libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${YAML-CPP_LIBRARIES})

#Copy files to runtime directory
file(GLOB SDL2_DLLS "${SDL2_ROOT}/lib/x86/*.dll")
file(COPY ${SDL2_DLLS} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

#images
file(GLOB IMAGES "${CMAKE_CURRENT_SOURCE_DIR}/assets/images/*.*")
file(COPY ${IMAGES} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets/images)

#fonts
file(GLOB FONTS "${CMAKE_CURRENT_SOURCE_DIR}/assets/fonts/*.*")
file(COPY ${FONTS} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets/fonts)

#data
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Data" DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
