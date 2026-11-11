class SC_Log
{
    static const string PREFIX = "[PVPPVECoreZ]";

    static void Info(string moduleName, string message)
    {
        Print(PREFIX + "[" + moduleName + "][INFO] " + message);
    }

    static void Warning(string moduleName, string message)
    {
        Print(PREFIX + "[" + moduleName + "][WARNING] " + message);
    }

    static void Error(string moduleName, string message)
    {
        Print(PREFIX + "[" + moduleName + "][ERROR] " + message);
    }

    static void Debug(string moduleName, string message)
    {
        SC_Config config = SC_ConfigManager.GetConfig();

        if (!config)
            return;

        if (!config.Debug.Enabled)
            return;

        Print(PREFIX + "[" + moduleName + "][DEBUG] " + message);
    }
};
