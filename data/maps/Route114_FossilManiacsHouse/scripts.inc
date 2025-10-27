Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "האח הגדול שלי הוא חובב מאובנים…\n"
	.string "הוא בן אדם נחמד שאוהב מאובנים…\p"
	.string "הוא גם אוהב לחפור בורות…\n"
	.string "הוא חבר את הבור הזה לבד…\p"
	.string "את{EMIT_HEY} יכול{ADD_HEY} לקחת את זה, כדי שתוכל{ADD_YUD} לחפור\n"
	.string "בורות בדיוק כמו אחי הגדול…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "אם תגר{EMIT_VAV}{SWAP_MEM}{ADD_YUD} לפוקימון לחפור\n"
	.string "במערה, את{EMIT_HEY} תחז{EMIT_VAV}ר{ADD_YUD} לכניסה…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "סלעים בצורות מיוחדות ממלאים\n"
	.string "את תיבת התצוגה…$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "הרכב השכבות…\n"
	.string "איך הגשם מעצב את הקרקע…\l"
	.string "סלעים, אדמה, ואבנים…\p"
	.string "הכל מלא בספרים.$"

