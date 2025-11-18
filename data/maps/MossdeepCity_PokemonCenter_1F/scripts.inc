MossdeepCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MossdeepCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

MossdeepCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_MOSSDEEP_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_Woman::
	msgbox MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_EventScript_Girl::
	msgbox MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable:
	.string "מנהיגי המכון בעיר הזאת הם\n"
	.string "זוג מרשים במיוחד.\p"
	.string "שילוב ההתקפות שלהם הוא, כאילו,\n"
	.string "מעולה ווואו!$"

MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves:
    .string "בהתאם ליכולות המיוחדות של\n"
    .string "פוקימון, חלק מהמהלכים עשויים להשתנות\l"
    .string "או לא לעבוד בכלל.$"

