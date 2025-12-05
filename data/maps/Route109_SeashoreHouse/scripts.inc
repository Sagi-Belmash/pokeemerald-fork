Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "אני הבעלים של בית חוף הים.\n"
	.string "אבל את{EMIT_HEY} יכול{ADD_HEY} לקרוא לי מר ים!\p"
	.string "מה שאני אוהב מעל הכל זה לראות קרבות\n"
	.string "פוקימון לוהטים.\p"
	.string "הרא{EMIT_HEY}{ADD_YUD} לי שהלב שלך בוער!\p"
	.string "אם תצליח{ADD_YUD} להביס את כל המאמנים\n"
	.string "כאן, אתגמל אותך על מאמציך.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "הרא{EMIT_HEY}{ADD_YUD} לי קרבות לוהטים!\p"
	.string "אני מנהל את בית חוף הים הזה מהסיבה\n"
	.string "הזאת בלבד!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "את{EMIT_HEY} לוהט{ADD_TAF} למדי!\n"
	.string "הקרבות האלה בערו!\l"
	.string "אני יותר ממרוצה!\p"
	.string "כתודה שהראית לי את הרצף\n"
	.string "הלוהט הזה, אני רוצה שתקח{ADD_YUD} את זה.\p"
	.string "זה חצי תריסר בקבוקי סודה פופ!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "או, אבל היי, התיק שלך מלא לגמריי.\n"
	.string "אני אשמור אותם לך בינתיים.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "רוצה לקנות סודה פופ?\n"
	.string "פוקימונים אוהבים את זה!\p"
	.string "רק 003¥ לבקבוק!\n"
	.string "תקנ{EMIT_HEY}{ADD_YUD} כמה!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "הנה לך!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "אין לך את הכסף.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "לא?\n"
	.string "חבל מדי.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "אם את{EMIT_HEY} מחפש{ADD_TAF} קרב\n"
	.string "בבית חוף הים, לא תמצא{ADD_YUD}\l"
	.string "מאמן לוהט יותר ממני, חבר{ADD_HEY}!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "זה היה קרב לוהט!\n"
	.string "אני יכול להכיל את ההפסד הזה, חבר{ADD_HEY}!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "כשאני בסלייטפורט, אני נהנה\n"
	.string "מקרבות לוהטים וסודה פופ קפוא כקרח!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "קרבות משעממים לא שווים את המאמץ.\p"
	.string "קרבות לוהטים וסוערים הם מה שמחשל\n"
	.string "מאמנים ופוקימונים!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "זה לוהט!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "ווהו, אני צמאה לגמריי.\n"
	.string "אולי אקח סודה פופ.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "אני הולך להראות לך כמה הפוקימונים\n"
	.string "שלי נהדרים, אבל אל תבכ{EMIT_HEY}{ADD_YUD}!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…הפסדתי, אבל אני לא אבכה…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "אם אחד הפוקימונים שלי היה יודע את\n"
	.string "המתקפה לנשיאה מעל המים על\l"
	.string "הגב שלו, הייתי יכול להיפטר מהאבוב הזה.$"

