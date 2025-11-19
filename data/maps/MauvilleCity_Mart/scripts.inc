MauvilleCity_Mart_MapScripts::
	.byte 0

MauvilleCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MauvilleCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_X_ACCURACY
	pokemartlistend

MauvilleCity_Mart_EventScript_ExpertM::
	msgbox MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats, MSGBOX_NPC
	end

MauvilleCity_Mart_EventScript_Man::
	msgbox MauvilleCity_Mart_Text_DecisionsDetermineBattle, MSGBOX_NPC
	end

MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats:
	.string "יש פריטים שמעלים זמנית את\n"
	.string "הנתונים של פוקימונים.\p"
	.string "אלה שאני מכיר שאתה משתמש בהם\n"
	.string "בקרב הם X התקפה ו־X הגנה…\p"
	.string "אני מאמין שיש עוד פריטים\n"
	.string "כאלה.$"

MauvilleCity_Mart_Text_DecisionsDetermineBattle:
	.string "להשתמש במהלך מסוים, או להשתמש\n"
	.string "בפריט במקום…\p"
	.string "ההחלטות של המאמן קובעות, לדעתי,\n"
	.string "איך הקרבות יסתיימו.$"

