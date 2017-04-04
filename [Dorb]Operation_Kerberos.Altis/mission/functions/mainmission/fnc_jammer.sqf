/*
 *  Author: iJesuz
 *
 *  Description:
 *      init mission "jammer"
 *
 *  Parameter(s):
 *      0 : HASH        - mission hash
 *      1 : [OBJECT]    - mission target
 *
 *  Returns:
 *      -
 */
#include "script_component.hpp"

_this params ["_mission", "_targets"];

{
    [_x] call EFUNC(mod_acre,jammer_add);

    _x setVariable [QGVAR(isActive), true, true];
    _x addEventHandler ["Killed", LINKFUNC(obj__increaseCounter)];
} forEach _targets;

[_mission, _targets] call FUNC(mainmission__oneCounter);
