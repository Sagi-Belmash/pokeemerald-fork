MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "מה עשיתי כדי לקבל תפקיד שמירה\n"
	.string "כזה?\p"
	.string "האוזן השמאלית שלי בוערת!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "אני מתחיל לסבול מתשישות החום…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "את{EMIT_HEY} חושב{ADD_TAF}שזה מוזר שאנחנו לובשים\n"
	.string "קפוצ'ונים בתוך הר געש מלא לבה?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "הצטרפנו כדי לעזור למנהיגנו\n"
	.string "להגשים את החזון המדהים שלו.\p"
	.string "לא אכפת לי אם את{EMIT_HEY} עם צוות אקווה\n"
	.string "או סתם ילד{ADD_HEY} שעובר{ADD_TAF} כאן.\p"
	.string "אף אחד לא יתעסק איתנו ויזכה\n"
	.string "לברוח מזה בקלות!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "או, לא!\n"
	.string "לא ניתן לסמוך עליך בכלל!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "תקשיב{ADD_YUD} לי.\n"
	.string "צוות מגמה צודק\p"
	.string "אל תקשיב{ADD_YUD} לצוות אקווה.\n"
	.string "אל תאמי{SWAP_NUN}{ADD_YUD} לשקרים שלהם!$"

