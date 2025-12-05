Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} כתב{ADD_HEY} את הקוד הסודי\n"
	.string "על הדלת.\p"
	.string "”מאסטר הטריקים האהוב.“\n"
	.string "… … … … … … … …\p"
	.string "המנעול נפתח בלחיצה!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "לא הרבה מאמנים הגיעו\n"
	.string "עד לכאן.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "זה אומר שגם את{EMIT_HEY} חזק{ADD_HEY}…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "ניצחת את אלוף ליגת הפוקימונים?\n"
	.string "זה כבר יותר מדי!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "תחשיב{ADD_YUD} את{EMIT_HEY} עצמך בר{ADD_TAF} מזל שאת{EMIT_HEY}\n"
	.string "נלח{SWAP_MEM}{ADD_TAF} מולי!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "זה לא הגיוני!\n"
	.string "אני לא יכולה להפסיד!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "זה נס שניצחת אותי.\n"
	.string "את{EMIT_HEY} יכול{ADD_HEY} להשוויץ בזה.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "גם את{EMIT_HEY} נאבקת דרך אתגר\n"
	.string "בית הטריקים.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "אני מבין…\n"
	.string "יש לך סגנון יוצא דופן.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "לראות מישהו כמוך בטח ישמח\n"
	.string "את מאסטר הטריקים.$"

