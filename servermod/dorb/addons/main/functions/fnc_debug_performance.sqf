/*
    Author: Dorbedo

    Description:
        Diagnosefunktion um Performance-Probleme zu analysieren

*/
#include "script_component.hpp"
_this params[["_Scripte",true,[true]],["_Variablen",false,[true]]];
private _Ausgabe = [];
private _tickzeit = diag_tickTime;
private _stunden = floor (_tickzeit / 3600);
private _sekunden = _tickzeit - (_stunden * 3600);
private _minuten = floor (_sekunden / 60);
private _sekunden = _sekunden - (_minuten * 60);
private _zeitstempel = format["%1:%2:%3",_stunden,_minuten,_sekunden];
_Ausgabe pushBack format["DIAG START - %1 (%2)",_zeitstempel,_tickzeit];

private _fps = diag_fps;
private _fps_min = diag_fpsmin;
_Ausgabe pushBack format["    FPS    = %1  (Average over the last 16)",_fps];
_Ausgabe pushBack format["    FPSMIN = %1  (Minimal over the last 16)",_fps_min];

_Ausgabe pushBack format["    PLAYERCOUNT = %1  (Amount der Spieler)",(count allPlayers)];
_Ausgabe pushBack format["    UNITAMOUNT = %1 | %2 | %3 | %4 (WEST | EAST | IND | CIV)",(west countSide allUnits),(east countSide allUnits),(independent countSide allUnits),(civilian countSide allUnits)];
_Ausgabe pushBack format["    MINES = %1  (Amount)",(count allMines)];
_Ausgabe pushBack format["    OBJEKTE = %1  (Amount of objects)",(count (allMissionObjects "ALL"))];
_Ausgabe pushBack format["    CBA_perFrameEH = %1  (Amount of CBA-Eventhandle)",(count (cba_common_perFrameHandlerArray))];
If (hasInterface) then {
    _Ausgabe pushBack format["    Viewdistance = %1 | %2  (viewDistance | [ObjectViewDistance , ShadowViewDistance])",(viewDistance),(getObjectViewDistance)];
};

If (_Scripte) then {
    private _aktive_SQF = diag_activeSQFScripts;
    private _aktive_SQS = diag_activeSQSScripts;
    private _aktive_FSM = diag_activeMissionFSMs;
    _Ausgabe pushBack "    ACTIVE SQF-SCRIPTS - [SCRIPTNAME | ISACTIV | LINE | FILE]";
    {
        _Ausgabe pushBack format["       %1 | %2 | %3 | %4",(_x select 0),(_x select 2),(_x select 3),(_x select 1)];
    }forEach _aktive_SQF;
    _Ausgabe pushBack "    ACTIVE SQS-SCRIPTS - [SCRIPTNAME | ISACTIV | LINE | FILE]";
    {
        _Ausgabe pushBack format["       %1 | %2 | %3 | %4",(_x select 0),(_x select 2),(_x select 3),(_x select 1)];
    }forEach _aktive_SQS;
    _Ausgabe pushBack "    ACTIVE FSM-SCRIPTS - [NAME | STATE | TIMEOUT]";
    {
        _Ausgabe pushBack format["       %1 | %2 | %3",(_x select 0),(_x select 1),(_x select 2)];
    }forEach _aktive_FSM;
};

If (_Variablen) then {
    private _alleVariablenMNS = allVariables missionnamespace;
    private _alleVariablenUI = allVariables uinamespace;
    _Ausgabe pushBack "    Variables in MISSIONNAMESPACE [VARIABLENNAME = VALUE]";
    {
        private "_Wert";
        _Wert = missionnamespace getVariable[_x,"ERROR"];
        If ((typeName _Wert) isEqualTo "CODE") then {_Wert = "CODE";};
        _Ausgabe pushBack format["       %1 = %2",_x,_Wert];
    }forEach _alleVariablenMNS;
    _Ausgabe pushBack "    Variables in UINAMESPACE [VARIABLENNAME = VALUE]";
    {
        private "_Wert";
        _Wert = uiNamespace getVariable[_x,"ERROR"];
        If ((typeName _Wert) isEqualTo "CODE") then {_Wert = "CODE";};
        _Ausgabe pushBack format["       %1 = %2",_x,_Wert];
    }forEach _alleVariablenMNS;
};
_Ausgabe pushBack "DIAG END - IN (%2) SECONDS";
_Ausgabe joinString "%1";
diag_log text format [_Ausgabe,endl,(diag_tickTime - _tickzeit)];

nil;
