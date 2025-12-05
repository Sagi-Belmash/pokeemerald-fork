SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "לפוקימון שלי יש אופי ממהר.\p"
	.string "המהירות שלו גבוהה יותר בהשוואה\n"
	.string "לפוקימונים האחרים שלי.\p"
	.string "אולי לאופי יש קשר לחוזק\n"
	.string "הנתונים של פוקימונים.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "את{EMIT_HEY} מאמ{SWAP_NUN}{ADD_TAF}, נכון?\p"
	.string "מאחר שהגעת לעיר סלייטפורט,\n"
	.string "בטח את{EMIT_HEY} הול{SWAP_CHAF}{ADD_TAF} לאוהל הקרבות.$"

