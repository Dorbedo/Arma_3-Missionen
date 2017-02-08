/*
 *  Author: [Name of Author(s)]
 *
 *  Description:
 *      [Description]
 *
 *  Parameter(s):
 *      0 : [TYPE] - [argument name]
 *
 *  Returns:
 *      [TYPE] - [return name]
 *
 */
#define INCLUDE_GUI
#define DEBUG_MODE_FULL
#include "script_component.hpp"

_this params ["_event","_params"];
TRACEV_3(_event,_params,_this);
switch (toLower _event) do {
    case "onload" : {
        _params params ["_ctrl"];

        private _enter = _ctrl ctrlAddEventHandler ["MouseEnter", {["onMouseEnter",_this] call FUNC(bttn);}];
        _ctrl ctrlAddEventHandler ["MouseExit", {["onMouseExit",_this] call FUNC(bttn);}];
        _ctrl ctrlAddEventHandler ["ButtonDown", {["onButtonDown",_this] call FUNC(bttn);}];
        _ctrl ctrlAddEventHandler ["ButtonClick", {["onButtonClick",_this] call FUNC(bttn);}];
        _ctrl ctrlAddEventHandler ["ButtonUp", {["onButtonUp",_this] call FUNC(bttn);}];

        private _ctrlGroup = ctrlParentControlsGroup _ctrl;
        private _idc = parseNumber ((str _ctrl) select [9]);
        private _ctrlPicture = _ctrlGroup controlsGroupCtrl (_idc+1);
        _ctrlPicture ctrlSetTextColor [RAL6018, 1];
        _ctrlPicture ctrlCommit 0;
        private _text = ctrlText _ctrlPicture;
        TRACEV_4(_ctrl,_ctrlGroup,_idc,_text);
        private _pos = ctrlPosition _ctrl;
        TRACEV_2(_enter,_pos);
    };
    case "onmouseenter" : {
        _params params ["_ctrl"];
        private _ctrlGroup = ctrlParentControlsGroup _ctrl;
        private _idc = parseNumber ((str _ctrl) select [9]);
        private _ctrlPicture = _ctrlGroup controlsGroupCtrl (_idc+1);
        _ctrlPicture ctrlSetText QEPAAPATH(buttons,button_256_over);
        _ctrlPicture ctrlSetBackgroundColor [1,1,1,1];
        _ctrlPicture ctrlCommit 0;
        private _text = ctrlText _ctrlPicture;
        TRACEV_2(_idc,_text);
    };
    case "onmouseexit" : {
        _params params ["_ctrl"];
        private _ctrlGroup = ctrlParentControlsGroup _ctrl;
        private _idc = parseNumber ((str _ctrl) select [9]);
        private _ctrlPicture = _ctrlGroup controlsGroupCtrl (_idc+1);
        _ctrlPicture ctrlSetText QEPAAPATH(buttons,button_256_normal);
        _ctrlPicture ctrlSetBackgroundColor [0,0,0,1];
        _ctrlPicture ctrlCommit 0;
        private _text = ctrlText _ctrlPicture;
        TRACEV_2(_idc,_text);
    };
    case "onbuttondown" : {
        _params params ["_ctrl"];
        private _ctrlGroup = ctrlParentControlsGroup _ctrl;
        private _idc = parseNumber ((str _ctrl) select [9]);
        private _ctrlPicture = _ctrlGroup controlsGroupCtrl (_idc+1);
        _ctrlPicture ctrlSetText QEPAAPATH(buttons,button_256_pressed);
        _ctrlPicture ctrlSetBackgroundColor [1,1,1,1];
        _ctrlPicture ctrlCommit 0;
        private _text = ctrlText _ctrlPicture;
        TRACEV_2(_idc,_text);
    };
    case "onbuttonup" : {
        _params params ["_ctrl"];
        private _ctrlGroup = ctrlParentControlsGroup _ctrl;
        private _idc = parseNumber ((str _ctrl) select [9]);
        private _ctrlPicture = _ctrlGroup controlsGroupCtrl (_idc+1);
        _ctrlPicture ctrlSetText QEPAAPATH(buttons,button_256_normal);
        _ctrlPicture ctrlSetBackgroundColor [0,0,0,1];
        _ctrlPicture ctrlCommit 0;
        private _text = ctrlText _ctrlPicture;
        TRACEV_2(_idc,_text);
    };
    case "onbuttonclick" : {
        _params params ["_ctrl"];
        private _ctrlGroup = ctrlParentControlsGroup _ctrl;
        private _idc = parseNumber ((str _ctrl) select [9]);
        private _ctrlPicture = _ctrlGroup controlsGroupCtrl (_idc+1);
        _ctrlPicture ctrlSetText QEPAAPATH(buttons,button_256_over);
        _ctrlPicture ctrlSetBackgroundColor [1,1,1,1];
        _ctrlPicture ctrlCommit 0;
        private _text = ctrlText _ctrlPicture;
        TRACEV_2(_idc,_text);
    };
};
