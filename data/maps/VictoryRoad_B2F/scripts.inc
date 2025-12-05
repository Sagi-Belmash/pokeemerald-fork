VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "התאמנתי יחד עם כל המשפחה שלי,\n"
	.string "כל אחד מאיתנו!\l"
	.string "אני לא מפסיד לאף אחד!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "טוב יותר מהמשפחה שלי?!\n"
	.string "האם זה אפשרי?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "הייתי טוב יותר מכולם במשפחה\n"
	.string "שלי. מעולם לא הפסדתי לפניכן…\p"
	.string "איבדתי את הביטחון שלי…\n"
	.string "אולי אלך הביתה…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "שמעתי שיש כאן איזה\n"
	.string "ילד{ADD_HEY} קט{SWAP_NUN}{ADD_HEY} וקשוח{ADD_HEY}. האם הם מתכוונים אליך?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "השרץ הקט{SWAP_NUN}{ADD_HEY} קשוח{ADD_HEY}!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "השמועות ששמעתי, שהילד{ADD_HEY} הקט{SWAP_NUN}{ADD_HEY}\n"
	.string "הקשוח{ADD_HEY} מהעיר פטלבורג.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "את{EMIT_HEY} בטח כבר קצת עיי{SWAP_PEY}{ADD_HEY}.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "אין שום סימני עייפות!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "דרך הניצחון וליגת הפוקימון\n"
	.string "הם אתגרים ארוכים ומתישים.\l"
	.string "היזהר{ADD_YUD} מעייפות!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "את{EMIT_HEY} לא צרי{SWAP_CHAF}{ADD_HEY} להיות שאנ{SWAP_NUN}{ADD_YUD}{ADD_TAF} רק\n"
	.string "בגלל שיש לך הרבה תגי מכון.\p"
	.string "תמיד יהיה מישהו\n"
	.string "שטוב יותר ממך!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "את{EMIT_HEY} טוב{ADD_HEY} יותר ממני!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "הב{ADD_YUD}ט{ADD_YUD} על התגים שאספת\n"
	.string "וזכ{EMIT_VAV}ר{ADD_YUD} את המאמנים שאיתם התמודדת.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "הגעתי עד כאן, אבל המתח\n"
	.string "גורם לי לכאבי בטן נוראיים…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "אוו…\n"
	.string "זה כואב…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "אני לא יכול שלא להיות לחוץ כשאני יודע\n"
	.string "שאני מתקרב לליגת הפוקימון.\p"
	.string "כל מה שאני יכול לעשות זה להעמיד פני רגוע.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "העלית שבין העלית מתאספת\n"
	.string "במערה הזו.\p"
	.string "איך את{EMIT_HEY} מוצא{ADD_TAF} את זה?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "לא נבהל אפילו במעט!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "יש לך אומץ! אני אוהבת את זה!\n"
	.string "תמשי{SWAP_CHAF}{ADD_YUD} כך!$"

