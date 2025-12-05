AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "מה כל כך מצחיק בזה שיש לי אבוב\n"
	.string "על הספינה?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "וואו, הבסת אותי לגמרי!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "לא קל לזרוק פוכדורים\n"
	.string "תוך כדי אחיזה באבוב!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "נכון שכיף פה?\n"
	.string "אני מתרגש רק מלהיות כאן!$"
