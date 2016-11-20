/*
 *  Author: Dorbedo
 *
 *  Description:
 *      called to initialize a new mainmission
 *
 *  Parameter(s):
 *      0 : ARRAY - Centerposition of the mainarea
 *
 *  Returns:
 *      none
 *
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"

_this params [["_centerPos",[],[[]]]];
TRACEV_1(_centerPos);

private _gridsize = HASH_GET(GVAR(dangerzones),"gridsize");
private _distance = HASH_GET(GVAR(dangerzones),"distance");

private _center = [
    (round ((_centerPos select 0) / _gridsize)) * _gridsize,
    (round ((_centerPos select 1) / _gridsize)) * _gridsize,
    0];

HASH_SET(GVAR(dangerzones),"centerpos",_center);
HASH_SET(GVAR(dangerzones),"x",[ARR_2((_center select 0) - _distance,(_center select 0) + _distance)]);
HASH_SET(GVAR(dangerzones),"y",[ARR_2((_center select 1) - _distance,(_center select 1) + _distance)]);


HASH_SET(GVAR(groups),"defenceGroups",[]);
HASH_SET(GVAR(groups),"attackGroups",[]);
HASH_SET(GVAR(groups),"patrolGroups",[]);


HASH_DELETE(GVAR(waypoints));
GVAR(waypoints) = HASH_CREATE;
HASH_SET(GVAR(waypoints),"deactivated",[]);



GVAR(active) = true;
