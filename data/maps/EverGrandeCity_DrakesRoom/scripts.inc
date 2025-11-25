EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech:
	.string "אני האחרון ברביעיית העלית של\n"
	.string "ליגת הפוקימונים, דרייק, מאסטר הדרקון!\p"
	.string "במצבם הטבעי, פוקימונים הם יצורים\n"
	.string "חיים פראיים. הם חופשיים.\p"
	.string "לפעמים הם מפריעים לנו.\n"
	.string "ולפעמים הם עוזרים לנו.\p"
	.string "כדי להילחם יחד עם פוקימונים\n"
	.string "כשותפים, את{EMIT_HEY} יודע{ADD_TAF} מה נדרש?\p"
	.string "את{EMIT_HEY} יודע{ADD_TAF} מה צריך?\p"
	.string "אם לא, לעולם לא תצליח{ADD_YUD}\n"
	.string "לגבור עליי!$"

EverGrandeCity_DrakesRoom_Text_Defeat:
	.string "נפלא, זה מה שצריך לומר.$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
	.string "את{EMIT_HEY} ראוי{ADD_HEY} לכל שבח על כך שהגעת\n"
	.string "עד לכאן כמאמ{SWAP_NUN}{ADD_TAF} פוקימונים.\p"
	.string "נראה שאת{EMIT_HEY} כן יודע{ADD_TAF} מה נדרש.\p"
	.string "כן, מה שמאמן צריך הוא\n"
	.string "לב מוסרי.\p"
	.string "פוקימונים נוגעים בלבם הטוב של\n"
	.string "המאמנים ולומדים טוב מרע.\p"
	.string "הם נוגעים בלבם הטוב של\n"
	.string "המאמנים ומתחזקים.\p"
	.string "ל{SWAP_CHAF}{ADD_YUD}! ל{SWAP_CHAF}{ADD_YUD} קדימה!\n"
	.string "האלוף מחכה!$"

