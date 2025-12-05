MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "היי, איך הולך, {PLAYER}\n"
	.string "אלו{SWAP_PEY}{ADD_HEY} שבדרך?\p"
	.string "ווטסון, מנהיג מכון מוויל,\n"
	.string "משתמש בפוקימונים מסוג חשמל.\p"
	.string "אם תאתגר אותו עם פוקימונים\n"
	.string "מסוג מים, הוא יחשמל אותם! בזזזט!\p"
	.string "והוא התקין דלתות בשליטת מתג\n"
	.string "בכל המכון שלו! יוצא דופן!\p"
	.string "היי, ל{SWAP_CHAF}{ADD_YUD} על זה!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "וואה, את{EMIT_HEY} מחשמל{ADD_TAF}!\n"
	.string "הפעלת את הדלת!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "הנשמה החשמלית שלי, היא תנפץ את\n"
	.string "החלומות שלך כליל, וואה-יאהאה!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "זה היה מחשמל, מתוגבר,\n"
	.string "קצר סוגר מעלים, בנאדם!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "פוקימון ורוק, הכל עניין של לב,\n"
	.string "וואה-יאה!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "התאמנתי אצל ווטסון!\n"
	.string "אין סיכוי שאפסיד בקלות!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "מנותק וכבוי…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "ווטסון, מנהיג המכון שלנו, נמצא\n"
	.string "בסביבה כבר הרבה, הרבה זמן.\p"
	.string "הוא נלחם אפילו לפני שאבא שלך\n"
	.string "נולד, הזקן הקשוח הזה.$"

MauvilleCity_Gym_Text_BenIntro:
	.string "במכון הזה יש פאזלים!\n"
	.string "זה לא כיף?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "זה לא כיף להפסיד…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "ווטסון אומר שהוא אוהב להציב\n"
	.string "מלכודות קטנות עם מתגים.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "עם הקסם שלי ומהלכי הפוקימון שלי,\n"
	.string "את{EMIT_HEY} תהי{EMIT_HEY}{ADD_YUD} בהלם!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "אני בהלם מהכוח שלך!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "שמעתי שמוויל נוסדה\n"
	.string "על ידי ווטסון.\p"
	.string "הוא היה מאמן הרבה לפני שאנחנו\n"
	.string "הפכנו למאמנים.\l"
	.string "הוא בטח יודע כל מיני דברים!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "אני אוהב דברים מבריקים!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "או…\n"
	.string "העיניים שלי חרוכות…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "לווטסון ממכון מוויל יש מצח\n"
	.string "מבריק. זה משמח אותי!$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "אני ויתרתי על תוכניותיי להמיר\n"
	.string "את העיר, אני.\p"
	.string "ולכן, אני משקיע את זמני בבניית\n"
	.string "דלתות ממולכדות במכון שלי.\p"
	.string "או? מה את{EMIT_HEY} עושה כאן?\p"
	.string "מה זה? את{EMIT_HEY} אומר{ADD_TAF} שעברת\n"
	.string "את כל הדלתות הממולכדות שלי?\p"
	.string "וואהאהאהאהא!\n"
	.string "עכשיו, זה משעשע!\p"
	.string "אם כן, אני, ווטסון, מנהיג מכון\n"
	.string "מוויל, אחשמל אותך!$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "וואהאהאהאהא!\n"
	.string "בסדר, הפסדתי!\p"
	.string "בסוף את{EMIT_HEY} גרמת לי להתרגשות!\n"
	.string "קח{ADD_YUD} את התג הזה!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} קיבל{ADD_HEY} את תג הדיינמו\n"
	.string "מווטסון.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "עם תג הדיינמו, פוקימונים יכולים\n"
	.string "להשתמש בריסוק סלע מחוץ לקרב.\p"
	.string "וזה גם יהפוך את הפוקימון שלך לקצת\n"
	.string "יותר מהיר.\p"
	.string "הממ…\n"
	.string "את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} לקחת גם את זה!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "מ”מ43 הזה מכיל גל הלם.\p"
	.string "זה מהלך אמין שלעולם לא\n"
	.string "מחטיא! את{EMIT_HEY} יכול{ADD_HEY} לסמוך עליו!\p"
	.string "… … … … … …$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "מנהיג המכון ווטסון נרשם\n"
	.string "בפוקינווט.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "אני מתמלא באופטימיות, כשאני רואה\n"
	.string "מאמ{SWAP_NUN}{ADD_TAF} צעיר{ADD_HEY} ומבטיח{ADD_HEY} כמוך!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "וואהאהאהא!\n"
	.string "צא{ADD_YUD} והצל{ADD_YUD}ח{ADD_YUD}, צעיר{ADD_HEY}!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "מכון הפוקימונים של עיר מוויל$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "מכון הפוקימונים של העיר מוויל\p"
	.string "המאמנים המוסמכים בידי ווטסון:\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "ווטסון: אה-הא! הנה את{EMIT_HEY} סוף סוף!\n"
	.string "אני יודע מה את{EMIT_HEY} רוצה.\l"
	.string "את{EMIT_HEY} רוצה להילחם בפוקימונים שלי!\p"
	.string "וואהאהאהא!\p"
	.string "אני אגרום לניצוצות לעוף ממך!\n"
	.string "אל תגיד{ADD_YUD} שלא הזהרתי אותך!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "אוף…\n"
	.string "הסוללות שלנו נגמרו…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "ווטסון: אנחנו נצטרך לטעון את\n"
	.string "הסוללות שלנו שוב.\p"
	.string "כאשר נהיה טעונים במלואנו, אנחנו\n"
	.string "נשמח לקבל את האתגר שלך.\p"
	.string "אז, תחז{EMIT_VAV}ר{ADD_YUD} לבקר שוב מתישהו,\n"
	.string "בסדר?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "ווטסון: אה-הא! הנה את{EMIT_HEY} סוף סוף!\n"
	.string "אני יודע מה את{EMIT_HEY} רוצה.\l"
	.string "את{EMIT_HEY} רוצה להילחם בפוקימונים שלי!\p"
	.string "וואהאהאהא!\p"
	.string "אופס! חכ{EMIT_HEY}{ADD_YUD}!\n"
	.string "יש לך רק פוקימון אחד איתך!\p"
	.string "בוא{ADD_YUD} לבקר אותי עם שניים או יותר\n"
	.string "פוקימונים, בסדר?$"

