BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

הנה התרגום לעברית של הדיאלוגים מהצד המערבי החיצוני של גבול הקרב (Battle Frontier), ללא ניקוד, וללא מילים בנות תו אחד בסוף שורה:

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "זוהי כיפת הקרב!\n"
	.string "הדרך שלך לכוכב העל הבלתי מנוצח!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "זהו בית החרושת לקרב!\n"
	.string "חפש את הפוקימונים הקשוחים ביותר!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "זהו כידון הקרב!\n"
	.string "בחר אחד משלושה נתיבים!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "זהו מגדל הקרב.\p"
	.string "מאמנים מביאים את הפוקימונים\n"
	.string "המגודלים הטובים ביותר שלהם לקרבות\l"
	.string "בסגנון הדחה.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "שלום, אתה כאן בשביל המעבורת?\n"
	.string "אפשר לראות את כרטיסך?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "ל-{PLAYER} אין כרטיס…\p"
	.string "אני מצטער מאוד.\p"
	.string "אתה חייב שיהיה לך כרטיס כדי לעלות\n"
	.string "למעבורת.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} הציג את הכרטיס.\p"
	.string "מושלם! זה כל מה שאתה צריך!\p"
	.string "ולאן תרצה לנסוע?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "עיר סלייטפורט, אם כן!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "עיר ליליקוב, אם כן!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "אנא הפלג איתנו בפעם אחרת!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "אנא עלה למעבורת והמתן ל\n"
	.string "יציאה.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "אם כן, לאן תרצה לנסוע?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "אני הטוב מכל החברים שלי.\n"
	.string "אבל כאן…\l"
	.string "הייתי חסר תועלת!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "אני רוצה ללכת למגדל הקרב,\n"
	.string "אבל אני לא מוצא אותו למרות שיש לי\l"
	.string "מפה של גבול הקרב.\p"
	.string "המקום הזה פשוט גדול מדי!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "רציתי לקחת אתגר ברגע\n"
	.string "שהגעתי לכאן.\p"
	.string "אבל בדרך, קיבלתי מחלת ים…\n"
	.string "אוררררפ…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "זה לא שכל אחד יכול לבוא\n"
	.string "לכאן, אתה יודע?\p"
	.string "רק אותם מאמנים ש_הוכרו\n"
	.string "כקשוחים מובאים לכאן.\p"
	.string "זו הסיבה שמאמנים רבים אפילו לא\n"
	.string "יודעים על גבול הקרב.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "היי, אח…\p"
	.string "אתה בטוח שאנחנו יכולים לקחת אתגרים\n"
	.string "גם אם אין לנו פוקימונים?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "אה…\n"
	.string "אני בטוח שזה יהיה בסדר.\p"
	.string "אני חושב…\p"
	.string "אבל אתה זוכר את הבחור המפחיד הגדול ההוא?\n"
	.string "הוא אמר, “אני אשאיל לכם פוקימונים!”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "זה בית החרושת לקרב.\n"
	.string "אתה יכול לשכור שם פוקימונים חזקים.\p"
	.string "אבל זה גורם לי לתהות.\n"
	.string "מי מגדל את הפוקימונים השכורים האלה?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "אני מפחד להיכנס לכידון הקרב\n"
	.string "בגלל סבייפר…\p"
	.string "א-אבל הגעתי עד לכאן, אז אני\n"
	.string "אנסה לכבוש הכל!\l"
	.string "…רעד…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "בוא נשחק אבן, נייר, ומספריים!\n"
	.string "אחת, שתיים, שלוש!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "יש! ניצחתי!\n"
	.string "אני אקבל את אתגר כידון הקרב!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "הו, לא…\n"
	.string "הפסדתי.\p"
	.string "אני מניח שאני לא בר מזל היום.\n"
	.string "אני אדחה את אתגר כידון הקרב שלי\l"
	.string "למחר.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "אני מאמין שאני האדם היחיד כאן ש,\n"
	.string "מסיבה לא ידועה כלשהי, היה בוחר\l"
	.string "בדיג על פני קרב.\p"
	.string "הא? אתה לא יכול לתפוס שום דבר כאן?\n"
	.string "זה מאכזב…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "היום, אני הולך להמשיך להילחם,\n"
	.string "לא משנה מה, עד שאשיג סמל.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "הו? אתה בדרך לאתגר\n"
	.string "את כיפת הקרב?\p"
	.string "אני מאחל לך את כל_המזל שבעולם.\n"
	.string "ששנינו ננצח בדרכינו וניפגש\l"
	.string "באתגרים.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "סבא, הנה!\n"
	.string "כיפת הקרב כאן!\l"
	.string "לך תביא להם, סבא!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "אה, אז זוהי זירת הקרב?\n"
	.string "אני לא אתן לג'נטלמנים לנצח אותי!\p"
	.string "אבל איפה הכניסה?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "לא היה כאן כלום לפני זמן\n"
	.string "לא רב כל כך.\p"
	.string "אבל, עכשיו תראה את המקום הזה! מדהים!\n"
	.string "אני אביא את אמא שלי לראות את זה.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "סוף סוף הגעתי לגבול הקרב!\n"
	.string "הקרב!\p"
	.string "אני בטוח שאמשוך תשומת לב עם\n"
	.string "המראה והיכולת שלי!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "לעיסה, לעיסה…\p"
	.string "נראה שהכיכר הזו מלאה באנשים\n"
	.string "קשוחים.\p"
	.string "לעיסה, לעיסה…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "קראנץ', לעיסה…\p"
	.string "לפני זמן מה, פגשתי בחורה מבוגרת\n"
	.string "בכידון הקרב.\p"
	.string "היו לה עיניים מפחידות\n"
	.string "בצורה עוינת ממש.\p"
	.string "קראנץ', לעיסה…\p"
	.string "היא התמלאה זעם: “תפסיק כבר\n"
	.string "לאכול!” ואז היא הרביצה לי.\p"
	.string "זו הייתה חוויה מפחידה\n"
	.string "ומחרידה, בוודאות.\p"
	.string "קראנץ', לעיסה…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "הא? תקשיב לעצמך!\n"
	.string "זה שטויות!\p"
	.string "וואו, בפעם האחרונה שעודדתי אותו,\n"
	.string "העיניים שלנו נפגשו ועפו ניצוצות!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "מממממההההה?!\n"
	.string "פחחח!\p"
	.string "זה קרה רק בגלל\n"
	.string "שבמקרה ישבתי לידך!\p"
	.string "אלוף הכיפה רק הסתכל לכיוון שלנו\n"
	.string "כי העידוד שלי היה כל כך חזק!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "הו, תשתקי!\n"
	.string "תנמיכי את הרעש הזה!\p"
	.string "מעריצות מזדמנות צריכות להישאר\n"
	.string "לעודד איזה מנהיג מכון!\p"
	.string "אלוף הכיפה הוא שלי!\n"
	.string "האליל היחיד בשבילי!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "האנשים האלה שמתווכחים שם…\p"
	.string "קשה להאמין, אבל הם היו פעם\n"
	.string "מאמנים, וטובים.\p"
	.string "הם היו קשוחים בצורה בלתי רגילה,\n"
	.string "והם היו מפורסמים, גם כן.\p"
	.string "אבל הם הובסו לחלוטין על ידי\n"
	.string "מאמן מסוים בטורניר.\p"
	.string "הם הובסו כל כך ביסודיות,\n"
	.string "שהם התאהבו במאמן.\p"
	.string "עכשיו הם רק מעריצים של המאמן.\n"
	.string "הם הולכים לעודד את האליל שלהם ב\l"
	.string "כיפת הקרב כל יום עכשיו.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "שמעתי שמועה שמישהו ראה\n"
	.string "פוקימון עם זנב ארוך במיוחד\l"
	.string "איפשהו בגבול הקרב.\p"
	.string "הוא בטח מקסים. אני בטוח ב_זה…\p"
	.string "הו, אתגרים יכולים לחכות. אני מרגיש מונע\n"
	.string "למצוא את היצור המקסים!$"

