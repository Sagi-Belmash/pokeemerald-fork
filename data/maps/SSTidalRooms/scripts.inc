SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end
SSTidalRooms_Text_TakeRestOnBed:
	.string "יש כאן מיטה…\n"
	.string "בוא{ADD_YUD} ניקח מנוחה.$"

SSTidalRooms_Text_ColtonIntro:
	.string "אני מפליג לעתים קרובות לעיר ליליקוב.\p"
	.string "אני נהנה להשתתף בתחרויות,\n"
	.string "את{EMIT_HEY} מבי{SWAP_NUN}{ADD_HEY}.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "זה היה קרב מהנה!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "אני מתרגש כל כך כשאני מדמיין איזה סוגי\n"
	.string "פוקימונים אני אזכה לראות בתחרות\l"
	.string "הבאה. הציפייה לכך מלהיבה!$"

SSTidalRooms_Text_MicahIntro:
	.string "האם החברים שלך חזקים?$"

SSTidalRooms_Text_MicahDefeat:
	.string "החברים שלך, אכן, חזקים.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "חברים לא חייבים להיות בני אנוש.\n"
	.string "בשבילי, פוקימונים הם חברים יקרים!$"

SSTidalRooms_Text_ThomasIntro:
	.string "ילד{ADD_HEY}…\n"
	.string "האם דפקת בדלת?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "יש לקבל הפסד ללא בהלה\n"
	.string "או פאניקה.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "לא להתרגז לעולם בשום מצב הוא\n"
	.string "קוד ההתנהגות של הג'נטלמן.$"

SSTidalRooms_Text_JedIntro:
	.string "ג'ד: אני מרגיש קצת ביישן לגבי זה, אבל…\n"
	.string "אנחנו נראה לך את הכוח המאוהב שלנו!$"

SSTidalRooms_Text_JedDefeat:
	.string "ג'ד: אנחה…$"

SSTidalRooms_Text_JedPostBattle:
	.string "ג'ד: זו הפעם הראשונה שהכוח המאוהב\n"
	.string "שלנו לא הצליח לגבור!\l"
	.string "את{EMIT_HEY} בטח מאמ{SWAP_NUN}{ADD_TAF} מדהי{SWAP_MEM}{ADD_HEY}!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "ג'ד: יש לך רק פוקימון אחד?\n"
	.string "זה לא בודד מדי?$"

SSTidalRooms_Text_LeaIntro:
	.string "לאה: אני מרגישה קצת מטופשת, אבל…\n"
	.string "אנחנו נראה לך את הכוח המאוהב שלנו!$"

SSTidalRooms_Text_LeaDefeat:
	.string "לאה: או, בוו!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "לאה: אני לא מאמינה!\n"
	.string "הכוח המאוהב שלנו נכשל…\l"
	.string "את{EMIT_HEY} בטח מאמ{SWAP_NUN}{ADD_TAF} מדהי{SWAP_MEM}{ADD_HEY}!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "לאה: רציתי להילחם…\n"
	.string "אבל אין לך אפילו שני פוקימונים…$"

SSTidalRooms_Text_GarretIntro:
	.string "אה, הגעת בדיוק בזמן.\p"
	.string "משעמם לי, את{EMIT_HEY} מבי{SWAP_NUN}{ADD_HEY}.\n"
	.string "את{EMIT_HEY} יכול{ADD_HEY} לבדר אותי.$"

SSTidalRooms_Text_GarretDefeat:
	.string "…זה יספיק.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "אולי אבקש מאבא שלי שיקנה\n"
	.string "לי יאכטה.\l"
	.string "יאכטה בשבילי ובשביל הפוקימונים!$"

SSTidalRooms_Text_NaomiIntro:
	.string "או, את{EMIT_HEY} מאמ{SWAP_NUN}{ADD_TAF} כה מקסי{SWAP_MEM}{ADD_HEY}.\n"
	.string "תרצ{EMIT_HEY}{ADD_YUD} לשתות תה?\l"
	.string "או שאת{EMIT_HEY} מעדי{SWAP_PEY}{ADD_HEY} קרב?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "אני מבין.\n"
	.string "את{EMIT_HEY} מהטיפוס הפעיל.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "שייט עולמי על ספינת יוקרה\n"
	.string "בעלת קסם משלו, אני חייבת לומר…\p"
	.string "אבל, אני מודה שיש צד מושך\n"
	.string "בסיור בהואן באמצעות מעבורת.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "אה… היי! אני… אני לא נראה חשוד!\n"
	.string "אה… את{EMIT_HEY} יכול{ADD_HEY} לקחת את זה! בחינם!\p"
	.string "זה… באמת, לא חטפתי את זה\n"
	.string "ממישהו! לעולם לא הייתי עושה דבר כזה!\l"
	.string "זה נקי! את{EMIT_HEY} יכול{ADD_HEY} להשתמש בזה!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "חטיפה גונבת את ההשפעות המועילות\n"
	.string "של מהלכים מסוימים לפני שהן יכולות להיות\l"
	.string "בשימוש על ידי יריב או בעל ברית.$"

