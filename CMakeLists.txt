cmake_minimum_required(VERSION 3.20)

project(ase-json
    VERSION 0.1.0
    DESCRIPTION "ASE JSON Utilities - Foundation Layer wrapper/utilities for JSON"
    LANGUAGES CXX
)

# ==============================================================================
# ase-json - JSON utilities
#
# Layer 0 Foundation (NO ECS dependency!)
# ==============================================================================

message(STATUS "Configuring ${PROJECT_NAME} v${PROJECT_VERSION}")

# Header-only library
add_library(ase-json INTERFACE)
add_library(ase::json ALIAS ase-json)

target_include_directories(ase-json
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(ase-json INTERFACE cxx_std_20)

# ==============================================================================
# Dependencies (Layer 0: nur std erlaubt, optional nlohmann/json)
# ==============================================================================

target_link_libraries(ase-json
    INTERFACE
        nlohmann_json::nlohmann_json
)

# ==============================================================================
# Installation
# ==============================================================================

install(TARGETS ase-json
    EXPORT ase-json-targets
)

install(DIRECTORY include/ase
    DESTINATION include
)
