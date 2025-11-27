FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "פרופ. קוזמו: או…\n"
	.string "אסור היה לי לתת לעצמי\l"
	.string "להיות מרומה ולגלות לצוות מגמה\l"
	.string "היכן ניתן למצוא מטאוריטים…\p"
	.string "המטאוריט הזה ממפלי המטאור…\n"
	.string "הוא לעולם לא יהיה שלי עכשיו…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "או!\n"
	.string "האא?\p"
	.string "הפריט הזה…\p"
	.string "יכול להיות?\p"
	.string "האם זה המטאוריט שצוות מגמה\n"
	.string "לקח ממפלי המטאור?\p"
	.string "בבקשה, אפשר לקבל אותו?\p"
	.string "אני לא מבקש אותו בחינם.\n"
	.string "מה דעתך בתמורה למ”מ הזה?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "פרופ. קוזמו: המ”מ הזה, הוא מייצג\n"
	.string "את תחושת התודה שלי.\l"
	.string "בבקשה השתמש{ADD_YUD} בו!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "פרופ. קוזמו: הו, אני לא מאמין.\n"
	.string "זה ממש, ממש נהדר!\p"
	.string "זה באמת הולך לעזור למחקר שלי!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "פרופ. קוזמו: או, אבל…\n"
	.string "אני מרוסק מאכזבה…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "פרופ' קוזמו: בבקשה, אפשר לקבל את\n"
	.string "המטאוריט הזה?\p"
	.string "אני לא מבקש אותו בחינם.\n"
	.string "מה דעתך בתמורה למ”מ הזה?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "פרופ. קוזמו יצא למפלי המטאור\n"
	.string "בדרך 411 עם כמה אנשים\l"
	.string "מצוות מגמה.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "פרופ. קוזמו המסכן…\n"
	.string "הוא כל כך מדוכא… אני מרחם עליו.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "תרא{EMIT_HEY}{ADD_YUD} את פרופ' קוזמו…\n"
	.string "הוא כל כך שמח! אני חושב שזה חמוד.$"

