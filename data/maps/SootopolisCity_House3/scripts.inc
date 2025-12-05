SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "את{EMIT_HEY} מאמ{SWAP_NUN}{ADD_TAF} פוקימונים, נכון?\p"
	.string "לחואן מסוטופוליס יש הרבה מעריצים.\n"
	.string "אפילו יותר מהתלמיד שלו, וולאס!\p"
	.string "יש לך כמה?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "אה, אז את{EMIT_HEY} בטח די חזק{ADD_HEY}.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "אוי, יקיר{ADD_TAF}י…\n"
	.string "זה קצת בודד.\p"
	.string "תנס{EMIT_HEY}{ADD_YUD} לעבוד קצת יותר קשה כדי\n"
	.string "לזכות בקהל מעריצים.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "מעריצים מסורים מגיעים אפילו\n"
	.string "מחוץ להואן.\p"
	.string "זה היה ממש מטורף כשביקרתי\n"
	.string "במועדון המעריצים בליליקוב.$"

