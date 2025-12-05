SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_AZUMARILL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "תקשיב{ADD_YUD}, ואני אספר לך משהו\n"
	.string "טוב.\p"
	.string "אומרים שיש חורבה עתיקה\n"
	.string "בים שבסביבה.\p"
	.string "יכול להיות שיש שם אוצרות\n"
	.string "שממש מחכים להתגלות.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "אוצרות עתיקים…\p"
	.string "זה היה יפה אם הם היו קיימים, אבל\n"
	.string "גם אם לא, זה היה כל כך\l"
	.string "יפה לקחת טיול תת ימי עם\l"
	.string "הפוקימון שלי.$"

SootopolisCity_House4_Text_Azumarill:
	.string "{STR_VAR_1}: מארוריי.$"

