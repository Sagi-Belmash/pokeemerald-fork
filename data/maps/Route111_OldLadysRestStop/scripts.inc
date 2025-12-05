Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "או, יקיר{ADD_TAF}י, יקיר{ADD_TAF}י.\n"
	.string "הפוקימונים שלך לא מותשים?\p"
	.string "אם תרצ{EMIT_HEY}{ADD_YUD}, תנוח{ADD_YUD} כאן.\n"
	.string "זה רעיון נהדר! כדאי לך לעשות את זה.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "בדיוק.\n"
	.string "קח{ADD_YUD} את הזמן ותנוח{ADD_YUD}!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "או, יקיר{ADD_TAF}י, יקיר{ADD_TAF}י.\n"
	.string "הפוקימונים שלך עדיין עייפים?\p"
	.string "כדאי שתנוח{ADD_YUD} כאן שוב.\n"
	.string "זה רעיון נהדר! כדאי לך לעשות את זה.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "אכן כך?\n"
	.string "את{EMIT_HEY} לא צרי{SWAP_CHAF}{ADD_HEY} להתבייש בכך.$"

