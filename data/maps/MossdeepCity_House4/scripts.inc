MossdeepCity_House4_MapScripts::
	.byte 0

MossdeepCity_House4_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_CanBattleAtSecretBases::
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NinjaBoy::
	lock
	faceplayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_House4_EventScript_NoSecretBase
	special GetSecretBaseNearbyMapName
	msgbox MossdeepCity_House4_Text_YouMadeSecretBaseNearX, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NoSecretBase::
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_SKITTY
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MossdeepCity_House4_Text_BrotherLikesToFindBases:
	.string "האח הקטן שלי אומר שהוא אוהב ללכת\n"
	.string "ולמצוא בסיסים סודיים של אנשים.$"

MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle:
	.string "האח הקטן שלי אומר שהוא אוהב\n"
	.string "לבקר בבסיסים סודיים של אנשים\l"
	.string "ולעשות קרבות פוקימון.$"

MossdeepCity_House4_Text_YouMadeSecretBaseNearX:
	.string "זה את{EMIT_HEY} שהכנת בסיס סודי\n"
	.string "ליד {STR_VAR_1}?$"

MossdeepCity_House4_Text_MakeSecretBase:
	.string "את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} להכין בסיס סודי\n"
	.string "איפשהו. אני אלך למצוא אותו!$"

MossdeepCity_House4_Text_Skitty:
	.string "{STR_VAR_1}: מיאאן?$"

