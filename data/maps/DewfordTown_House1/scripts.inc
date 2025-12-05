DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "יש הרבה מה להגיד על החיים באי\n"
	.string "קטן כזה בהרמוניה עם\l"
	.string "פוקימון והמשפחה.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "עזבתי את הנמל המרכזי בעיר\n"
	.string "סלייטפורט כשהתחתנתי עם בעלי כאן.\p"
	.string "החיים עוברים לאט באי\n"
	.string "הקטן הזה. אבל להיות מוקפת בים\l"
	.string "היפה -- גם זה אושר.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "{STR_VAR_1}: גוגוה!$"

