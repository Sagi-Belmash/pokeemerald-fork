Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "הבוס התעניין במחקר\n"
	.string "שמתקיים כאן, לכן הוא שלח אותנו.\p"
	.string "תפסיק{ADD_YUD} להתערב!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "זה ארור…\n"
	.string "ארור על ידי ילד{ADD_HEY}…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "הבוס שלנו יודע הכל.\p"
	.string "אבל אני רק עובד פשוט. מה אני אדע\n"
	.string "על מה שהוא חושב?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "האא?\n"
	.string "מה ילד{ADD_HEY} עושה כאן?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "האא?\n"
	.string "הפסדתי?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "או, לא…\n"
	.string "אקבל על הראש על שהפסדתי לילד{ADD_HEY}…\p"
	.string "אולי עדיף שאלך לנמנם במיטה…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "בזמן שישנתי, כולם עלו\n"
	.string "למעלה!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "וואו, את{EMIT_HEY} ממש חזק{ADD_HEY}!\p"
	.string "הלוואי שיכולתי להיות מאמן פוקימונים\n"
	.string "כמוך!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "הפרופסור אוהב גשם.\n"
	.string "זו עובדה.\p"
	.string "אבל אם ימשיך לרדת גשם, אנשים יהיו\n"
	.string "בצרה. זו עובדה נוספת.\p"
	.string "ולכן, הפרופסור חוקר\n"
	.string "אם אפשר להשתמש בגשם לטובה.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "בקומה 2 של המכון,\n"
	.string "אנחנו חוקרים את דפוסי מזג האוויר על\l"
	.string "פני מחוז הואן.\p"
	.string "שמנו לב לאחרונה למקרים זמניים\n"
	.string "מבודדים של בצורות\l"
	.string "וגשם כבד…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "שלום!\n"
	.string "ניצלנו בזכות מעשיך!\p"
	.string "מה שאני לא מבין זה מה לעזאזל\n"
	.string "צוות אקווה תכננו.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "יש כאן מיטה…\n"
	.string "בוא{ADD_YUD} נקח מנוחה.$"

