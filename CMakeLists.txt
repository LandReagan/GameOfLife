cmake_minimum_required(VERSION 3.10)

project(GameOfLife LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

set(GOL_LIB_SOURCES 
    src/Engine.cpp 
    src/GameOfLife.cpp 
    src/Map.cpp 
    src/Rule.cpp 
    src/UI.cpp
    src/GolWindow.cpp)
    
set(GOL_LIB_HEADERS 
    include/constants.hpp 
    include/Engine.hpp 
    include/GameOfLife.hpp
    include/Map.hpp
    include/Cell.hpp
    include/Rule.hpp
    include/UI.hpp
    include/GolWindow.hpp
    include/utils_debug.hpp)
    
set(GOL_TESTS_SOURCES
    tests/launcher.cpp
    tests/Rule_tests.cpp
    tests/Cell_tests.cpp
    tests/Map_tests.cpp
    tests/Engine_tests.cpp)

add_library(GOL_lib ${GOL_LIB_HEADERS} ${GOL_LIB_SOURCES})
target_include_directories(GOL_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add our cmake_modules sub folder in the CMAKE_MODULE_PATH variable
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
# Find SFML package from the system
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)

# Main App
add_executable(GameOfLifeApp src/main.cpp)
# Our library
target_link_libraries(GameOfLifeApp GOL_lib)
# SFML library
target_link_libraries(GameOfLifeApp ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

# Unit tests
add_executable(GameOfLifeTests ${GOL_TESTS_SOURCES})
# Our library
target_link_libraries(GameOfLifeTests GOL_lib)
# Catch2 unit testing library
target_include_directories(GameOfLifeTests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/extern/Catch2)
