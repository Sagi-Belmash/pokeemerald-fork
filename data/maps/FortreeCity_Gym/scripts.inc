FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "יו, מה שלומך, {PLAYER}\n"
	.string "אלו{SWAP_PEY}{ADD_HEY} שבדרך?\p"
	.string "מנהיגת מכון פורטרי, ווינונה, היא\n"
	.string "אמנית בפוקימונים מסוג מעופף.\p"
	.string "היא מחכה בחלק האחורי של המכון,\n"
	.string "מאחורי הדלתות המסתובבות.\p"
	.string "היא מחכה לאתגרים חדשים\n"
	.string "שמנסים לפרוש כנפיים!\p"
	.string "אוקיי, ל{SWAP_CHAF}{ADD_YUD} על זה!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "עשית את זה!\n"
	.string "השגת המראה!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "תחז{EMIT_HEY}{ADD_YUD} בסגנון הקרב האלגנטי של\n"
	.string "פוקימוני ציפור!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "את{EMIT_HEY}…\n"
	.string "את{EMIT_HEY} חזק{ADD_HEY}…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "מאמן צריך להיות חכם כדי להתמודד\n"
	.string "עם תפניות בלתי צפויות.\p"
	.string "האם יש לך את החוכמה להגיע אל\n"
	.string "המנהיגה שלנו?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "אוהבי פוקימוני ציפור שואפים\n"
	.string "להצטרף למכון הזה.\p"
	.string "כחבר במכון פורטרי,\n"
	.string "אסור לי להפסיד!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "זה היה עומס גדול מדי בשבילי\n"
	.string "לשאת…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "העולם ענק, ויש אינספור\n"
	.string "מאמנים קשוחים.\p"
	.string "אני הולך להמשיך להתאמן להפוך\n"
	.string "את עצמי לחזק יותר.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "אין צורך שווינונה, מנהיגת המכון\n"
	.string "שלנו, תתמודד מולך!\p"
	.string "אני מספיק טוב בשבילך!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "ווינונה, אני…\n"
	.string "הפסדתי!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "ווינונה חמודה והיא חזקה.\n"
	.string "היא המנהיגה האולטימטיבית!\p"
	.string "הסמקה…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "ווינונה לימדה אותי באופן אישי!\n"
	.string "את{EMIT_HEY} לא יכול{ADD_HEY} לנצח אותי בקלות!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "הובסתי…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "בזכות ווינונה, תושבי\n"
	.string "פורטרי יכולים לחיות ללא פחד.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "כאשר ווינונה נכנסת לקרב, פניה\n"
	.string "זורחות בהחלטיות יפה…\p"
	.string "אני לא נותן לך לחזות במראה\n"
	.string "היפה הזה!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "אוחח!\n"
	.string "לא יכולתי לעצור אותך.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "מוטב שתשי{SWAP_MEM}{ADD_YUD} לב!\n"
	.string "אל תוסח{ADD_YUD} דעת מלבהות בווינונה\l"
	.string "או שתיפול ארצה בערמה!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "מוטב שתדע{ADD_YUD} שיש כל מיני\n"
	.string "סוגים של פוקימונים מעופפים.\p"
	.string "את{EMIT_HEY} יודע{ADD_TAF} את זה, נכון?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "נראה שאת{EMIT_HEY} מבי{SWAP_NUN}{ADD_HEY} עניין!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "בטח, ניצחת אותי, זה בסדר.\n"
	.string "אבל מוטב שתשי{SWAP_MEM}{ADD_YUD} לב! הפוקימונים של המנהיגה\l"
	.string "שלנו ווינונה מאוד רציניים.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "אני ווינונה. אני המנהיגה של\n"
	.string "מכון הפוקימונים של פורטרי.\p"
	.string "הפכתי לאחת עם פוקימוני ציפור\n"
	.string "וריחפתי בשחקים…\p"
	.string "לא משנה כמה הקרב קשה, ניצחנו\n"
	.string "באלגנטיות…\p"
	.string "תחז{EMIT_HEY}{ADD_YUD} בכוריאוגרפיה האלגנטית\n"
	.string "של פוקימוני ציפור ואני!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "מעולם לא ראיתי מאמ{SWAP_NUN}{ADD_TAF}\n"
	.string "שמפקד{ADD_TAF} על פוקימונים בחן רב\l"
	.string "יותר ממני…\p"
	.string "כהכרה לגבורתך,\n"
	.string "אני מעניקה לך את תג המכון הזה.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} קיבל{ADD_HEY} את תג הנוצה\n"
	.string "מווינונה.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "עם תג הנוצה, כל הפוקימונים עד\n"
	.string "רמה 07, אפילו אלה שהתקבלו דרך\l"
	.string "החלפות, יצייתו לכל פקודה שלך.\p"
	.string "את{EMIT_HEY} תוכל{ADD_YUD} גם להשתמש במהלך המ”נ\n"
	.string "תעופה מחוץ לקרב.\p"
	.string "וזה…\n"
	.string "זו מתנה ממני.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "מ”מ04 מכיל אס אווירי.\p"
	.string "המהירות שלו…\n"
	.string "אף פוקימון לא אמור להיות מסוגל להימנע ממנו.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "מנהיגת המכון ווינונה נרשמה\n"
	.string "בפוקינווט.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "למרות שנפלתי ממך, אני אשאר\n"
	.string "מסורה לפוקימוני ציפור.$"

FortreeCity_Gym_Text_GymStatue:
	.string "מכון הפוקימונים של עיר פורטרי$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "מכון הפוקימונים של עיר פורטרי\p"
	.string "המאמנים המוסמכים בידי ווינונה:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "ווינונה: אנחנו בני האדם לעולם לא נוכל לברוח\n"
	.string "מהמשיכה של כוח הכבידה על הקרקע.\p"
	.string "אבל על ידי חתירה למצוינות,\n"
	.string "יש לנו את הכוח להמריא!\p"
	.string "את{EMIT_HEY} טיפסת לפסגה בתור האלו{SWAP_PEY}{ADD_HEY}\n"
	.string "המכה{SWAP_NUN}{ADD_TAF}.\p"
	.string "בבקשה, הרש{EMIT_HEY}{ADD_YUD} לי לראות את כוחך\n"
	.string "בשיא המעוף!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "נכשלתי להגיע לגובה שלך שוב…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "ווינונה: למרות שהפסדתי,\n"
	.string "כנפי ליבי נשארות שלמות.\p"
	.string "אני יכולה לקום ולהמריא שוב\n"
	.string "ושוב.\p"
	.string "אני משוכנעת בזה!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "ווינונה: אנחנו בני האדם לעולם לא נוכל לברוח\n"
	.string "מהמשיכה של כוח הכבידה על הקרקע.\p"
	.string "אבל על ידי חתירה למצוינות,\n"
	.string "יש לנו את הכוח להמריא!\p"
	.string "את{EMIT_HEY} טיפסת לפסגה בתור האלו{SWAP_PEY}{ADD_HEY}\n"
	.string "המכה{SWAP_NUN}{ADD_TAF}.\p"
	.string "בבקשה, הרש{EMIT_HEY}{ADD_YUD} לי לראות את כוחך\n"
	.string "בשיא המעוף!\p"
	.string "או, לא… האם יש לך רק פוקימון\n"
	.string "אחד איתך?\p"
	.string "בבקשה חז{EMIT_VAV}ר{ADD_YUD} עם שני פוקימונים\n"
	.string "לכל הפחות.$"
