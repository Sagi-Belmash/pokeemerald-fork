MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
    .string "אני אוהבת את כל הדברים המפחידים…\n"
    .string "זה כמו מחלה…\p"
    .string "כשהאני כאן…\n"
    .string "אני רועדת מפחד…$"

MtPyre_4F_Text_TashaDefeat:
    .string "להפסיד, אני לא אוהבת…$"

MtPyre_4F_Text_TashaPostBattle:
    .string "אני רוצה לראות דברים נוראיים…\n"
    .string "אני לא יכולה לעזוב…\p"
    .string "השאר{ADD_YUD}…\n"
    .string "לא תשאר{ADD_YUD} איתי?$"

