AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "דן: בזמן שחיפשנו אוצרות,\n"
	.string "מצאנו מאמ{SWAP_NUN}{ADD_TAF}!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "דן: לא הצלחנו לנצח למרות\n"
	.string "שעבדנו ביחד…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "דן: אנחנו לא מוצאים שום אוצרות…\n"
	.string "אני תוהה אם מישהו כבר לקח אותם?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "דן: אין לך אפילו שני פוקימונים.\n"
	.string "את{EMIT_HEY} לא יכול{ADD_HEY} לצפות לנצח אותנו ככה.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "קירה: אה?\n"
	.string "חיפשנו אוצרות.\l"
	.string "אבל במקום זה מצאנו מאמ{SWAP_NUN}{ADD_TAF}!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "קירה: אוי, כל כך חזק!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "קירה: איפה האוצרות יכולים להיות?\p"
	.string "כבר החלטתי מה אני אקנה\n"
	.string "כשנמצא את האוצרות!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "קירה: אה, אין לך שני פוקימונים?\n"
	.string "נצטרך להילחם בפעם אחרת!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "קירה: אה, את{EMIT_HEY} כל כך מרגיז{ADD_HEY} אותי!\n"
	.string "אני הולכת לרשום אותך בגלל זה!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "דן: חיפשנו אוצרות\n"
	.string "כל הזמן הזה.\p"
	.string "הפוקימונים שלנו גם התחזקו.\n"
	.string "ת{SWAP_NUN}{ADD_YUD} לנו להראות לך, בסדר?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "דן: את{EMIT_HEY} חזק{ADD_HEY}, כרגיל!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "דן: אנחנו לא מוצאים שום אוצרות,\n"
	.string "אנחנו מפסידים בפוקימון…\p"
	.string "אני רוצה הביתה… אבל אם אני אומר את זה,\n"
	.string "היא מתעצבנת עליי…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "דן: אין לך אפילו שני פוקימונים.\n"
	.string "את{EMIT_HEY} לא יכול{ADD_HEY} לצפות לנצח אותנו ככה.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "קירה: אה? נפגשים שוב!\p"
	.string "בדיוק כמונו, גם את{EMIT_HEY} עדיין לא\n"
	.string "ויתרת על חיפוש האוצרות, נכון?\p"
	.string "רוצה לעשות שהמפסיד{ADD_HEY} צרי{SWAP_CHAF}{ADD_HEY}\n"
	.string "לוותר על החיפושים?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "קירה: או, הפסדנו שוב…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "קירה: אנחנו לא עוזבים עד שנאמן\n"
	.string "את הפוקימונים שלנו עוד קצת ונמצא\l"
	.string "את האוצרות כאן!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "קירה: אה, אין לך שני פוקימונים?\n"
	.string "נצטרך להילחם בפעם אחרת!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "אני לא טובה בשחייה,\n"
	.string "אבל אני טובה בקרבות!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "אופס.\n"
	.string "זה לא הלך כל כך טוב.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "ללכת יחפה בספינה הזאת\n"
	.string "זה די מגעיל.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "כוח וחמלה…\n"
	.string "אלו האוצרות של מאמן!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "אה, יש בך משהו\n"
	.string "שנוצץ.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "בתא מסוים על הספינה,\n"
	.string "ראיתי משהו נוצץ.$"
