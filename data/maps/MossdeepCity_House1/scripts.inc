MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.string "הממ!\n"
	.string "ה{STR_VAR_1} שלך…$"

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.string "הוא אוהב {STR_VAR_1}ים,\n"
	.string "לא כך?\p"
	.string "לא, אני בטוח בזה! הוא בוודאי\n"
	.string "אוהב {STR_VAR_1}ים!$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.string "נראה שהוא לא אוהב ולא שונא\n"
	.string "שום פוקיגוש.$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.string "בעלי יכול לדעת איזה סוג של\n"
	.string "פוקיגוש פוקימון אוהב ממבט חפוז.$"

