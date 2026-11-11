modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();

        SC_Core.Initialize();
        SC_Log.Info("Mission", "MissionServer.OnInit reached.");

        if (SC_ConfigManager.Load())
        {
            SC_ModuleManager.Initialize();
        }
        else
        {
            SC_Log.Error("Mission", "Startup stopped because the main configuration could not be loaded.");
        }
    }
};
