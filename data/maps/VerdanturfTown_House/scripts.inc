VerdanturfTown_House_MapScripts::
	.byte 0

VerdanturfTown_House_EventScript_Woman1::
	msgbox VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague, MSGBOX_NPC
	end

VerdanturfTown_House_EventScript_Woman2::
	msgbox VerdanturfTown_House_Text_DefeatEliteFourInARow, MSGBOX_NPC
	end

VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague:
	.string "רחוק מכאן, עמוק בעיר אבר גרנדה,\n"
	.string "נמצאת ליגת הפוקימון.\p"
	.string "המאמנים שמתאספים שם הם כולם\n"
	.string "מיומנים באופן מפחיד.$"

VerdanturfTown_House_Text_DefeatEliteFourInARow:
	.string "בליגת הפוקימון, אני חושב\n"
	.string "שהחוקים אומרים שאת{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} להילחם ברצ\l"
	.string "נגד הרביעיה העילית.\p"
	.string "אם הפסדת לאחד מהם, את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY}\n"
	.string "להתחיל את האתגר שלך שוב מהראשון.$
