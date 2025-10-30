DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "היי, איך הולך אלו{SWAP_PEY}{ADD_HEY}\n"
	.string "לעתיד {PLAYER}?\p"
	.string "מנהיג המכון בדופורוד, בראולי, פוקד\n"
	.string "על פוקימונים מסוג לחימה.\p"
	.string "ללכת נגדו עם פוקימונים מסוג רגיל\n"
	.string "זה לבקש צרות.\p"
	.string "פוקימוני לחימה יתנו מכה רצינית\n"
	.string "לפוקימון מסוג רגיל,\l"
	.string "אז תיזהר{ADD_YUD}!\p"
	.string "גרוע מכך, המכון חשוך כמו\n"
	.string "קרקעית האוקיינוס.\p"
	.string "אבל הוא יתבהר לאחר שתביס{ADD_YUD}\n"
	.string "מאמנים שעומדים בדרכך.\p"
	.string "היי, אוקיי, ל{SWAP_CHAF}{ADD_YUD} על זה!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "וואה! נהיה פה בהיר מדי!\p"
	.string "העתיד שלך מזהיר, גם כן!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "הכוח הוא הצדק!\n"
	.string "בוא{ADD_YUD}!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "אין מספיק כוח…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "הכישרון שלך התגבר על העוצמה שלי!\n"
	.string "הטכניקה שלך ראויה לשבח!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "אין צורך לבראולי להיות מעורב!\p"
	.string "אני אמחוץ אותך!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "אבל… איך?\n"
	.string "איך יכולתי להפסיד בכזאת קלות?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "אני לא הולכת לבזבז את ההפסד הזה.\n"
	.string "אני אשתמש בו כדי להניע אותי להתאמן!\p"
	.string "יום אחד אהפוך למנהיגת מכון…\p"
	.string "לא, אני אהפוך לאלופת ליגת הפוקימון!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "אל תעז{ADD_YUD} להתעלם ממני!\n"
	.string "זאת לא אשמתי אם תבכ{EMIT_HEY}{ADD_YUD}!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "ואאאאאאאה!\n"
	.string "הפסדתי!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "אני נלחמת בחושך כדי לחזק את הלב שלי.\p"
	.string "אבל בגלל שכל כך חשוך, אני אף פעם לא\n"
	.string "רואה את הפנים של בראולי…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "אופופו…\n"
	.string "האם את{EMIT_HEY} מגשש{ADD_TAF} באפלה?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "או, את{EMIT_HEY}…\n"
	.string "אני לא רוצה להכיר אותך!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "מגיע לך להישאר אבוד{ADD_HEY} ובסוף\n"
	.string "לחזור שוב לכניסה!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "אני אראה לך את האומץ לב של\n"
	.string "ימאי!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "איך זה קרה?\n"
	.string "זה לא מתאים לי להפסיד ככה!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "או, איי! את{EMIT_HEY} ראוי{ADD_HEY} לראות\n"
	.string "את מנהיג המכון שלנו.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "את את{EMIT_HEY} מתכוו{SWAP_NUN}{ADD_TAF} לעבור, זה חייב להיות\n"
	.string "דרכי!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "גררררר!\n"
	.string "הובסתי לחלוטין!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "ניצחת!\n"
	.string "ל{SWAP_CHAF}{ADD_YUD} אחרי התג הזה!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "אני בראולי!\n"
	.string "מנהיג המכון בדופורד!\p"
	.string "נסחפתי בגלים הסוערים באזורים האלה,\n"
	.string "והתחשלתי במערה החשוכה!\p"
	.string "אז רצית לאתגר אותי?\n"
	.string "ת{SWAP_NUN}{ADD_YUD} לי לראות ממה שאת{EMIT_HEY} עשוי{ADD_HEY}!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "וואה, וואו! עשית גל יותר\n"
	.string "גדול ממה שציפיתי!\p"
	.string "הצפת אותי!\p"
	.string "אוקיי, הבסת אותי.\n"
	.string "קח{ADD_YUD} את התג מכון הזה !$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} קיבל{ADD_HEY} את תג הפרק מבראולי.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "תג הפרק גורם לכל פוקימון\n"
	.string "עד לרמה 30, גם כאלה שקיבלת\l"
	.string "בהחלפה, לציית ללא עוררין.\p"
	.string "ותוכל{ADD_YUD} גם להשתמש במהלך מ”נ הבזק\n"
	.string "מחוץ לקרב.\p"
	.string "אם תרצ{EMIT_HEY}{ADD_YUD}, תשתמש גם במהלך\n"
	.string "מכשיר הזה.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "המ”מ80 הזה מכיל ניפוח.\p"
	.string "זה מהלך שמעלה את נתוני ההתקפה\n"
	.string "וההגנה.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "מנהיג המכון בראולי נרשם\n"
	.string "בפוקינווט.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "אני יכול לראות את הכישרון שלך יום אחד\n"
	.string "הופך לגל ענקי שגורם לסערה של תדהמה\l"
	.string "בקרב מאמנים!$"

DewfordTown_Gym_Text_GymStatue:
	.string "מכון הפוקימון בעיירת דופורד$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "מכון הפוקימון בעיירת דופורד\p"
	.string "מאמנים מוסמכים בידי בראולי:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "בראולי: גל עשוי לשגת, אבל הוא\n"
	.string "תמיד חוזר לחוף.\p"
	.string "גל ענק של כישרון כמוך…\n"
	.string "ידעתי שתחז{EMIT_VAV}ר{ADD_YUD}!\p"
	.string "תרא{EMIT_HEY}{ADD_YUD} לי כמה גבוה הגעת!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "וואו!\n"
	.string "הוצפתי שוב!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "בראולי: קרבות זה דבר עצום ועמוק.\n"
	.string "לא ניתן לראות את התחתית.\l"
	.string "זה בדיוק כמו הים של הואן!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "בראולי: גל עשוי לשגת, אבל הוא\n"
	.string "תמיד חוזר לחוף.\p"
	.string "גל ענק של כישרון כמוך…\n"
	.string "ידעתי שתחז{EMIT_VAV}ר{ADD_YUD}!\p"
	.string "או? יש לך רק פוקימון אחד\n"
	.string "שיכול להילחם.\p"
	.string "אני מצטער, אבל אני אשמח שתחז{EMIT_VAV}ר{ש{ADD_YUD}\n"
	.string "עם לפחות שני פוקימונים.$"
