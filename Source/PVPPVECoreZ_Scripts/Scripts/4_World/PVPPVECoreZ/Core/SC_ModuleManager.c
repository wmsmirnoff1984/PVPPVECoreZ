class SC_ModuleManager
{
    static void Initialize()
    {
        SC_Config config = SC_ConfigManager.GetConfig();

        if (!config)
        {
            SC_Log.Error("Modules", "Cannot initialize modules: configuration is unavailable.");
            return;
        }

        if (!config.Enabled)
        {
            SC_Log.Warning("Modules", "PVPPVECoreZ is disabled in the main configuration.");
            return;
        }

        SC_Log.Info("Modules", "Starting enabled server modules.");

        if (config.Modules.Zones)
            SC_ZoneManager.Initialize();

        if (config.Modules.Combat)
            SC_CombatManager.Initialize();

        if (config.Modules.Rewards)
            SC_RewardManager.Initialize();

        if (config.Modules.Economy)
            SC_EconomyManager.Initialize();

        if (config.Modules.TerritoryControl)
            SC_TerritoryManager.Initialize();

        if (config.Modules.Crafting)
            SC_CraftingManager.Initialize();

        if (config.Modules.Permissions)
            SC_PermissionManager.Initialize();

        if (config.Modules.Items)
            SC_ItemManager.Initialize();

        if (config.Modules.Progression)
            SC_ProgressionManager.Initialize();

        SC_Log.Info("Modules", "Server module initialization pass completed.");
        SC_Log.Info("Modules", "Map/UI is reserved for the client-side mission layer.");
    }
};
