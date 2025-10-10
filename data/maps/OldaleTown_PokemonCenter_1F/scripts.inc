OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "המחשב שם בפינה הוא לשימוש עבור כל\n"
	.string "מאמן פוקימון .\p"
	.string "כמובן, זה אומר שגם את{EMIT_HEY} יכול{ADD_HEY}\n"
	.string "להשתמש בו.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "מרכזי פוקימון הם נהדרים!\p"
	.string "ניתן להשתמש בשירותיהם כמה שרוצים,\n"
	.string "והכל בחינם.\l"
	.string "אף פעם לא צריך לדאוג!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "מועדון הפוקימון האלחוטי\n"
	.string "בקומה השניה נבנה לאחרונה.\p"
	.string "אבל הם אומרים שהם עדיין מבצעים\n"
	.string "התאמות.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "מועדון הפוקימון האלחוטי\n"
	.string "בקומה השניה נבנה לאחרונה.\p"
	.string "מיד החלפתי פוקימון.$"

