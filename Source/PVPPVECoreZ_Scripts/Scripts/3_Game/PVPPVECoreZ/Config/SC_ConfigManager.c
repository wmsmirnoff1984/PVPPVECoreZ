class SC_ConfigManager
{
    protected static ref SC_Config s_Config;

    static const string CONFIG_DIRECTORY = "$profile:PVPPVECoreZ";
    static const string CONFIG_PATH = "$profile:PVPPVECoreZ/PVPPVECoreZ.json";

    static bool Load()
    {
        SC_Log.Info("Config", "Loading main configuration.");

        MakeDirectory(CONFIG_DIRECTORY);

        s_Config = new SC_Config();

        if (!FileExist(CONFIG_PATH))
        {
            s_Config.Validate();

            string saveError;
            if (!JsonFileLoader<SC_Config>.SaveFile(CONFIG_PATH, s_Config, saveError))
            {
                SC_Log.Error("Config", "Could not create default configuration: " + saveError);
                return false;
            }

            SC_Log.Warning("Config", "No configuration found. Created defaults: " + CONFIG_PATH);
            return true;
        }

        string loadError;
        if (!JsonFileLoader<SC_Config>.LoadFile(CONFIG_PATH, s_Config, loadError))
        {
            SC_Log.Error("Config", "Configuration load failed: " + loadError);
            return false;
        }

        s_Config.Validate();
        SC_Log.Info("Config", "Configuration loaded. ServerMode=" + s_Config.ServerMode);
        return true;
    }

    static SC_Config GetConfig()
    {
        return s_Config;
    }
};
