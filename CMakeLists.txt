cmake_minimum_required(VERSION 3.20)
project(ase-json VERSION 0.1.0 LANGUAGES CXX)

#[[
ASE FOUNDATION BUILD CONFIGURATION

@file        CMakeLists.txt
@brief       Build configuration for ase-json
@description JSON utilities - Foundation layer wrapper for nlohmann/json.
             Header-only library for JSON operations.

@module      ase-json
@layer       0 (Foundation)
@created     2025-01-01
@modified    2025-01-30
@version     1.0.0

CMAKE MODULE COMPLIANCE

[ ] cmake_minimum_required(VERSION 3.20) as FIRST line
[ ] project() with VERSION and LANGUAGES CXX
[ ] message(STATUS) for configuration output
[ ] add_library() with INTERFACE for header-only
[ ] add_library(ase::{module} ALIAS ...) for namespace
[ ] target_include_directories() with INTERFACE and generator expressions
[ ] target_compile_features() with cxx_std_20
[ ] target_link_libraries() with nlohmann_json (Layer 0 allowed external)
[ ] include(GNUInstallDirs) for installation
[ ] install(DIRECTORY include/ ...) for headers
]]

message(STATUS "Configuring ${PROJECT_NAME} v${PROJECT_VERSION}")

#[[
HEADER-ONLY LIBRARY
JSON utilities wrapping nlohmann/json for ASE conventions.
]]
add_library(${PROJECT_NAME} INTERFACE)
add_library(ase::json ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

target_link_libraries(${PROJECT_NAME}
    INTERFACE
        nlohmann_json::nlohmann_json
)
#[[ VERBOTEN: No ASE dependencies in Layer 0! Only external libs allowed! ]]

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-targets
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
