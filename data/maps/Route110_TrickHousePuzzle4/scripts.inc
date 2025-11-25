Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} כתב{ADD_HEY} את הקוד הסודי\n"
	.string "על הדלת.\p"
	.string "”מאסטר הטריקים הוא מגניב.“\n"
	.string "… … … … … … … …\p"
	.string "המנעול נפתח בלחיצה!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "זה יותר מדי טרחה לחשוב על זה.\n"
	.string "אני רק רציתי להילחם!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "למרות שהפסדתי, אני עדיין הכי אוהבת\n"
	.string "להילחם!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "את{EMIT_HEY} לא מסכי{SWAP_MEM}{ADD_HEY}? הייתי הולכת\n"
	.string "לכל מקום אם היו שם מאמנים.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "הא! סלעים כאלה, אני יכול להזיז\n"
	.string "הצידה עם אצבע אחת!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "אני יכול לדחוף סלעים, אבל אני לא יכול לפתור\n"
	.string "את הפאזל…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "זה לא מספיק להיות שרירי…\n"
	.string "את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} גם להשתמש בראש. תהי{EMIT_HEY}{ADD_YUD} מבריק{ADD_HEY}!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "בית הטריקים נהיה יותר טריקי,\n"
	.string "לא כך?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "אההה!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "האם מישהו הצליח להגיע לסוף?$"

