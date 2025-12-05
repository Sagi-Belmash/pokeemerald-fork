PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "אנשים אמרו שהם ראו פוקימון\n"
	.string "עף גבוה מעל הואן.\p"
	.string "האם הוא עף כך כל הזמן?\n"
	.string "הוא לא צריך לנוח איפשהו?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "פוקימון שמיים!\n"
	.string "פוקימון שמיים!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "מאיפה הגעת?$"

PacifidlogTown_House4_Text_YesTown:
	.string "כן?\n"
	.string "עיירת כן?\p"
	.string "מעולם לא שמעתי על מקום כזה.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "לא? זה לא הגיוני.\n"
	.string "את{EMIT_HEY} חייב{ADD_TAF} לבוא מאיפשהו.\p"
	.string "או! חכ{EMIT_HEY}{ADD_YUD}! אל תגיד{ADD_YUD} לי שנולדת\n"
	.string "בתחתית הים?$"

