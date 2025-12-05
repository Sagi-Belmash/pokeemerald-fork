Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} כתב{ADD_HEY} את הקוד הסודי\n"
	.string "על הדלת.\p"
	.string "”מאסטר הטריקים הוא החיים שלי.“\n"
	.string "… … … … … … … …\p"
	.string "המנעול נפתח בלחיצה!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
    .string "כששמעתי שיש בית מוזר,\n"
    .string "הייתי חייבת לבדוק את זה.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
    .string "אני גיליתי מאמ{SWAP_NUN}{ADD_TAF} קשוח{ADD_HEY}!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
    .string "אני ממש נהנית לבדוק\n"
    .string "את המקום הזה.\p"
    .string "זה אתגר ששווה לי\n"
    .string "לחזור עליו שוב!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "אולי אוכל לגרום לפוקימון ציפור שלי\n"
	.string "לעוף מעל הקיר…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "גוואה! הרסתי הכל!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "איהיהי… כנראה שהפסדתי כי\n"
	.string "ניסיתי לרמות.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "אני נהיה מסוחרר מהדלתות המסתובבות\n"
	.string "האלה…$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "הכל מסתובב ומסתובב.\n"
	.string "אני לא יכול עם זה יותר…$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "נראה שאת{EMIT_HEY} לא מושפע{ADD_TAF} מזה בכלל.\n"
	.string "או שיש לך פרצוף פוקר?$"

