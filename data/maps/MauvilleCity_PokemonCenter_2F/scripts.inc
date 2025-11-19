MauvilleCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
MauvilleCity_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

MauvilleCity_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

MauvilleCity_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

MauvilleCity_PokemonCenter_2F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_2F_Text_Youngster, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_2F_EventScript_Girl1StartSoloBerryCrush::
	lockall
	faceplayer
	checkitem ITEM_POWDER_JAR
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_2F_EventScript_NeedPowderJar
	msgbox MauvilleCity_PokemonCenter_2F_Text_PlayBerryCrushSolo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_2F_EventScript_DeclinedBerryCrushFromGirl
    fadescreenswapbuffers FADE_TO_BLACK
    special StartBerryCrushSolo
	releaseall
	end

MauvilleCity_PokemonCenter_2F_EventScript_DeclinedBerryCrushFromGirl::
	msgbox MauvilleCity_PokemonCenter_2F_Text_Girl1OkayThen, MSGBOX_AUTOCLOSE
	releaseall
	end

MauvilleCity_PokemonCenter_2F_EventScript_NeedPowderJar::
	msgbox MauvilleCity_PokemonCenter_2F_Text_NeedPowderJar, MSGBOX_AUTOCLOSE
	releaseall
	end

MauvilleCity_PokemonCenter_2F_Text_Youngster:
	.string "ידעת שאפשר לערוך קרבות קשר\n"
	.string "בקולוסיאום כאן?\p"
	.string "הם שמים את השיא שלך על הקיר\n"
	.string "להראות לכולם.\p"
	.string "זה מביך אם את{EMIT_HEY} מפסיד{ADD_HEY} יותר ממה\n"
	.string "שאת{EMIT_HEY} מנצח{ADD_TAF}…$"

MauvilleCity_PokemonCenter_2F_Text_PlayBerryCrushSolo:
	.string "רוצה לשחק במעיכת פירות יער\n"
	.string "בעצמך?$"

MauvilleCity_PokemonCenter_2F_Text_Girl1OkayThen:
	.string "בסדר…$"

MauvilleCity_PokemonCenter_2F_Text_NeedPowderJar:
	.string "אם תרצ{EMIT_HEY}{ADD_YUD} לשחק במעיכת פירות יער\n"
	.string "בעצמך, תצטר{SWAP_CHAF}{ADD_YUD} צנצנת אבקה.$"

