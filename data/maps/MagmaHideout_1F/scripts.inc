MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
    .string "כשבצוות מגמה עושים ספירה, אנחנו\n"
    .string "מקבלים משימות שמירה חשובות לפי\l"
    .string "הסדר שבו אנחנו עומדים.\p"
    .string "בגלל זה אני תקוע פה בפינה.\n"
    .string "אני תמיד מאחר לספירה!$"

MagmaHideout_1F_Text_Grunt1Defeat:
    .string "אני תמיד מאחר גם לאימונים!\p"
    .string "אני שונא להודות בזה, אבל אני חלש…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
    .string "אוקיי, אני אנסה להשקיע קצת יותר\n"
    .string "מהיום והלאה…$"

MagmaHideout_1F_Text_Grunt2Intro:
    .string "המנהיג שלנו אמר לנו לחפור אל תוך\n"
    .string "הר הארובה, אז חפרנו וחפרנו.\p"
    .string "ובמהלך החפירה נתקלנו במשהו\n"
    .string "שפשוט העיף לנו את המוח!\p"
    .string "מה מצאנו?\p"
    .string "פוהאהאה!\n"
    .string "אני אגיד לך אם תנצח{ADD_YUD}} אותי!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "אחחח!\n"
	.string "מפלה!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
    .string "בכל זאת אני לא אגיד לך.\n"
    .string "את{EMIT_HEY} תגל{EMIT_HEY}{ADD_YUD} כשתגיע{ADD_YUD} לשם!\p"
    .string "עדיף לשמור הפתעות\n"
    .string "לסוף, את{EMIT_HEY} לא חושב{ADD_TAF}?$"

