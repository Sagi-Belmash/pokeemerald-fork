LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
    .string "אשתי מחממת ביצה במעיינות\n"
    .string "החמים. זה מה שהיא סיפרה לי.\p"
	.string "היא השאירה שני פוקימונים במעון.\n"
	.string "והם גילו את הביצה הזו!$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "{STR_VAR_1}: פשוו!$"

