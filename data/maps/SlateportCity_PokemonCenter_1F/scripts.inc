SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SLATEPORT_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "רוצה טיפ לקרבות?\p"
	.string "אני ממליץ לגדל סוגים שונים של פוקימונים\n"
	.string "באופן מאוזן.\p"
	.string "זה לא טוב לחזק רק פוקימון אחד.\p"
	.string "אם יש לו חיסרון מול סוג מסוים,\n"
	.string "הוא אולי לא יחזיק מעמד.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "החלפתי פוקימונים עם חברים שלי.\p"
	.string "אם פוקימון מוחלף מחזיק בפריט,\n"
	.string "זה משמח אותי כפליים!$"

