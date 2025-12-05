PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag::
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	call_if_eq VAR_RESULT, 0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
	return

PacifidlogTown_House2_EventScript_MonAssessment::
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM::
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_GiveReturn::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_FRUSTRATION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays::
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_2, SPECIES_AZURILL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
	bufferspeciesname STR_VAR_2, SPECIES_AZURILL
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "אר-אהם!\p"
	.string "אני האדם הכי חשוב במועדון המעריצים\n"
	.string "של פוקימון, האח הקטן של יושב הראש.\p"
	.string "אני כאן נהנה מהחופשה שלי עם\n"
	.string "פוקימון, כן, בהחלט.$"

PacifidlogTown_House2_Text_AhYourPokemon:
	.string "אה!\n"
	.string "הפוקימון שלך…$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string "ברור שהוא מחבב אותך מאוד.\p"
	.string "פוקימון שמתוק ומקסים\n"
	.string "ראוי למ”מ כמו זה, לא?$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string "הממ…\n"
	.string "זה לא רע, אבל זה גם לא טוב.\p"
	.string "את{EMIT_HEY}, כמאמ{SWAP_NUN}{ADD_TAF}, צרי{SWAP_CHAF}{ADD_HEY} לתת\n"
	.string "קצת יותר מאמץ.$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string "יש לו מבט מרושע.\p"
	.string "פוקימון מפחיד שכזה\n"
	.string "ראוי למ”מ שכזה.$"

PacifidlogTown_House2_Text_ExplainReturnFrustration:
	.string "אם פוקימון מחבב אותך מאוד, כוחו\n"
	.string "של חזרה מוגבר.\p"
	.string "אם הוא לא מחבב אותך, כוחו\n"
	.string "של תסכול מוגבר.$"

PacifidlogTown_House2_Text_GetGoodTMInXDays:
	.string "או, כן. בעוד כ{STR_VAR_1} או כך ימים,\n"
	.string "אני אמור לקבל מ”מ טוב או שניים.\p"
	.string "תבוא{ADD_YUD} לבקר אותי זה.\n"
	.string "אני אתן לך מ”מ שמתאים\l"
	.string "לפוקימון שלך$"

PacifidlogTown_House2_Text_Rurii:
	.string "{STR_VAR_2}: רוריי.$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "נראה שהוא מאוד ידידותי כלפי\n"
	.string "המאמן.$"

PacifidlogTown_House2_Text_Rururi:
	.string "{STR_VAR_2}: רורורי!$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "נראה שהוא לא מחבב את המאמן\n"
	.string "יותר מדי.$"

