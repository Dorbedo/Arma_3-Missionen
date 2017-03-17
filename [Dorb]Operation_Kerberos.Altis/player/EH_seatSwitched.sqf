/*
 *  Author: Dorbedo
 *
 *  Description:
 *      adds the hit Eventhandler
 *
 */
#include "script_component.hpp"

If (hasInterface) then {
    ["Air", "seatSwitched", {
        _this call FUNC(onseatswitched);
    },true,[],true] call CBA_fnc_addClassEventHandler;
};
