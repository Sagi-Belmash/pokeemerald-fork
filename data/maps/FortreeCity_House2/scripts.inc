FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
    .string "אנשים… פוקימון…\p"
    .string "הכוחות הנסתרים שלהם מתעוררים\n"
    .string "כשחיים בסביבות טבעיות…$"

FortreeCity_House2_Text_CoinInWhichHand:
    .string "ת{SWAP_NUN}{ADD_YUD} לזקנה הזו לבדוק אם הכוח הנסתר\n"
    .string "שלך התעורר…\p"
    .string "אני מחזיקה מטבע ביד.\p"
    .string "עכשיו, תגיד{ADD_YUD} לי, האם החבאתי אותו\n"
    .string "ביד ימין? או ביד שמאל?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "רו! כן, נכון!\p"
    .string "ננסה שוב.\p"
    .string "באיזו יד החבאתי את המטבע?\n"
    .string "ימין או שמאל?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
    .string "או! כן, נכון!\p"
    .string "ננסה שוב.\p"
    .string "באיזו יד החבאתי את המטבע?\n"
    .string "ימין או שמאל?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "או! נהדר!\n"
    .string "הכוח הנסתר שלך התעורר!\p"
    .string "הנה, קח{ADD_YUD} את זה והער את הכוח הנסתר\n"
    .string "של הפוקימון שלך.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "כוח נסתר הוא מהלך שמשתנה\n"
	.string "לפי הפוקימון.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "לא, חבל.\n"
	.string "ניחשת לא נכון.$"

