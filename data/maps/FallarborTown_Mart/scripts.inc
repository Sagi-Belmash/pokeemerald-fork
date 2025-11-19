FallarborTown_Mart_MapScripts::
	.byte 0

FallarborTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FallarborTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	pokemartlistend

FallarborTown_Mart_EventScript_Woman::
	bufferspeciesname STR_VAR_1, SPECIES_SKITTY
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_PokefanM::
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_SKITTY
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_Mart_Text_DecidingSkittyEvolve:
	.string "אני מתקשה להחליט אם אני\n"
	.string "צריך לגרום ל{STR_VAR_1} שלי להתפתח או לא.\p"
	.string "אני רק צריך להשתמש באבן הירח הזו,\n"
	.string "אבל קשה כל כך להחליט…\p"
	.string "אם אתן לה להתפתח, היא תהיה\n"
	.string "הרבה יותר חזקה.\p"
	.string "אבל היא גם תראה שונה לגמרי.$"

FallarborTown_Mart_Text_Skitty:
	.string "{STR_VAR_1}: מיאו?$"

FallarborTown_Mart_Text_SellNuggetIFound:
	.string "גוש הזהב שמצאתי כאן…\n"
	.string "כנראה שאצטרך למכור אותו,\n"
	.string "מאחר שאין לו שימוש אחר.$"

