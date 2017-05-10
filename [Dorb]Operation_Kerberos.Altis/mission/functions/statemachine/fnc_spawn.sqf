/*
 *  Author: iJesuz, Dorbedo
 *
 *  Description:
 *      ends a mission
 *
 *  Parameter(s):
 *      0 : LOCATION - the last MainMission
 *
 *  Returns:
 *      none
 *
 */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE("spawn");
_this params ["_mission"];

 // if the spawning is not finished after 10 Minutes, we stop the mission
_mission setVariable ["spawntimeout",CBA_missiontime + 10*60];

_mission spawn {
    _this params ["_mission"];
    // we move the spawning outside the sheduled environment, adding a delay to reduce the network peaks
    private _type = _mission getVariable "type";
    private _centerpos = _mission getVariable "centerpos";
    private _mainOrSide = If (_mission getVariable ["isMain",true]) then {"main"}else{"side"};
    TRACEV_3(_type,_centerpos,_mainOrSide);
    private _objects = [_type,_centerpos,_mainOrSide] call FUNC(spawn_spawnTargets);

    // remove wrong spawned objects (0,0,0) or ATL
    _objects = _objects - [objNull];
    _objects = _objects select {
        (((getPosATL _x) select 2) >= 0)&&
        {((getPos _x) distance2D [0,0,0])>10}
    };

    If (_mainOrSide == "main") then {
        [_mission] call FUNC(statemachine_addSide);
        [_mission, _objects] call (missionNamespace getVariable [format ["%1_%2", QFUNC(mainmission), _type], {}]);
    }else{
        [_mission, _objects] call (missionNamespace getVariable [format ["%1_%2", QFUNC(sidemission), _type], {}]);
    };

    {
        _x setVariable [QGVAR(mission),_mission];
    } forEach _objects;
    _mission setVariable ["objects",_objects];
    // the spawning has been finished, next state
    _mission setVariable ["spawningfinished",true];

};
