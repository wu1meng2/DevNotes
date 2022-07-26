https://medium.com/heuristics/c-application-development-part-1-project-structure-454b00f9eddc
## Project structure
```bash
Project_name
  |
  |---- CMakeLists.txt
  |
  |---- include
  |       |
  |       |---- Project_name
  |                 |
  |                 |---- public_header(s).h
  |
  ---- src
  |     |
  |     |---- private_header(s).h
  |     |
  |     |---- code(s).cpp
  |
  |
  |---- libs
  |       |
  |       |---- A
  |       |
  |       |---- B
  |
  |
  |---- tests
```

#### `include/`
Modern practice suggests that include directory must strictly contain headers that need to be *exposed publicly*. Use the name of the project as the folder name within `include/` give a sense of specification when someone tries to use your library.

#### `src/`
This directory contains all the source code and the header files that are for internal use only.

#### `libs/`
This directory consists all the third party libraries that are needed.

#### `test/`
Unit tests are here.

## cmake
1. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `make`

## `CMakeLists.txt`
Major sections
1. Flags
2. Files
3. Include
4. Targets
5. External libraries
6. Unit Testing

```bash
# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project( sample_cmake )

# flags

# files

# include
include_directories( ./include ./src ./libs/Logger/include ./libs/Randomize/include )

# target
add_executable( binary ./src/main.cpp ./src/game_engine.cpp ./src/game_interface.cpp )

# external libs (liblogger.a)
add_subdirectory( ./libs/Logger )
target_link_libraries( binary logger )

# add_subdirectory( ./libs/Randomize )
# target_link_libraries( binary randomize )

## using a static library name librandomize.a
add_library(randomize STATIC IMPORTED)
set_property(TARGET randomize PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/Randomize/librandomize.a)
target_link_libraries( binary randomize )
```