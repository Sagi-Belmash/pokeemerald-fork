PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "אני לא יכול לראות את אי התעתוע היום…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "או! אוי לי!\n"
	.string "אני יכול לראות את אי התעתוע היום!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "אי התעתוע…\p"
	.string "זה בטח מתגלה ומסתתר\n"
	.string "בהתאם לתנאי מזג האוויר\l"
	.string "שגורם לחזיונות להופיע.\p"
	.string "או שזה באמת מופיע ונעלם?$"

