## 1. Summary
ItzEngine is a game engine that i create to challenge myself.

## 2. Table of Contents
- [1. Summary](#1-summary)
- [2. Table of Contents](#2-table-of-contents)
- [3. Requirements](#3-requirements)
- [4. Adding ItzEngine to your project](#4-adding-itzengine-to-your-project)
- [5. Example Project](#5-example-project)
## 3. Requirements
- [CMake](https://cmake.org/) >= 3.24
- [python](https://www.python.org/downloads/)
- [jinja2](https://pypi.org/project/Jinja2/)

## 4. Adding ItzEngine to your project
```
git clone https://github.com/Itzerr/ItzEngine --recurse-submodules
```
then inside your CMakeLists:
```
add_subdirectory(ItzEngine)
target_link_libraries(YourTarget ItzEngine)
```

## 5. Example Project
Check 'app' directory inside ItzEngine