/*
 *  Author: Dorbedo
 *
 *  Description:
 *      the statemachine for the playergroups
 *
 */
#include "script_component.hpp"


class GVAR(AIGroups_statemachine) {
    // Class properties have the same name as the corresponding function parameters
    // and code goes into strings.
    list = QUOTE(call FUNC(statemachine_getAIGroups));
    skipNull = 1;

    class initial {
        onState = "";
        onStateEntered = QUOTE(_this setVariable [ARR_2('GVAR(target)',locationNull]);
        onStateLeaving = "";
        // groups patroling the outer parameter
        class toPatrol {
            targetState = "patrol";
            condition = QUOTE((_this getVariable [ARR_2('GVAR(state)','none')])=='patrol');
            onTransition = "";
        };
        // attackgroups
        class toCombat {
            targetState = "combat";
            condition = QUOTE((_this getVariable [ARR_2('GVAR(state)','none')])=='combat');
            onTransition = "";
        };
        // groups defending the POIs
        class toDefence {
            targetState = "defence";
            condition = QUOTE((_this getVariable [ARR_2('GVAR(state)','none')])=='defence');
            onTransition = "";
        };
        // static units e.g. compositions
        class toStatic {
            targetState = "static";
            condition = QUOTE((_this getVariable [ARR_2('GVAR(state)','none')])=='static');
            onTransition = "";
        };
        class toCAS {
            targetState = "cas_support";
            condition = QUOTE((_this getVariable [ARR_2('GVAR(state)','none')])=='cas_support');
            onTransition = "";
        };

    };


    // patrol recoursively around the Area
    class patrol {
        onState = "";
        onStateEntered = QFUNC(statemachine_patrol);
        onStateLeaving = "";
        // the grouptype has been changed due to the curcumstance, that not enaught attackunits are availlible
        class patrol_toCombat {
            targetState = "Combat";
            condition = QUOTE((_this getVariable [ARR_2('GVAR(state)','none')])=='combat');
            onTransition = "";
        };
    };

    // combat waiting modi
    class combat {
        onState = "";
        onStateEntered = QFUNC(statemachine_patrolCombat);
        onStateLeaving = "";
        class attack {
            targetState = "combat_inAttack";
            condition = QUOTE((!isNull(_this getVariable [ARR_2('GVAR(target)',locationNull)])));
            onTransition = "";
        };
    };
    // attacking
    class combat_inAttack {
        onState = "";
        onStateEntered = QFUNC(statemachine_attack);
        onStateLeaving = "";
        class combat_return {
            targetState = "combat_return";
            condition = QUOTE((isNull(_this getVariable [ARR_2('GVAR(target)',locationNull)])));
            onTransition = "";
        };
        class combat_complete {
            targetState = "combat_AttackComplete";
            condition = QUOTE((_this getVariable [ARR_2('GVAR(state)','finished')])=='finished');
            onTransition = "";
        };
    };
    // attack has been finished
    class combat_AttackComplete {
        onState = "";
        onStateEntered = QFUNC(statemachine_attackfinished);
        onStateLeaving = "";
        class combat_return {
            targetState = "combat_return";
            condition = "true";
            onTransition = QUOTE(_this setVariable [ARR_2('GVAR(state)','returning')]);
        };
    };

    class combat_return {
        onState = "";
        onStateEntered = QFUNC(statemachine_return);
        onStateLeaving = "";
        class finished {
            targetState = "combat";
            condition = QUOTE((_this getVariable [ARR_2('GVAR(state)','returning')])!='returning');
            onTransition = QUOTE(_this setVariable [ARR_2('GVAR(state)','combat')]);
        };
    };

    class defence {
        onState = "";
        onStateEntered = QFUNC(statemachine_patrolDefence);
        onStateLeaving = "";
        // the state has been switched to combat due to no POI exist anymore
        class defence_toCombat {
            targetState = "Combat";
            condition = QUOTE((_this getVariable [ARR_2('GVAR(state)','none')])=='combat');
            onTransition = "";
        };
        // if the POI has been destroyed, move the group to another POI to defend this one
        class defence_nextPOI {
            targetState = "defence";
            condition = QUOTE(isNull (_this getVariable [ARR_2('GVAR(target)',locationNull)]));
            onTransition = "";
        };
    };
    // static units and compositions
    class static {
        onState = "";
        onStateEntered = QUOTE(_this setVariable [ARR_2('GVAR(state)','static')]);
        onStateLeaving = "";
    };

    class cas_support {
        onState = "";
        onStateEntered = QFUNC(statemachine_CAS);
        onStateLeaving = "";
        /*
        class noAmmo {
            targetState = "return";
            condition = QFUNC(NoAmmo);
            onTransition = "";
        };
        */
        class timeout {
            targetState = "return";
            condition = QUOTE((_this getVariable [ARR_2('GVAR(timeout)',-1)])<CBA_missiontime);
            onTransition = "";
        };
    };

    // return to spawnpos and delete
    class return {
        onState = "";
        onStateEntered = QFUNC(statemachine_OffMapReturn);
        onStateLeaving = "";
        class returnpoint_reached {
            targetState = "delete";
            condition = QUOTE(((leader _this) distance2d (_this getVariable [ARR_2('GVAR(spawnpos)',[ARR_3(0,0,0)])]))<800);
            onTransition = "";
        };
        class isUnseen {
            targetState = "delete";
            condition = QFUNC(statemachine_canBeDeletedUnseen);
            onTransition = "";
        };
    };
    // delete a group and it's units mostly for off-map support or transport groups
    class delete {
        onState = "";
        onStateEntered = QEFUNC(common,delete);
        onStateLeaving = "";
    };
};
