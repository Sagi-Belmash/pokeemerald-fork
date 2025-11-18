FortreeCity_DecorationShop_MapScripts::
	.byte 0

FortreeCity_DecorationShop_EventScript_PokefanM::
	msgbox FortreeCity_DecorationShop_Text_MerchandiseSentToPC, MSGBOX_NPC
	end

FortreeCity_DecorationShop_EventScript_Girl::
	msgbox FortreeCity_DecorationShop_Text_BuyingDeskForDolls, MSGBOX_NPC
	end

FortreeCity_DecorationShop_EventScript_ClerkDesks::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_Desks
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_DecorationShop_PokemartDecor_Desks:
	.2byte DECOR_SMALL_DESK
	.2byte DECOR_POKEMON_DESK
	.2byte DECOR_HEAVY_DESK
	.2byte DECOR_RAGGED_DESK
	.2byte DECOR_COMFORT_DESK
	.2byte DECOR_BRICK_DESK
	.2byte DECOR_CAMP_DESK
	.2byte DECOR_HARD_DESK
	pokemartlistend

FortreeCity_DecorationShop_EventScript_ClerkChairs::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_Chairs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_DecorationShop_PokemartDecor_Chairs:
	.2byte DECOR_SMALL_CHAIR
	.2byte DECOR_POKEMON_CHAIR
	.2byte DECOR_HEAVY_CHAIR
	.2byte DECOR_RAGGED_CHAIR
	.2byte DECOR_COMFORT_CHAIR
	.2byte DECOR_BRICK_CHAIR
	.2byte DECOR_CAMP_CHAIR
	.2byte DECOR_HARD_CHAIR
	pokemartlistend

FortreeCity_DecorationShop_Text_MerchandiseSentToPC:
    .string "המוצרים שאת{EMIT_HEY} קונה כאן נשלחים\n"
    .string "למחשב האישי שלך.\p"
    .string "זה נפלא! הלוואי שהם היו יכולים\n"
    .string "גם להביא לי אותם כך הביתה.$"

FortreeCity_DecorationShop_Text_BuyingDeskForDolls:
    .string "אני קונה שולחן יפה ואני\n"
    .string "שמה עליו את הבובות החמודות שלי.\p"
    .string "אם לא, כשאעצב את\n"
    .string "הבסיס הסודי שלי, הבובות שלי יתלכלכו\n"
    .string "או יחתכו מקוצים.$"

