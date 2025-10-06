LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 8, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 4, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 9, 8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "אמא: רואה, {PLAYER}?\n"
	.string "גם כאן נחמד, לא?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "הפוקימונים של המוביל עושים את כל העבודה\n"
	.string "של המעבר וניקיון אחרי\l"
	.string "זה כזה נוח!\p"
	.string "{PLAYER}, החדר שלך למעלה.\n"
	.string "לך תבדוק אותו, מתוק!\p"
	.string "אבא שלך קנה לך שעון חדש לציון\n"
	.string "המעבר שלנו לפה.\l"
	.string "אל תשכח לכוון אותו!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "אמא: ובכן, {PLAYER}?\p"
	.string "אתה לא סקרן לראות את החדר\n"
	.string "הפרטי שלך?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "אמא: {PLAYER}.\p"
	.string "לך לכוון את השעון בחדר שלך, מתוק.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "אמא: או! {PLAYER}, {PLAYER}!\n"
	.string "מהר! בוא מהר!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "אמא: תראה! זה מכון פטלבורג!\n"
	.string "אולי אבא יופיע!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "אמא: או… זה נגמר.\p"
	.string "אני חושב שאבא הופיע, אבל החמצנו אותו.\n"
	.string "חבל מאוד.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "אה, כן.\n"
	.string "אחד מהחברים של אבא גר בעיירה.\p"
	.string "פרופ. בירץ' הוא שמו.\p"
	.string "הוא גר ממש ליד, אז כדאי לך\n"
	.string "ללכת לשם ולהציג את עצמך.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "אמא: נתראה, מתוק!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "אמא: האם הצגת את עצמך\n"
	.string "לפרופ. בירץ'?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "אמא: מה שלומך, {PLAYER}?\n"
	.string "אתה נראה קצת עייף.\p"
	.string "אני חושבת שאתה צריך לנוח קצת.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "אמא: שמור על עצמך, מתוק!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "אמא: או? האם אבא נתן לך את התג הזה?\p"
	.string "אז הנה משהו מאמא אלך!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "אל תתאמץ יותר מדי, מתוק.\n"
	.string "אתה יכול תמיד לבוא הביתה.\p"
	.string "לך על זה, מתוק!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "אמא: מה זה, מתוק? פויקנווט?\n"
	.string "מישהו מדבון נתן לך אותו?\p"
	.string "ובכן, מתוק, מה דעתך על להוסיף\n"
	.string "את אמא שלך?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "אמא נוספה לפוקינווט.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "פוגיייייה!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "הוגגו, אוגו אוגו…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "מראיין: …אנחנו מביאים לכם את הדיווח \n"
	.string "הזה מול מכון פטלבורג.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "יש סרט בטלוויזיה.\p"
	.string "שני גברים רוקדים על קלידי\n"
	.string "פסנתר.\p"
	.string "מוטב לצאת לדרך!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "זוהי חוברת ההוראות של\n"
	.string "נעלי הריצה.\p"
	.string "“לחץ על כפתור B כדי לרוץ בזמן\n"
	.string "שאתה נועל את נעלי הריצה שלך.\p"
	.string "“שרוך את נעלי הריצה שלך וצעד\n"
	.string "למרחקים!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "אבא: המ?\p"
	.string "היי, זה {PLAYER}!\p"
	.string "עבר זמן מאז שראיתי אותך,\n"
	.string "אבל אתה נראה…חזק יותר, איכשהו.\p"
	.string "זה הרושם שאני מקבל.\n"
	.string "אבל אבא שלך הזקן עדיין לא ויתר!\p"
	.string "אה, כן, יש לי משהו בשבילך.\n"
	.string "זה הגיע אליך ממישהו בשם\l"
	.string "מר. ברייני.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "אבא: המ, כרטיס למעבורת?\p"
	.string "אם אני זוכר, יש נמלי מעבורת\n"
	.string "בסלייטפורט וליליקוב.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "כדאי שאחזור למכון פטלבורג.\p"
	.string "אמא, תודה שאת שומרת על הבית בזמן שאני\n"
	.string "לא כאן.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "אמא: איזה אבא יש לך…\p"
	.string "הוא חוזר הביתה בפעם הראשונה מזה תקופה,\n"
	.string "אבל כל מה שהוא מדבר עליו זה פוקימון.\p"
	.string "הוא צריך לנוח ולהישאר קצת יותר.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "אמא: האם זה מבזק חדשות?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "אנחנו מביאים לכם את מבזק החדשות\n"
	.string "הזה אלכים!\p"
	.string "ברחבי הוון, ישנם דיווחים על\n"
	.string "בזזז… פוקימון צבעוני בתעופה.\p"
	.string "הזהות של הפוקימון עדיין לא ידועה.\p"
	.string "אנחנו עכשיו חוזרים לתוכנית השגרתית\n"
	.string "שלנו.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "אמא: {PLAYER}, האם הבנת את זה?\p"
	.string "מה הצבע שהמגיש אמר שיש לפוקימון הזה?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "אמא: ובכן, האם זה לא משהו!\n"
	.string "יש עדיין פוקימונים לא ידועים.$"
