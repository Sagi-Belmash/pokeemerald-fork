DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "מה באופנה? למה, זה חייב להיות\n"
	.string "”{STR_VAR_1}“!\p"
	.string "אני לא יכולה לדמיין איך החיים היו נראים\n"
	.string "בלי ”{STR_VAR_1}“!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "מה באופנה? למה, זה חייב להיות\n"
	.string "”{STR_VAR_1}“!\p"
	.string "אבל אני מתחילה להשתעמם מזה.\p"
	.string "אני צריכה לחפש את הדבר הגדול הבא.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "אני מלמדת את הפוקימון שלי על\n"
	.string "”{STR_VAR_1}“,\l"
	.string "אבל זה לא הולך טוב.\p"
	.string "זה קצת יותר מדי, אני חושבת.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "אני לומד על הטרנד החדש\n"
	.string "”{STR_VAR_1}“ עכשיו.\p"
	.string "זה נכון שיש קשר עמוק\n"
	.string "בין ”{STR_VAR_1}“\l"
	.string "ל”{STR_VAR_2}“?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "אה!\n"
	.string "אז, התחושה שלי הייתה נכונה!\p"
	.string "אני צעד אחד קרוב יותר להיות\n"
	.string "אופנתי ומעודכן, יאללה!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "מה?!\n"
	.string "זה ככה?!\p"
	.string "זה לא קל לאיש מבוגר כמוני\n"
	.string "להישאר מעודכן בטרנדים!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "כל העסק הזה עם\n"
	.string "“{STR_VAR_1}”…\l"
	.string "אין על זה תוכנית טלוויזיה?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "מעבר לים…\p"
	.string "האם ”{STR_VAR_1}“\n"
	.string "אפילו יותר פופולרי?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "אני אוסף מוצרים רשמיים של\n"
	.string "”{STR_VAR_1}“.\p"
	.string "יש לי בובות רשמיות\n"
	.string "של ”{STR_VAR_1}“…\p"
	.string "בגדים ממותגים רשמית\n"
	.string "של ”{STR_VAR_1}“…\p"
	.string "וספרי תמונות ברישיון רשמי\n"
	.string "של ”{STR_VAR_1}“.\p"
	.string "חהחה, אני שולט!\n"
	.string "אני לא משתף איתך כלום!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "זיהוי טוב\n"
	.string "”{STR_VAR_1}“ &\l"
	.string "”{STR_VAR_1}“ רע…\p"
	.string "הקשר בין\n"
	.string "”{STR_VAR_1}“\l"
	.string "ופוקימון…\p"
	.string "”{STR_VAR_1}“\n"
	.string "שימושי…\p"
	.string "עמוס בספרים על\n"
	.string "”{STR_VAR_1}.“$"

DewfordTown_Hall_Text_TrendsScream:
	.string "”הצרחה של\n"
	.string "{STR_VAR_1}“ זאת הכותרת.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "”החיוך של\n"
	.string "{STR_VAR_1}“ זאת הכותרת.$"

DewfordTown_Hall_Text_LastTrend:
	.string "זה נקרא “ה{STR_VAR_1}\n"
	.string "האחרון”.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "זה נקרא “לידתו של\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "ראיתי את ”{STR_VAR_1}“!\n"
	.string "מגניב, הא?\p"
	.string "זה, כאילו, הדבר הכי מגניב כרגע!\p"
	.string "זה היה מדהים!\n"
	.string "זה היה הדבר האמיתי, או כן!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "או, חא, חא, חא.\p"
	.string "ה”{STR_VAR_1}“ לכאורה\n"
	.string "את{EMIT_HEY} טוע{SWAP_NUN}{ADD_TAF} שראית אותו--\l"
	.string "זה לא זה.\p"
	.string "הדבר האמיתי הוא יותר…\n"
	.string "איך אני אגיד את זה?\l"
	.string "חד יותר, אבל גם רגוע יותר!\p"
	.string "אה, לא משנה. זה מדהים!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "היי, תשמע{ADD_YUD}, חיברתי שיר נושא על\n"
	.string "”{STR_VAR_1}.“\p"
	.string "”{STR_VAR_1}“\n"
	.string "ממש פופולרי כרגע.\p"
	.string "אוקיי, תשמע{ADD_YUD}!\n"
	.string "… …\p"
	.string "או!\n"
	.string "{STR_VAR_1}!\p"
	.string "מדהים\n"
	.string "{STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "… …\p"
	.string "אני מעז לומר, חבוב{ADD_HEY}, ישתלם לך לעבוד\n"
	.string "לעבוד על השירה שלך לפני\l"
	.string "שתתעסק{ADD_YUD} עם\l"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "בכל מקרה, כמו שאמרתי קודם,\n"
	.string "צריך להתאסף ולארגן מסיבה על\l"
	.string "”{STR_VAR_1}“\l"
	.string "על האי.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "או, רעיון נהדר!\p"
	.string "ככה סוף סוף נוכל לקבוע\n"
	.string "אחת ולתמיד מי הכי טוב\l"
	.string "ב”{STR_VAR_1}.“\l"
	.string "מבריק, באמת!\p"
	.string "מהיום, החיים שלנו יסתובבו\n"
	.string "סביב ”{STR_VAR_1}“!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "I was thinking, though…\p"
	.string "Wouldn't you agree that\n"
	.string "“{STR_VAR_1}” has\l"
	.string "grown from being something trendy to\l"
	.string "being a part of our daily lives?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Beg pardon?\n"
	.string "That much, what?\p"
	.string "However, it's true that\n"
	.string "“{STR_VAR_1}”\l"
	.string "weighs heavily on your mind, whether\l"
	.string "you're awake or asleep.\p"
	.string "Absolutely, you're the\n"
	.string "“{STR_VAR_1}”\l"
	.string "PROFESSOR, old sport!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "If you and me team up as a combo,\n"
	.string "we'll be invincible when it comes to all\l"
	.string "things “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Spot on, my friend!\p"
	.string "We shall be the\n"
	.string "“{STR_VAR_1}” DUO!\p"
	.string "Isn't that a ripe image?\n"
	.string "Hahahah!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "For me, SLUDGE BOMB is at the peak\n"
	.string "of popularity. It's the one.\p"
	.string "Hunh? You're telling me that you don't\n"
	.string "know about SLUDGE BOMB?\p"
	.string "That's outright pitiful.\n"
	.string "I'll give you one.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "I love SLUDGE BOMB.\p"
	.string "But POKéMON with the move\n"
	.string "“{STR_VAR_1}”\l"
	.string "are in, too.$"

