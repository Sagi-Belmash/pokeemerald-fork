SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
    .string "הר המוקד…\p"
    .string "בקצהו יש שני כדורים מונחים זה לצד זה.\n"
    .string "האם ידעת?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
    .string "כן, שני כדורים זה לצד זה…\p"
    .string "המראה שלהם יחד…\n"
    .string "משהו בו מרגיע…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
    .string "האם כך?\n"
    .string "אולי כדאי לך לבקר ולראות…$"

