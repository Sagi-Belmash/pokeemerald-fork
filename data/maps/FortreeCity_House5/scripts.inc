FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
    .string "בתי העץ של פורטרי נהדרים!\p"
    .string "אני חושב שזו העיר מספר אחד\n"
    .string "לחיות יחד עם פוקימון.$"

FortreeCity_House5_Text_AdaptedToNature:
    .string "פוקימון ואנשים הסתגלו\n"
    .string "לטבע כדי לשרוד.\p"
    .string "אין צורך לגרום לטבע\n"
    .string "להתאים לאופן שבו אנו רוצים לחיות.$"

FortreeCity_House5_Text_Zigzagoon:
	.string "{STR_VAR_1}: בופוו!$"

