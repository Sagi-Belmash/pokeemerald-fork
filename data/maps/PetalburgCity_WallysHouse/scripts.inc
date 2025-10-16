PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "את{EMIT_HEY}…\n"
	.string "אה, את{EMIT_HEY} בטח {PLAYER}{KUN}, נכון?\p"
	.string "תודה ששיחקת עם וולי\n"
	.string "לפני זמן קצר.\p"
	.string "הוא היה שברירי וחולה מאז\n"
	.string "שהיה תינוק.\p"
	.string "שלחנו אותו להתארח אצל קרובי המשפחה\n"
	.string "שלי בעיירת ורנדטרף לזמן מה.\p"
	.string "האוויר שם הרבה יותר נקי\n"
	.string "מאשר כאן.\p"
	.string "מה זה? איפה וולי?\n"
	.string "הוא כבר עזב, וולי שלנו.\p"
	.string "אני תוהה לאן הוא כבר יכל\n"
	.string "להגיע בינתיים?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "אני תוהה מה שלום וולי שלנו?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! אנא סלח{ADD_YUD} לנו\n"
	.string "שגררנו אותך לכאן.\p"
	.string "אבל הוולי שלנו נהיה בריא מאוד\n"
	.string "מאז שהלך לעיירת ורדנטרף.\p"
	.string "אנחנו חייבים הכל לך!\p"
	.string "כשוולי עזב את העיר, את{EMIT_HEY} עזרת\n"
	.string "לו לתפוס פוקימון, נכון?\p"
	.string "אני חושב שזה גרם לוולי להיות\n"
	.string "שמח מאוד.\p"
	.string "למעשה, לא רק את וולי.\n"
	.string "זה גרם לי, אבא שלו, גם לשמוח.\p"
	.string "שמח שזכה בחבר{ADD_HEY} כל כך טוב{ADD_HEY}\n"
	.string "כמוך.\p"
	.string "זה לא שוחד או משהו, אבל\n"
	.string "אשמח שיהיה לך את זה.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "אם הפוקימון שלך יכול לגלוש, את{EMIT_HEY}\n"
	.string "תוכל{ADD_HEY} להגיע לכל מיני מקומות.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "וולי חוזר הביתה בקרוב.\n"
	.string "אני מצפה לזה בקוצר רוח.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "או? פגשת את וולי\n"
	.string "בעיר אבר גרנדה?\p"
	.string "או, {PLAYER}{KUN}, אל תהי{EMIT_HEY}{ADD_YUD} מגוח{SWAP_CHAF}{ADD_TAF}.\p"
	.string "הוא אולי הבריא, אבל הוא\n"
	.string "לא יכול ללכת למקום רחוק כזה\l"
	.string "לגמרי לבדו.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "וולי ממש שמח כשסיפר לנו\n"
	.string "שעזרת לו לתפוס פוקימון.\p"
	.string "עבר המון זמן מאז שראיתי אותו\n"
	.string "מחייך ככה.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "אני רוצה שתשמ{EMIT_VAV}ר{ADD_YUD} את זה בסוד\n"
	.string "מבעלי…\p"
	.string "אבל וולי שלנו עזב את עיירת ורדנטרף\n"
	.string "מבלי לספר לאף אחד.\p"
	.string "את{EMIT_HEY} יודע{ADD_TAF}, וולי שברירי, אבל\n"
	.string "יש לו רצון חזק באופן מפתיע.\p"
	.string "אני בטוחה שהוא יחזור בשלום\n"
	.string "יום אחד!$"

