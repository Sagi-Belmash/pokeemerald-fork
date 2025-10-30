PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PACIFIDLOG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	bufferspeiesname STR_VAR_1, SPECIES_CORSOLA
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "איזה צבע הכרטיס מאמן שלך?\n"
	.string "שלי בצבע נחושת!$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "עיירת פסיפידלוג צפה מעל מושבה של\n"
	.string "{STR_VAR_1}.\p"
	.string "אם אמרתי לך את זה, היית מאמי{SWAP_NUN}{ADD_HEY} לי?$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "אומרים שאבותיהם של האנשים\n"
	.string "בפסיפידלוג נולדו על סירות ואז\l"
	.string "חיו ומתו עליהן.\p"
	.string "אני מבין שהם חיו ככה כי\n"
	.string "הם חיפשו משהו.$"
