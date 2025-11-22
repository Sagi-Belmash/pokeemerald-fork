MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "כל מיני יצורים משוטטים במדרונות\n"
	.string "הר המוקד…\p"
	.string "אי אפשר לדעת מה עלול לקרות.\n"
	.string "קח{ADD_YUD} את זה. זה לטובתך.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "ת{SWAP_NUN}{ADD_YUD} לפוקימון שלך להחזיק את\n"
	.string "התג טיהור.\p"
	.string "זה יעזור להרחיק פוקימונים פראיים.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "האם באת לחלוק כבוד\n"
	.string "לרוחות שעזבו את הפוקימונים?\p"
	.string "את{EMIT_HEY} בטח דואג{ADD_TAF} מאוד לפוקימונים שלך.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "זה מקום המנוחה האחרון של\n"
	.string "{STR_VAR_1}. אני מוקיר אותו…$"

