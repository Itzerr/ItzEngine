file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp src/*.h)

add_executable(
  ItzEngineApp
  src/main.cpp
)

target_link_libraries(ItzEngineApp ItzEngine)