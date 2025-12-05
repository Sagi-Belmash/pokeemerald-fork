DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "הנה, תראה את זה!\p"
	.string "זה צעיף משי. הוא בדיוק בחזית\n"
	.string "האופנה, כן!\p"
	.string "אה, אני רואה את העיניים שלך נוצצות!\n"
	.string "את{EMIT_HEY} מערי{SWAP_CHAF}{ADD_HEY} את הסגנון המרהיב שלי!\p"
	.string "אה, איזה תענוג!\n"
	.string "קח{ADD_YUD}, אני רוצה שיהיה לך!$"

DewfordTown_House2_Text_NoRoom:
	.string "אה, אין לך מקום?\p"
	.string "עכשיו, תקשיב{ADD_YUD} טוב, הצעיף הזה\n"
	.string "הוא חובה! למה, הייתי מוכר את כל\l"
	.string "הפריטים שלי בשביל להשיג אותו!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "הצעיף משי מגביר את הכוח של\n"
	.string "מהלכים מסוג רגיל.\p"
	.string "זה צעיף נפלא שילך\n"
	.string "עם כמעט כל פוקימון!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "וואו, טרחת לחצות את הים\n"
	.string "כדי לבקר בדופורד?\p"
	.string "אולי באת לכאן כי\n"
	.string "שמעת על בראולי?\p"
	.string "הוא כל כך מגניב…\n"
	.string "כולם מעריצים אותו.$"

