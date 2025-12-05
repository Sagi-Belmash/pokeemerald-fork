SootopolisCity_House1_MapScripts::
	.byte 0

SootopolisCity_House1_EventScript_BrickBreakBlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_BRICK_BREAK, SootopolisCity_House1_EventScript_ReceivedBrickBreak
	msgbox SootopolisCity_House1_Text_DevelopedThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_BRICK_BREAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_BRICK_BREAK
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House1_EventScript_ReceivedBrickBreak::
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_KECLEON
	msgbox SootopolisCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House1_Text_DevelopedThisTM:
    .string "שלושים שנה נשארתי בסוטופוליס\n"
    .string "לשפר את כישוריי.\p"
    .string "פיתחתי מ”מ מרסק.\n"
    .string "אני מוסר אותו לך!$"

SootopolisCity_House1_Text_ExplainBrickBreak:
	.string "מ”מ13 מכיל שובר שורות! זה מהלך\n"
    .string "איום כל כך שלא אוכל לתאר אותו.$"

SootopolisCity_House1_Text_Kecleon:
	.string "{STR_VAR_1}: פוו פוהייאה.$"

