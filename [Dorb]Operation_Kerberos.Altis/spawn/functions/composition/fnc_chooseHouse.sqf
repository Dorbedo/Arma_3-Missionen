/*
 *  Author: Dorbedo
 *
 *  Description:
 *      chooses a housemacro from configfile
 *
 *  Parameter(s):
 *      0 : OBJECT - targethouse
 *
 *  Returns:
 *      CONFIG - the targetConfig
 *
 */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

_this params [["_house",objNull,[objNull]],["_isMissiontarget",false,[true]]];

private _housetype = typeOf _house;
private _allConfigs = [];

IF (_isMissiontarget) then {
    _allConfigs = ((format["((getText(_x >> 'type') == '%1')&&(getNumber(_x >> 'hasmissiontarget')>0))",_housetype]) configClasses (missionConfigFile >> "CfgCompositions" >> "houses"));
}else{
    _allConfigs = ((format["getText(_x >> 'type') == '%1'",_housetype]) configClasses (missionConfigFile >> "CfgCompositions" >> "houses"));
};
TRACEV_4(_house,_housetype,_isMissiontarget,_allConfigs);
If (_allConfigs isEqualTo []) exitWith {configNull;};

selectRandom _allConfigs;
