MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "היי שם, מאמ{SWAP_NUN}{ADD_TAF}!\n"
	.string "החכה מעולה היא באמת מעולה!\p"
	.string "תגיד{ADD_YUD} מה שבא לך, אבל התותחית הזו יכולה"
	.string "לתפוס פוקימונים מקרקעית הים!\p"
	.string "מה את{EMIT_HEY} חושב{ADD_TAF}?\n"
	.string "את{EMIT_HEY} רוצה אותה, נכון?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "בטח, בטח!\n"
	.string "אחרי הכל, החכה המעולה היא באמת מעולה!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "אם יש מים איפשהו, נס{EMIT_HEY}{ADD_YUD} להטיל\n"
	.string "את החכה שלך ותרא{EMIT_HEY}{ADD_YUD} מה נותן ביס!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "האא?\n"
	.string "את{EMIT_HEY} לא אוהב{ADD_TAF} לדוג?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "צא{ADD_YUD} לצוד פוקימונים מקרקעית הים\n"
	.string "עם החכה המעולה שלך.$"

