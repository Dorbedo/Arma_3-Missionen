/*
 *  Author: Dorbedo
 *
 *  Description:
 *      the config of the component
 *
 */
#define CBA_OFF
#include "script_component.hpp"

class ADDON {
    Events[] = {};
    class dependencies {
        CfgPatches = {'ace_main'};
        CfgComponent = {};
    };
};

#include "ace_settings.hpp"
