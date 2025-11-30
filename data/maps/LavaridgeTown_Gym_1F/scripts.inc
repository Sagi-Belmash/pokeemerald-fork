LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "היי, מה שלומך, {PLAYER}\n"
	.string "בדרך להיות אלוף?\p"
	.string "מנהיגת מכון לווארידג', פלאנרי,\n"
	.string "משתמשת בפוקימונים מטיפוס אש.\p"
	.string "התשוקה שלה לפוקימונים בוערת חזק\n"
	.string "וחם יותר מהר געש.\p"
	.string "אל תתקרב אליה יותר מדי—אתה תישרף!\n"
	.string "השקע אותה במים ואז\l"
	.string "לך על זה!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "וואו! זה היה קרב לוהט ושורף!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "אווואוואוואו!\n"
	.string "יואו, כמה חם!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "אני מסונוור מזיעה בעיניים…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "להיקבר בחול חם משפר\n"
	.string "את זרימת הדם.\p"
	.string "זה יעיל לריפוי כאבים\n"
	.string "במפרקים שלך.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "אני מנסה להקל על הלחץ שלי.\n"
	.string "אל תבוא ותלחיץ אותי!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "אני מקווה שפלאנרי תשרוף אותך טוב!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "אההה… פיו…\p"
	.string "אם אתה מבלה יותר מדי זמן קבור\n"
	.string "בחול חם, זה מתיש אותך…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "אתה בטח מתעייף כבר.\n"
	.string "היית רוצה לנוח בחול החם,\l"
	.string "נכון?\p"
	.string "אבל אתה צריך לדעת ששמירה על\n"
	.string "כוח הרצון שלך היא יכולת חשובה\l"
	.string "לכל המאמנים.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "משחק באש, ונשרף…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "הכישרון שלך אמיתי…\n"
	.string "אבל המנהיגה שלנו פלאנרי חזקה.\p"
	.string "אם לא תיזהר, אתה תישרף\n"
	.string "ברצינות.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "האם הפוקימונים שלך יכולים לעמוד\n"
	.string "בחום של 392 מעלות?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "זה לא בער מספיק חזק…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "הטמפרטורה של מאגמה היא\n"
	.string "392 מעלות.\p"
	.string "הפוקימונים שלך ניצחו אותי, אז הם אמורים\n"
	.string "לשרוד בקלות במאגמה.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "הממ…\n"
	.string "בסדר, אני אלחם איתך.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "הו, אבל אתה חזק מדי.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "אני הולכת להיות מאמנת יפה וחזקה\n"
	.string "בדיוק כמו פלאנרי.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "קדימה, תתחיל!\n"
	.string "בוא נלך לפני שהרגשות שלי מתקררים!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "כל כך חם, ובכל זאת הלב שלי נתפס\n"
	.string "על ידי קרח…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "הדרך שבה רוח הקרב בוערת\n"
	.string "בתוכך, אולי יש לך סיכוי\l"
	.string "מול המנהיגה שלנו.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "ראה איך הלהבות משתוללות בחוזקה?\n"
	.string "הן בוערות בציפייה לניצחון שלי!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "משהו לא הלך כשורה.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "טוב, אז מה? אני אומר אז מה?\n"
	.string "אני יכול ללכת יחף על גחלים לוהטות!\p"
	.string "…אל תחשוב אפילו לנסות את זה!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "ככל שאני אוהב הרים,\n"
	.string "אני אוהב במיוחד הרי געש.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "טוב, נראה לי שהפסדתי בלי\n"
	.string "ששלטתי במצב בכלל.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "אני נשאר כאן כי הפכתי למעריץ\n"
	.string "של הכוח של פלאנרי.\p"
	.string "הההההה.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "ברוך הבא… לא, חכה.\p"
	.string "מאמן עלוב, כמה טוב לראות\n"
	.string "שהגעת לכאן!\p"
	.string "הופקדתי על…\n"
	.string "לא, חכה.\p"
	.string "אני פלאנרי, ואני מנהיגת המכון\n"
	.string "כאן!\p"
	.string "אה…\n"
	.string "אל תעז לזלזל בי, למרות\l"
	.string "שאני מנהיגה רק זמן קצר!\p"
	.string "עם כישורים שירשתי מסבי\n"
	.string "רבא, אני א… אני אדגים את\l"
	.string "המהלכים הלוהטים שחישלנו על האדמה הזו!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "הו…\n"
	.string "אני מניחה שניסיתי יותר מדי…\p"
	.string "אני… אני הפכתי למנהיגת מכון\n"
	.string "רק לאחרונה.\p"
	.string "ניסיתי יותר מדי להיות מישהי\n"
	.string "שאני לא.\p"
	.string "אני צריכה לעשות דברים בדרך הטבעית שלי. אם\n"
	.string "אני לא עושה את זה, הפוקימונים שלי יתבלבלו.\p"
	.string "תודה שלימדת אותי את זה.\n"
	.string "בגלל זה, מגיע לך את זה.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} קיבל את תג החום\n"
	.string "מפלאנרי.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "אם יש לך תג חום, כל הפוקימונים\n"
	.string "עד רמה 50, אפילו אלה שאתה מקבל ב\l"
	.string "החלפות מאנשים אחרים, יצייתו\l"
	.string "לך לחלוטין.\p"
	.string "וזה מאפשר לפוקימונים להשתמש ב_מהלך HM\n"
	.string "כוח (STRENGTH) מחוץ לקרב.\p"
	.string "זוהי אות הערכה ממני.\n"
	.string "אל תתבייש לקחת את זה!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "ה-TM50 הזה מכיל OVERHEAT.\p"
	.string "המהלך הזה מטיל נזק רציני על\n"
	.string "היריב.\p"
	.string "אבל הוא גם מוריד בחדות את התקפ"מ\n"
	.string "של הפוקימון המשתמש בו. זה אולי לא\l"
	.string "מתאים לקרבות ארוכים יותר.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "נרשמה מנהיגת המכון פלאנרי\n"
	.string "בפוקינאב.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "הכוח שלך מזכיר לי מישהו…\p"
	.string "הו! אני יודעת! אתה נלחם כמו נורמן,\n"
	.string "מנהיג מכון פטלבורג.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "מכון הפוקימונים של עיר לווארידג' $"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "מכון הפוקימונים של עיר לווארידג'\p"
	.string "המאמנים המאושרים של פלאנרי:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "פלאנרי: להפסיד בקרב לא יגרום\n"
	.string "לי להתייאש.\p"
	.string "אני אוהבת פוקימונים.\n"
	.string "אני אוהבת להילחם.\l"
	.string "ו… אני אוהבת את המכון הזה!\p"
	.string "בוא נחליף מהלכים לוהטים במיוחד\n"
	.string "בקרב נוסף!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "פיו!\n"
	.string "על סף התפרצות!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "פלאנרי: הפסדתי בקרב,\n"
	.string "אבל אני מרוצה לחלוטין.\p"
	.string "לא לעתים קרובות אני זוכה ליהנות מקרב\n"
	.string "כל כך לוהט.\p"
	.string "בוא נערוך קרב נוסף כזה\n"
	.string "מתישהו!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "פלאנרי: להפסיד בקרב לא יגרום\n"
	.string "לי להתייאש.\p"
	.string "אני אוהבת פוקימונים.\n"
	.string "אני אוהבת להילחם.\l"
	.string "ו… אני אוהבת את המכון הזה!\p"
	.string "בוא נחליף מהלכים לוהטים במיוחד\n"
	.string "בקרב נוסף!\p"
	.string "הו, חכה. האם יש לך רק פוקימון אחד\n"
	.string "שיכול להילחם?\p"
	.string "אני שונאת לומר את זה, אבל כשאתה בא\n"
	.string "לראות אותי, תביא לפחות שני פוקימונים.$"
