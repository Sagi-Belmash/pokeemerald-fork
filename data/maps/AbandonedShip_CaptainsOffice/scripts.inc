AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
    .string "אני חוקר את הספינה הזאת בשם\n"
    .string "קפטן סטרן.\p"
    .string "הוא גם ביקש ממני למצוא את הסורק,\n"
    .string "אבל לא היתה לי הצלחה…$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "הו! זה הסורק!\p"
	.string "תקשיב{ADD_YUD}, את{EMIT_HEY} יכול{ADD_HEY} להעביר\n"
	.string "את זה לקפטן סטרן?\p"
	.string "אני רוצה לחקור את הספינה הזאת\n"
	.string "עוד קצת.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "הספינה הזאת נקראת ס.ס. קקטוס.\n"
	.string "נראה שהיא מתקופה מוקדמת יותר.$"

