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
TRACE("endmission");
/*
    //   _stateMachine   - the state machine
    //   _this           - the current list item
    //   _thisTransition - the current transition we're in
    //   _thisOrigin     - the state we're coming from
    //   _thisState      - same as _thisOrigin
    //   _thisTarget     - the state we're transitioning to
*/

_this params ["_mission"];

private _TaskID = _mission getVariable "taskID";
If (IS_ARRAY(_TaskID)) then {
    _TaskID = _TaskID select 0;
};
private _type = _mission getVariable ["type",""];

switch _thisTransition do {
    case "succeeded" : {
        [
            _TaskID,
            "SUCCEEDED",
            false
        ] call BIS_fnc_taskSetState;
        [QEGVAR(gui,message),[format[LSTRING(%1_TITLE),_type],format[LSTRING(%1_SUCCEEDED),_type],"green"]] call CBA_fnc_globalEvent;
    };
    case "neutral" : {
        [
            _TaskID,
            "CANCELED",
            false
        ] call BIS_fnc_taskSetState;
        [QEGVAR(gui,message),[format[LSTRING(%1_TITLE),_type],format[LSTRING(%1_NEUTRAL),_type],"yellow"]] call CBA_fnc_globalEvent;
    };
    case "timeout";
    case "failed" : {
        [
            _TaskID,
            "FAILED",
            false
        ] call BIS_fnc_taskSetState;
        [QEGVAR(gui,message),[format[LSTRING(%1_TITLE),_type],format[LSTRING(%1_FAILED),_type],"red"]] call CBA_fnc_globalEvent;
    };
    default {
        [
            _TaskID,
            "CANCELED",
            false
        ] call BIS_fnc_taskSetState;
    };
}
