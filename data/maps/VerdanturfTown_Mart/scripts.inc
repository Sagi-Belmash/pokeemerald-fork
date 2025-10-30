VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_FLUFFY_TAIL
	pokemartlistend

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "לכל קרב פוקימון, X מיוחד\n"
	.string "הוא חיוני.\p"
	.string "הוא מחזק את העוצמה של מתקפות\n"
	.string "מסוימות, למרות שזה רק לקרב אחד.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "הם לא מוכרים שום מדריכי אסטרגיה\n"
	.string "לניצחון באוהל קרב…\p"
	.string "נראה שבסופו של דבר צריך\n"
	.string "לסמוך על השכל הישר…$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "הכדור קן עובד יותר נגד\n"
	.string "פוקימונים מוחלשים.\p"
	.string "ורדנטרף הוא המקום היחידי שאפשר\n"
	.string "לקנות אותו.$"

