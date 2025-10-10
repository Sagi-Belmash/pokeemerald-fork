OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "כשפוקימון נלחם, הוא בסופו של דבר\n"
	.string "עולה רמה ומתחזק.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "אם הפוקימון איתך מתחזק,\n"
	.string "תוכל{ADD_YUD} להגיע הרחק יותר\l"
	.string "מכאן.$"

