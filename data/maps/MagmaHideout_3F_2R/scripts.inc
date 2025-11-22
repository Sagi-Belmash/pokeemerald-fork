MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "אני מבין כל מה שהמנהיג שלנו\n"
	.string "אומר. אבל את{EMIT_HEY} יודע{ADD_TAF} מה?\p"
	.string "לעשות דברים כמו לחפור פוקימון\n"
	.string "עתיק במיוחד ולגנוב למישהו מטאוריט...\p"
	.string "אני חושב שאנחנו הולכים קצת רחוק\n"
	.string "מדי. מה את{EMIT_HEY} חושב{ADD_TAF}?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "כן, אני חושב שאנחנו עושים משהו\n"
	.string "לא נכון איכשהו.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "את{EMIT_HEY} יודע{ADD_TAF}, להפסיד לך ניקה לי את הראש.\p"
	.string "בפעם הבאה שאני אראה את המנהיג שלנו,\n"
	.string "אני הולך לשאול אותו על מה שאנחנו עושים.$"

