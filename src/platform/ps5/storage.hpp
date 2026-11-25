// ProsperoPuzzles - Filesystem access and where the app keeps its files.
// Copyright (C) 2026 BlackBearReloaded
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <string>

namespace ppz::ps5
{

// The title's readable app folder and writable sandbox data directory.
struct Storage
{
    std::string version;
    std::string app_dir = "/app0";
    std::string data_root = "/download0/prosperopuzzles";
};

// Reads the content version from the packaged application metadata.
Storage prepare_storage();

} // namespace ppz::ps5
