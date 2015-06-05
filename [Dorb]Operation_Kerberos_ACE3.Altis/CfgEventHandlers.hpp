

class Extended_PreInit_EventHandlers {
    class Dorb_Preinit {
        init = "call compile preProcessFileLineNumbers 'XEH_PreInit.sqf'";
    };
};

class Extended_Init_Eventhandlers {
	class rhs_infantry_msv_base {
		class Dorb_init {
			init = "_this call dorb_fnc_addNVG;";
		};
	};
};
class Extended_Respawn_EventHandlers {
	class B_Soldier_base_F {
		class Dorb_Respawn {
			scope = 2;
			respawn = "call compile preProcessFileLineNumbers 'XEH_respawn.sqf'";
		};
	};
};
class Extended_killed_EventHandlers {
	class B_Soldier_base_F {
		class Dorb_killed {
			scope = 2;
			killed = "call compile preProcessFileLineNumbers 'XEH_killed.sqf'";
		};
	};
};

class Extended_fired_Eventhandlers {
	class B_Soldier_base_F {
		class Dorb_Fired {
			scope = 2;
			fired = "call compile preProcessFileLineNumbers 'XEH_fired.sqf'";
		};
	};
};

class Extended_Hit_EventHandlers {
	class B_Soldier_base_F {
		class Dorb_Hit {
			scope = 2;
			hit = "call compile preProcessFileLineNumbers 'XEH_hit.sqf'";
		};
	};
};