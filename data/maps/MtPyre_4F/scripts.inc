MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
    .string "מורה…\n"
    .string "בבקשה שמור על התקדמותי!$"

MtPyre_5F_Text_AtsushiDefeat:
    .string "מורה…\n"
    .string "סלח לי בבקשה!$"

MtPyre_5F_Text_AtsushiPostBattle:
    .string "עד שאשתפר, המורה שלי, שמנוחתו\n"
    .string "כאן, לא ימצא שקט אמיתי…$"

