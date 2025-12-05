SootopolisCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SootopolisCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SOOTOPOLIS_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn:
	.string "שומעים שוולאס נחשב למאמן\n"
	.string "החזק ביותר בכל אזור הואן.\p"
	.string "המכון בעיר הזאת מנוהל על ידי\n"
	.string "המאמן שלימד את וולאס.\p"
	.string "אבל הרביעייה העלית… אומרים שהם\n"
	.string "חזקים אפילו יותר ממורו של וולאס.\p"
	.string "כמה חזקים הם יכולים להיות?$"

SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge:
	.string "כל תושבי העיר חיפשו מחסה\n"
	.string "ולא יוצאים מבתיהם.\p"
	.string "גם אני מעדיף שלא להסתכן\n"
	.string "ולצאת החוצה.$"

SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon:
	.string "בכל זמן, בכל מקום, ובכל מצב\n"
	.string "אני תמיד אשמור על חברות עם\l"
	.string "פוקימונים.\p"
	.string "כי כיף להיות עם פוקימונים!$"

SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends:
	.string "האם פוקימונים אינם חברינו?\p"
	.string "למה הם משתוללים כך?$"

