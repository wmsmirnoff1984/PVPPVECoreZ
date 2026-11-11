class CfgPatches
{
    class SurvivalCore_Scripts
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Data",
            "DZ_Scripts"
        };
    };
};

class CfgMods
{
    class PVPPVECoreZ
    {
        dir = "PVPPVECoreZ";
        name = "PVPPVECoreZ";
        author = "PVPPVECoreZ Team";
        type = "mod";

        dependencies[] =
        {
            "Game",
            "World",
            "Mission"
        };

        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] =
                {
                    "PVPPVECoreZ/Scripts/3_Game"
                };
            };

            class worldScriptModule
            {
                value = "";
                files[] =
                {
                    "PVPPVECoreZ/Scripts/4_World"
                };
            };

            class missionScriptModule
            {
                value = "";
                files[] =
                {
                    "PVPPVECoreZ/Scripts/5_Mission"
                };
            };
        };
    };
};
