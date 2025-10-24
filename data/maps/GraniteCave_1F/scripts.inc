GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "היי, את{EMIT_HEY}.\n"
	.string "זה נהיה חשוך להחריד בהמשך .\l"
	.string "זה יהיה קשוח לנסות לחקור.\p"
	.string "הבחור שעבר כאן קודם…\n"
	.string "סטיבן, נראה לי .\p"
	.string "הוא ידע איך להשתמש בהבזק, אז הוא\n"
	.string "בטח יסתדר, אבל…\p"
	.string "ובכן, לנו המטיילים, המוטו שלנו\n"
	.string "הוא לעזור למי שאנחנו פוגשים.\p"
	.string "אז הנה, אני נותן לך את זה.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "תלמד{ADD_YUD} את המכשיר נסתר הבזק\n"
	.string "לפוקימון ותשתמש{ADD_YUD} בו.\p"
	.string "זה מאיר אפילו את החושך העמוק\n"
	.string "של המערות.\p"
	.string "אבל, כדי להשתמש בו, צריך את תג המכון\n"
	.string "מהמכון פוקימון בדופורד.$"

