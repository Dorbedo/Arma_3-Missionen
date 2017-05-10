/*
    Author: Dorbedo

    Description:
    Big Cleanup

*/
#include "script_component.hpp"
_this params ["_pos",["_rad",2500,[0]]];

{
    GVAR(cleanup_Dump_int) pushBackUnique [-1,_x];
} foreach (_pos nearObjects ["ALL", _rad]);

{
    GVAR(cleanup_Dump_int) pushBackUnique [-1,_x];
} forEach allMines;

{
    if (side _x != GVARMAIN(playerside) ) then {
        GVAR(cleanup_Dump_int) pushBackUnique [-1,_x];
    };
} foreach allunits;

{
    if (!(alive _x)) then {
        GVAR(cleanup_Dump_int) pushBackUnique [-1,_x];
    };
} foreach vehicles;

{
    GVAR(cleanup_Dump_int) pushBackUnique [-1,_x];
} forEach allDead;

{
    GVAR(cleanup_Dump_int) pushBackUnique [-1,_x];
} forEach (allMissionObjects "CraterLong");

{
    GVAR(cleanup_Dump_int) pushBackUnique [-1,_x];
} forEach (allMissionObjects "CraterLong_small");

{
    GVAR(cleanup_Dump_int) pushBackUnique [-1,_x];
} forEach (allMissionObjects "WeaponHolder");

{
    GVAR(cleanup_Dump_int) pushBackUnique [-1,_x];
} forEach (allMissionObjects "GroundWeaponHolder");

{
    GVAR(cleanup_Dump_int) pushBackUnique [-1,_x];
} forEach (allMissionObjects "GroundWeaponHolder_scripted");

{
    GVAR(cleanup_Dump_int) pushBackUnique [-1,_x];
    nil;
} count GVAR(cleanUpDump);
GVAR(cleanup_Dump_int) sort true;
GVAR(cleanUpDump) = [];

[] call EFUNC(common,debug_marker_clean);

ISNILS(EGVAR(mission,markerdump),[]);
EGVAR(mission,markerdump) TILGE;

[{GVAR(cleaningUp) = false;},[],30] call CBA_fnc_waitAndExecute;
