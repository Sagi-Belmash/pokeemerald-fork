MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "תודה שהשתמשת במערכת\n"
	.string "המתנה המסתורית.\p"
	.string "על ידי החזקת כרטיס הפלא הזה,\n"
	.string "תוכל{ADD_YUD} להשתתף בשאלון בחנות\l"
	.string "הפוקימון.\p"
	.string "השתמש{ADD_YUD} בשאלון הזה כדי להזמין\n"
	.string "מאמנים לעיר סוטופוליס.\p"
	.string "…ת{SWAP_NUN}{ADD_YUD} לי לגלות לך סיסמה סודית\n"
	.string "לשאלון:\p"
	.string "“תן לי\n"
	.string "מאמן מדהים”\p"
	.string "כת{EMIT_VAV}ב{ADD_YUD} זאת באחד הסקרים ושלח{ADD_YUD}\n"
	.string "זאת דרך מערכת\l"
	.string "התקשורת האלחוטית.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "תודה שהשתמשת במערכת\n"
	.string "המתנה המסתורית.\p"
	.string "מאמן הגיע לעיר סוטופוליס\n"
	.string "ומחפש אותך.\p"
	.string "אנו מקווים שתהנ{EMIT_HEY}{ADD_YUD} מהקרב\n"
	.string "נגד המאמן האורח.\p"
	.string "תוכל{ADD_YUD} להזמין מאמנים נוספים על ידי\n"
	.string "הזנת סיסמאות אחרות.\p"
	.string "נס{EMIT_HEY}{ADD_YUD} למצוא סיסמאות נוספות\n"
	.string "שעשויות לעבוד.$"
