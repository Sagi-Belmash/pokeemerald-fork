SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "אחחח! נמאס לי ואני מותש מלנקות\n"
	.string "את המקום הענקי הזה!\p"
	.string "בוא{ADD_YUD} נעשה קרב קצר!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "אחי הקטן, הפסדתי!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "אנחנו האחים לניקיון!\p"
	.string "הזקן שופך את החומר ניקוי,\n"
	.string "והצעיר עושה את השפשוף!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "זאת התחתית של גוף הספינה.\n"
	.string "יש כאן מקום רב.\l"
	.string "זה יהיה מתאים לקרב פוקימונים.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "אחי הגדול, הפסדתי!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "אנחנו האחים לניקיון!\p"
	.string "הזקן שופך את החומר ניקוי,\n"
	.string "והצעיר עושה את השפשוף!$"

