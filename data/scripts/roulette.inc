Roulette_EventScript_Table1::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play::
	special PlayRoulette
	waitstate
	end
Roulette_Text_PlayMinimumWagerIsX::
	.string "ההימור המינימלי בשולחן הזה הוא\n"
	.string "{STR_VAR_1}. רוצה לשחק?$"

Roulette_Text_NotEnoughCoins::
	.string "אין לך מספיק מטבעות.$"

Roulette_Text_SpecialRateTable::
	.string "שולחן בתעריף מיוחד עכשיו!$"

Roulette_Text_ControlsInstruction::
	.string "בחר{ADD_YUD} את סכום ההימור בעזרת + משטח\n"
	.string "הבקרה, ואז לח{SWAP_TZADIK}{ADD_YUD} על כפתור A.$"

Roulette_Text_ItsAHit::
	.string "פגיעה!$"

Roulette_Text_Jackpot::
	.string "ג'קפוט!$"

Roulette_Text_NothingDoing::
	.string "לא קרה כלום!$"

Roulette_Text_YouveWonXCoins::
	.string "הרווחת {STR_VAR_1} מטבעות!$"

Roulette_Text_NoCoinsLeft::
	.string "לא נשארו לך מטבעות…$"

Roulette_Text_KeepPlaying::
	.string "להמשיך לשחק?$"

Roulette_Text_BoardWillBeCleared::
	.string "לוח הרולטה יימחק.$"

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.string "אין לך ארנק מטבעות.$"

Roulette_Text_CoinCaseIsFull::
	.string "ארנק המטבעות שלך מלא!\n"
	.string "אפשר להחליף מטבעות בפרסים.$"
