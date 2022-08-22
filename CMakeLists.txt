cmake_minimum_required(VERSION 3.24)

project(
  ItzEngine
  VERSION 1.0.0
  LANGUAGES CXX
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ItzEngineApp)
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
option(ITZENGINE_BUILD_APP "Build ItzEngine test app" ON)

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")



file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp src/*.h)
add_library(ItzEngine ${sources})

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(ItzEngine PUBLIC ITZENGINE_STATIC)
endif()

target_include_directories(ItzEngine PUBLIC src)
target_compile_features(ItzEngine PUBLIC cxx_std_20)
target_compile_definitions(
  ItzEngine
  PRIVATE ITZENGINE_EXPORT
  PUBLIC SDL_MAIN_HANDLED
)

set(SDL2_DISABLE_SDL2MAIN ON CACHE INTERNAL "")
set(SDL_TEST OFF CACHE INTERNAL "")
add_subdirectory(vendor/sdl2)
target_link_libraries(ItzEngine PUBLIC SDL2::SDL2)
set_target_properties(SDL2 sdl_headers_copy ItzEngine PROPERTIES FOLDER "Dependencies/SDL2")

# target_include_directories(ItzEngine PUBLIC "${SDL2_SOURCE_DIR}/include")

find_package(OpenGL REQUIRED)
target_link_libraries(ItzEngine PUBLIC OpenGL::GL)

add_subdirectory(vendor/glad2/cmake)
glad_add_library(glad2 API gl:core=4.6)
target_link_libraries(ItzEngine PUBLIC glad2)

add_subdirectory(vendor/glm)
target_link_libraries(ItzEngine PUBLIC glm)

if(TARGET glm_shared)
  set_target_properties(glm_shared PROPERTIES FOLDER "Dependencies")
endif()
if(TARGET glm_static)
  set_target_properties(glm_static PROPERTIES FOLDER "Dependencies")
endif()

set_target_properties(glad2 ItzEngine PROPERTIES FOLDER "Dependencies")
set_target_properties(uninstall PROPERTIES FOLDER "CMakePredefinedTargets")
set_target_properties(glad2 PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)

if(ITZENGINE_BUILD_APP)
  add_subdirectory(app)
endif()