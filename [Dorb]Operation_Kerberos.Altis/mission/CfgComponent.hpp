/*
 *  Author: Dorbedo
 *
 *  Description:
 *      the config of the component
 *
 */
#define CBA_OFF
#include "script_component.hpp"

class DOUBLES(CfgComponent,ADDON) {
    class clientpostinit {server = 0;};
    class serverpostinit {client = 0;};
    class preinit {};
    class serverkilled {client=0;};
    class dependencies {
        CfgPatches[] = {};
        CfgComponents[] = {"spawn"};
    };
    class features {
        mainmissions = CSTRING(FEATURES_MAINMISSIONS);
        sidemissions = CSTRING(FEATURES_SIDEMISSIONS);
    };
};
#include "config\CfgTaskTypes.hpp"
#include "config\CfgTaskEnhancements.hpp"
#include "config\CfgTaskDescriptions.hpp"
#include "config\missions_config.hpp"
#include "CfgDebriefing.hpp"
