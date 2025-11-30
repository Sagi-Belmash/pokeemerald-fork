BattleFrontier_ScottsHouse_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier:
	.string "סקוט: ובכן, שלום וברוך הבא!\n"
	.string "הההה… סליחה על המקום הצפוף.\p"
	.string "בכל מקרה, {PLAYER}{KUN}, הרשה לי רשמית\n"
	.string "לברך אותך לגבול הקרב.\p"
	.string "זה החלום שלי שהתגשם.\n"
	.string "לקח לי שנים על גבי שנים, אבל סוף\l"
	.string "סוף נתתי צורה לחלום שלי.$"

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal:
	.string "במחשבה שנייה, זה היה מסע ארוך\n"
	.string "בצורה נוראית…\p"
	.string "עזבתי את הבית לבד במסע למצוא\n"
	.string "מאמנים חזקים.\p"
	.string "אף אחד לא יכול לדמיין כמה מאמץ\n"
	.string "או זמן נדרש כדי להפוך את זה למציאות.$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing:
	.string "אבל כל זה בעבר.\n"
	.string "אין טעם להתעכב על זה!\p"
	.string "כל מה שאני רוצה זה שתיהנה מקרב\n"
	.string "ככל שתרצה כאן.\p"
	.string "{PLAYER}{KUN}, אני רוצה שתקבל את זה\n"
	.string "כמזכרת על כל הזמן שדרכינו\l"
	.string "הצטלבו במסעותינו.$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints:
	.string "{PLAYER} קיבל\n"
	.string "{STR_VAR_1} נקודת/ות קרב.$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints:
	.string "סקוט: אתה יכול לבדוק את נקודות הקרב\n"
	.string "שלך בכרטיס גבול הקרב שלך.\p"
	.string "ככל שתצליח יותר כאן ב\n"
	.string "גבול הקרב, כך תצבור יותר נקודות\l"
	.string "קרב.\p"
	.string "השתמש בנקודות הקרב שלך כפי\n"
	.string "שנראה לך, כמו להחליף אותן בפריטים.$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings:
	.string "אני מצפה ממך לדברים גדולים!$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers:
	.string "סקוט: כל מאמן הוא אינדיבידואל.\n"
	.string "לכולם יש חיים משלהם.\p"
	.string "אבל כשהם בקרב,\n"
	.string "זה לא משנה מי הם.\p"
	.string "כולם זהים!\p"
	.string "אני אוהב את הטוהר של הקרב,\n"
	.string "שבו כולם שווים.\p"
	.string "זו הסיבה שבגללה אני הולך לכל מקום ומחפש\n"
	.string "מאמנים שרציניים לגבי קרבות,\l"
	.string "ומזמין אותם לכאן.$"

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain:
	.string "סקוט: האם פגשת מישהו ממוחות\n"
	.string "הגבול?\p"
	.string "או אפילו טוב יותר, האם השגת מהם\n"
	.string "סמלים כלשהם?\p"
	.string "אני בחרתי את מוחות הגבול\n"
	.string "כמאמנים הקשוחים ביותר שיש.\p"
	.string "אבל אני בטוח ש_כשתראה כמה אתה קשוח\n"
	.string "זה יבהיל אפילו אותם!$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier:
	.string "סקוט: אתה לא רק מתאמן לקרבות,\n"
	.string "נכון?\p"
	.string "נדמה לי שאני זוכר שאתה עובד\n"
	.string "גם על פוקידע.\p"
	.string "טוב, נחש מה?\p"
	.string "אתה עשוי להיתקל בפוקימונים פראיים\n"
	.string "איפשהו בגבול הקרב…\l"
	.string "פופופו!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols:
	.string "סקוט: האם אתה נהנה מ_הדברים\n"
	.string "בגבול הקרב?\p"
	.string "…חכה שנייה…\n"
	.string "הו!\p"
	.string "כרטיס גבול הקרב שלך!\n"
	.string "אספת את הסט המלא\l"
	.string "של סמלי כסף!\p"
	.string "זה יותר ממרשים!\n"
	.string "אתה קשוח, בדיוק כפי שחשדתי!\p"
	.string "בדרך כלל, לא הייתי עושה משהו\n"
	.string "כזה, אבל זה זמן מיוחד!\p"
	.string "אני רוצה שתקבל את זה.\n"
	.string "אני בטוח שאתה יכול להשתמש בזה כראוי.$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols:
	.string "סקוט: אני מקווה שאתה נהנה מ\n"
	.string "כל מה שיש בגבול הקרב.\p"
	.string "…חכה שנייה…\n"
	.string "הו, העיניים הלא מאמינות שלי!\p"
	.string "כרטיס גבול הקרב שלך!\n"
	.string "אספת את הסט המלא\l"
	.string "של סמלי זהב!\p"
	.string "זה יותר ממדהים!\n"
	.string "אתה מדהים, בדיוק כפי שחשדתי!\p"
	.string "… … … … … …\p"
	.string "{PLAYER}, אתה חייב לקבל את זה!\p"
	.string "אני חושב שאתה תדע\n"
	.string "להעריך את שווי המתנה שלי!$"

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere:
	.string "אני חייב לומר שיש לי מתנה לזהות\n"
	.string "מאמן טוב כשאני רואה אותו.\p"
	.string "אני כל כך שמח שהייתה לי התבונה\n"
	.string "להביא אותך לכאן!$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed:
	.string "נראה שכיס פירות יער (BERRY POCKET) שלך\n"
	.string "מלא.$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow:
	.string "סקוט: הו, שמעתי עליך!\n"
	.string "איך שלטת במגדל הקרב!\l"
	.string "ניצחת למעלה מ-50 מאמנים ברצף?\p"
	.string "זה פנטסטי!\n"
	.string "אני רוצה שתקבל את זה!$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow:
	.string "סקוט: הו, אלוהים! שמעתי עליך!\n"
	.string "איך הממת את מגדל הקרב!\l"
	.string "ניצחת למעלה מ-100 מאמנים ברצף?\p"
	.string "זה מרהיב בצורה מגוחכת!\n"
	.string "אתה חייב לקבל את זה!$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings:
	.string "אני אצפה לשמוע דברים גדולים\n"
	.string "אפילו יותר עליך עכשיו!$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater:
	.string "אופס, טוב, אם יש לך יותר מדי\n"
	.string "דברים, תחזור בשביל זה מאוחר יותר.$"

