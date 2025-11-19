SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "מי את{EMIT_HEY}?\n"
	.string "מאיפה נכנסת?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "איבדתי את זה…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "אני לא מוצא את הדרך החוצה!\p"
	.string "אני לא מפחד. אל תבי{SWAP_NUN}{ADD_YUD} אותי לא נכון!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "מי את{EMIT_HEY}?\n"
	.string "לאן את{EMIT_HEY} חושב{ADD_TAF} שאת{EMIT_HEY} הול{SWAP_CHAF}{ADD_TAF}?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "נכשלתי בלנצח!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "השותף שלי שכח את המפה בצוללת!\p"
	.string "איך זה בלהיות חסר תועלת?$"

