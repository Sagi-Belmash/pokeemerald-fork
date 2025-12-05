MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "אין לי עניין אישי איתך.\n"
	.string "אני פשוט מצייתת לפקודות!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "אולי הפסדתי, אבל…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "חפרנו משהו בלתי יאומן!\n"
	.string "ומצאנו את הכדור הכחול!\p"
	.string "כל מה שנותר זה שהמנהיג שלנו…\n"
	.string "פופופו… פוואהאהא!$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "אני לא סובל חום. אולי הייתי צריך\n"
	.string "להצטרף לצוות אקווה במקום…$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "כן, אולי אני באמת לא מתאים\n"
	.string "לצוות מגמה…$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "את{EMIT_HEY} לא מתגעגע{ADD_TAF} לים כשאת{EMIT_HEY}\n"
	.string "נמצא{ADD_TAF} במקום כזה?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "אפשר לשמוע כאן לפעמים רעידות.\p"
	.string "אולי זה הר הגעש רועד?\n"
	.string "או שזה גראו…\p"
	.string "וופס!\n"
	.string "לא, לא, לא חשוב!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "את{EMIT_HEY} לוח{SWAP_MEM}{ADD_TAF} לוהט{ADD_TAF}.\n"
	.string "בדיוק כמו הר געש!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "במקרה ניצחת הפעם,\n"
	.string "אבל זה לא משנה.\p"
	.string "המטרה של צוות מגמה עומדת\n"
	.string "להתממש!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "אחד החבר'ה שלנו נבהל כשגילה\n"
	.string "שאיבד את סמל המגמה שלו…\p"
	.string "רגע אחד!\n"
	.string "האם זה את{EMIT_HEY} שמצאת אותו?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "קשה לי להאמין לזה…$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "יש לי הרגשה שהתוכנית שלנו\n"
	.string "תסתיים בכישלון…$"

