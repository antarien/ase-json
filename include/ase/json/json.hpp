#pragma once

/**
 * =============================================================================
 * ASE JSON - Foundation Layer JSON Utilities
 * =============================================================================
 *
 * @file        json.hpp
 * @brief       Main include for ase-json module
 * @description Foundation layer wrapper/utilities for JSON operations
 *
 * -----------------------------------------------------------------------------
 * META
 * -----------------------------------------------------------------------------
 * @module      ase-json
 * @layer       0 (Foundation)
 * @created     2024-12-29
 * @modified    2024-12-29
 * @version     1.0.0
 *
 * -----------------------------------------------------------------------------
 * LAYER 0 RULES
 * -----------------------------------------------------------------------------
 * - NO ECS dependency (no ase-ecs include)
 * - NO Components, NO Systems
 * - Only std library + nlohmann/json allowed
 * - Header-only library
 *
 * =============================================================================
 */

#include <nlohmann/json.hpp>

namespace ase::json {

// Re-export nlohmann::json for convenience
using Json = nlohmann::json;
using JsonArray = nlohmann::json::array_t;
using JsonObject = nlohmann::json::object_t;

// TODO: Add utility functions as domain requirements emerge

}  // namespace ase::json
