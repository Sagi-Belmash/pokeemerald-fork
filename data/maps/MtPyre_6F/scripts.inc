MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "כשאני כאן…\n"
	.string "זורם אליי כוח מוזר…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "הכוח הולך ודועך…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "אולי הכוח מגיע מהרוחות\n"
	.string "של פוקימונים בשינה סוערת כאן…$"

MtPyre_6F_Text_ValerieRegister:
	.string "פופופו… הפסדתי בקרב, אבל…\n"
	.string "יש לי יכולת קטנה כזו…\p"
	.string "מבלי שאניח את ידיי על\n"
	.string "הפוקידע שלך… הייאה!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "מאחוריך…\n"
	.string "מה זה…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "משהו נעלם…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "הפוקימונים נחים כאן…\n"
	.string "לפעמים, הם משחקים…$"

MtPyre_6F_Text_CedricIntro:
	.string "האם איבדת את הדרך?\n"
	.string "אל תפחד{ADD_YUD} כי אני כאן!$"

MtPyre_6F_Text_CedricDefeat:
	.string "לא היית אבוד?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "הייתה לי הרגשה שמאמ{SWAP_NUN}{ADD_TAF} אבוד{ADD_HEY}\n"
	.string "{EMIT_YUD}{ADD_TAF}היה בפאניקה ויהיה קל להביס אות{EMIT_VAV}{ADD_HEY}.\p"
	.string "זה מלוכלך ולא אנסה זאת שוב…$"

