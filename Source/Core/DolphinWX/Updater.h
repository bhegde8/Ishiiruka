// Copyright 2015 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include <wx/thread.h>

#include "Common/CommonTypes.h"
#include "UICommon/AutoUpdate.h"

class Updater : public wxThread, public AutoUpdateChecker
{
public:
    Updater() = default;
    ~Updater() = default;
    void *Entry();
    
    void OnUpdateAvailable(const NewVersionInformation& info) override;
    bool CheckForUpdate();

private:
    bool m_update_available = false;
};
