Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "לאנט: או! {PLAYER}{KUN}!\p"
	.string "מצטערת שהכל נורא צפוף…\n"
	.string "כשאני שקועה במחקר,\l"
	.string "זה מסתיים ככה…\p"
	.string "זה מביך… בבקשה תשמ{EMIT_VAV}ר{ADD_YUD}\n"
	.string "על זה בסוד בתמורה לזה.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "אפשר לייעץ לגבי מערכת\n"
	.string "אחסון הפוקימונים שלי?\p"
	.string "כדאי לך לארגן את הקופסאות שלך כך\n"
	.string "שתוכל{ADD_YUD} לדעת איזה פוקימון נמצא בהם.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "אלו הן הערות מחקר של לאנט.\n"
	.string "יש מידע על הקופסאות.\p"
	.string "לעצב קופסאות לאחסון 03 פוקימונים בכל אחת.\p"
	.string "כל מאמן יוכל לאחסן 024\n"
	.string "פוקימונים במערכת המחשב.\p"
	.string "להמשיך לקרוא?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "יש להוסיף מערכת סימון כדי\n"
	.string "להקל על ארגון הפוקימונים.\p"
	.string "השם והטפט של כל קופסה יהיו\n"
	.string "ניתנים לשינוי כדי לרצות\l"
	.string "את הפוקימונים המאחוסנים.\p"
	.string "להמשיך לקרוא?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "כאשר מאחסנים פוקימון, הוא צריך\n"
	.string "להישלח לקופסה שנבדקה אחרונה.\p"
	.string "אם הקופסה מלאה, הפוקימון\n"
	.string "יועבר לקופסה הבאה.\p"
	.string "במילים אחרות, כשקופסה נבדקת,\n"
	.string "היא נבחרת אוטומטית כקופסה\l"
	.string "לאחסון פוקימונים.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} סגר{ADD_HEY} את החוברת.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "יש הודעת דואר ממישהו במחשב.\p"
	.string "“… … … … … … …\p"
	.string "”מערכת האחסון שלך נוחה יותר משלי.\p"
	.string "”יש לה הרבה תכונות ידידותיות למשתמש\n"
	.string "שעושות אותה גם כיפית וגם שימושית.\p"
	.string "“זה משמח אותי שלחקתי חלק\n"
	.string "בפיתוח שלה.\p"
	.string "“מקווה שתמשיכי לחקור\n"
	.string "את מערכות האחסון.\p"
	.string "”מביל\n"
	.string "… … … … … … … …“$"

