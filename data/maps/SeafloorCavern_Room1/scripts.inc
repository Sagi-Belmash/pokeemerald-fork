SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "אנחנו לא צריכים פה ילד{ADD_HEY}!\n"
	.string "ל{SWAP_CHAF}{ADD_YUD} כבר הביתה!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "אני רוצה לחזור הביתה…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "אני רוצה קידום כדי שאוכל\n"
	.string "לפקד על החברים שלי…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "הצוללת הזו… היא קטנה מבפנים.\n"
	.string "כואב לי בכל הגוף!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "להפסיד כואב לי!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "הצוללת שגנבנו, אחי,\n"
	.string "זה פשוט טיול קשה,\l"
	.string "הכל כל כך צפוף בפנים!$"

