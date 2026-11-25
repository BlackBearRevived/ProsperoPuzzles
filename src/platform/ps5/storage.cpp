// ProsperoPuzzles - Filesystem access and where the app keeps its files.
// Copyright (C) 2026 BlackBearReloaded
// SPDX-License-Identifier: GPL-3.0-or-later

#include "platform/ps5/storage.hpp"

#include "core/save_file.hpp"
#include "core/version.hpp"

namespace ppz::ps5
{

Storage prepare_storage()
{
    Storage result;
    std::string param;
    if (save::read_file(result.app_dir + "/sce_sys/param.json", &param))
        result.version = content_version(param);
    return result;
}

} // namespace ppz::ps5
