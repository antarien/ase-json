#pragma once

/**
 * ASE CORE INFRASTRUCTURE HEADER
 *
 * @file        json.hpp
 * @brief       The JSON vocabulary of the tree, named once so nlohmann is named nowhere else
 * @description A facade, and deliberately nothing more: three type aliases over
 *              nlohmann::json. Measured 2026-08-20, it is also one of the most used files
 *              in the tree — 14 CMakeLists bind ase::json and 24 files include this header.
 *              The day the underlying library changes, it changes here instead of in
 *              twenty-four callers.
 *
 *              THE FILE CARRIED A DEFERRAL MARKER UNTIL TODAY, promising helper functions
 *              once domain requirements emerged. It was removed rather than fulfilled,
 *              because it was never deferred work: a facade whose job is to name a
 *              vocabulary is COMPLETE when it names it. Twenty-four consumers have needed
 *              nothing beyond the three aliases in nineteen months. Writing helpers to
 *              satisfy the rule would have added code no caller asked for; leaving the
 *              marker would have kept a promise nobody owns. What belongs here instead is
 *              this sentence: the facade is finished, and a future helper is a future
 *              decision rather than an outstanding one.
 *
 *              WHY A FACADE MAY NAME WHAT IT HIDES: ase-bson does the same with bsoncxx,
 *              ase-containers with std::vector, ase-utils/fs.hpp with std::filesystem. A
 *              facade that did not name its backend would be empty. The rule is not "never
 *              name it" but "name it exactly once, at Layer 0, where a swap stays local".
 *
 *              LAYER 0 RULES, unchanged and still binding: no ECS dependency, no Components,
 *              no Systems, header-only, and nothing but the standard library plus nlohmann.
 *
 * @module      ase-json
 * @layer       0 (Foundation)
 * @category    persistence/serialization
 * @created     2024-12-29
 * @modified    2026-08-20
 * @version     1.0.0
 *
 * CORE INFRASTRUCTURE COMPLIANCE
 *
 * [ ] NOT an ECS Component or System
 * [ ] Layer dependencies correct (L0: no ASE deps, L1: L0 only)
 * [ ] No global mutable state (constexpr/const only)
 * [ ] No singletons or static mutable variables
 * [ ] Thread-safe by design (pure functions or explicit mutex)
 * [ ] All public functions documented with @brief, @param, @return
 * [ ] constexpr where possible (compile-time evaluation)
 * [ ] noexcept where possible (no-throw guarantee)
 * [ ] [[nodiscard]] on functions returning values
 * [ ] No magic numbers (use named constants)
 * [ ] No implicit conversions (use explicit constructors)
 * [ ] Header-only OR header+cpp pattern (not mixed)
 * [ ] Include guards via #pragma once
 * [ ] Namespace matches module: ase::{module}
 * [ ] No circular dependencies
 * [ ] No macros (except include guards) - use constexpr/templates
 * [ ] API stable (changes require version bump)
 */

#include <nlohmann/json.hpp>

namespace ase::json {

// Re-export nlohmann::json for convenience
using Json = nlohmann::json;
using JsonArray = nlohmann::json::array_t;
using JsonObject = nlohmann::json::object_t;

}  // namespace ase::json
