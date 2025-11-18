Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_WINGULL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
    .string "שמעתי על מערה שנקראת מערת\n"
    .string "המוצא.\p"
    .string "יש שמועות שהרוחות של פוקימונים\n"
    .string "חוזרות שם לחיים. האם\l"
    .string "משהו כזה יכול באמת לקרות?$"

Route119_House_Text_Wingull:
	.string "{STR_VAR_1}: פיהיוה!$"

