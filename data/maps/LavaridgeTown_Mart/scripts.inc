LavaridgeTown_Mart_MapScripts::
	.byte 0

LavaridgeTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPEED
	pokemartlistend

LavaridgeTown_Mart_EventScript_ExpertM::
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_OldWoman::
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
	end

LavaridgeTown_Mart_Text_XSpeedFirstStrike:
	.string "השתמש{ADD_YUD} בX התקפה כדי להוסיף מהירות\n"
	.string "של פוקימון בקרב.\p"
	.string "זה יעזור לו לתקוף ראשון--יתרון ברור!$"

LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney:
	.string "בפסת הר הארובה, יש תוצר מקומי\n"
	.string "שניתן לקנות רק שם.\p"
	.string "ת{SWAP_NUN}{ADD_YUD} אותו לפוקימון--הוא ישמח מאוד.$"

