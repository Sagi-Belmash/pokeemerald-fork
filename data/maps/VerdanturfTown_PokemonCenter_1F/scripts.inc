VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_VERDANTURF_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "את{EMIT_HEY} לא יכול{ADD_HEY} להחשיב את עצמך\n"
	.string "כמאמ{SWAP_NUN}{ADD_TAF} אם אין לך אמון\l"
	.string "בפוקימון שלך.\p"
	.string "רק אנשים שיכולים להאמין בפוקימונים\n"
	.string "הנלחמים שלהם יכולים לנצח עד הסוף.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "הסיבה שלה מישהו יבקר\n"
	.string "בורדנטרף…\p"
	.string "זה אוהל הקרב. זה מובן מאליו.\p"
	.string "או שיש פה מישהו שבאת לבקר?$

