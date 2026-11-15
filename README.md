# ase-json

**Design:** DSGN_016 (AEC//SRLZTN, AEC//PARSERS)

[![Layer](https://img.shields.io/badge/Layer-0%20Foundation-blue.svg)]()
[![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)]()
[![Header Only](https://img.shields.io/badge/Header-Only-green.svg)]()

> Foundation layer JSON utilities wrapping nlohmann/json for engine-wide operations

Part of [ASE - Antares Simulation Engine](../../..)

## Overview

The ase-json module provides a thin, header-only wrapper around nlohmann/json for standardized JSON operations across the entire engine. As a Layer 0 foundation library, it has no ASE dependencies and can be used by all higher layers for configuration loading, serialization, and data interchange. The wrapper standardizes JSON include paths and namespace usage so that all ASE modules reference JSON functionality through a single header rather than directly including nlohmann headers, enabling future replacement of the underlying JSON library without touching module code. It provides the foundation for Hub value serialization (ase-serial), configuration file loading (ase-config), codegen pipeline data (ase-codegen), and network protocol encoding. Every module that reads JSON configuration files, serializes component data for network transmission, or processes codegen output depends on this library transitively. The wrapper is intentionally minimal — it re-exports nlohmann/json's API rather than abstracting it, keeping the familiar nlohmann interface while centralizing the dependency management.

## Dependencies

### External
- **nlohmann/json** - JSON parsing and serialization

### Internal
- None (Layer 0 - Foundation)

## License

Copyright (c) Jan Ohlmann. All rights reserved.
Licensed to ANTARES SIMULACAO LTDA (CNPJ 69.363.366/0001-21) under ASE-JAN-LTDA-2026-10-16-1.0.

This repository is released under the Antares Simulation Engine and ADG License Agreement
**ASE-ADG-LIC-2026-10-16-1.0** ([LICENSE.md](LICENSE.md)) and the ADG Project Participation
Agreement **ASE-ADG-PJV-2026-10-16-1.0** ([PJV.md](PJV.md)). Contribution workflow: [CONTRIBUTING.md](CONTRIBUTING.md).

Translations: [DE LIC](license/de/LIC_ASE_ADG_DE.md) · [DE PJV](license/de/PJV_ASE_ADG_DE.md) ·
[PT LIC](license/pt/LIC_ASE_ADG_PT.md) · [PT PJV](license/pt/PJV_ASE_ADG_PT.md)

SPDX-License-Identifier: LicenseRef-ASE-LIC
