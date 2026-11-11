class SC_ModuleSettings
{
    bool Zones = true;
    bool Combat = true;
    bool Rewards = true;
    bool Economy = true;
    bool TerritoryControl = true;
    bool Crafting = true;
    bool Permissions = true;
    bool Items = true;
    bool Progression = false;
    bool Map = true;
};

class SC_DebugSettings
{
    bool Enabled = true;
    bool LogModuleLoading = true;
    bool LogZoneChecks = false;
    bool LogCombatEvents = true;
    bool LogEconomyEvents = true;
};

class SC_Config
{
    int Version = 1;
    bool Enabled = true;

    // Valid values: "PVP", "PVE", "ZONED"
    string ServerMode = "ZONED";

    ref SC_ModuleSettings Modules = new SC_ModuleSettings();
    ref SC_DebugSettings Debug = new SC_DebugSettings();

    void Validate()
    {
        if (ServerMode != "PVP" && ServerMode != "PVE" && ServerMode != "ZONED")
        {
            SC_Log.Warning("Config", "Unknown ServerMode '" + ServerMode + "'. Falling back to ZONED.");
            ServerMode = "ZONED";
        }

        if (Version < 1)
            Version = 1;
    }
};
