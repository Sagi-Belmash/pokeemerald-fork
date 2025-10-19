RustboroCity_Flat2_1F_MapScripts::
	.byte 0

RustboroCity_Flat2_1F_EventScript_OldWoman::
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_SKITTY
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere:
	.string "עובדים של תאגיד דבון גרים\n"
	.string "בבניין הזה.$"

RustboroCity_Flat2_1F_Text_Skitty:
	.string "{STR_VAR_1}: גיאאאה!$"

