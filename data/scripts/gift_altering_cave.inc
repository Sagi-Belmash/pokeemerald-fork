MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "תודה שהשתמשת במערכת המתנה\n"
	.string "המסתורית.\p"
	.string "מסתבר שיש שמועה על\n"
	.string "תצפיות של פוקימון נדיר.\p"
	.string "התצפיות הגיעו, על פי דיווחים\n"
	.string "ממערת השינוי בדרך 301.\p"
	.string "אולי יהיה כדאי לך\n"
	.string "לחקור את השמועה הזו.$"
