/*
 *  Author: Dorbedo
 *
 *  Description:
 *      adds the init Eventhandler
 *
 */
#include "script_component.hpp"

["rhsusf_M1083A1P2_B_M2_d_Medical_fmtv_usarmy", "init", {
    _this call FUNC(addACEMedicalItems);
},true,[],true] call CBA_fnc_addClassEventHandler;

["rhs_gaz66_ap2_base", "init", {
    _this call FUNC(addACEMedicalItems);
},true,[],true] call CBA_fnc_addClassEventHandler;

["ACE_bodyBagObject", "init", {
    if (local (_this select 0)) then {deleteVehicle (_this select 0);};
},true,[],true] call CBA_fnc_addClassEventHandler;
