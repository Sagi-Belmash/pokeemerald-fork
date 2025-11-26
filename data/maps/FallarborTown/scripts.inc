FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	bufferspeciesname STR_VAR_1, SPECIES_AZURILL
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_AZURILL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "משהו קורה,\n"
	.string "ואני לא אוהב את זה!\p"
	.string "ראיתי דמויות מפוקפקות משוטטות\n"
	.string "בתוך ומחוץ לביתו של פרופ. קוזמו…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "האזור הזה ידוע במטאורים\n"
	.string "מאז ימים עברו.\p"
	.string "אומרים שמפלי המטאורים נחצבו\n"
	.string "על ידי נפילת מטאוריט לפני זמן רב.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "רואה! תסתכל{ADD_YUD}!\n"
	.string "זה ה{STR_VAR_1} היקר שלי!\p"
	.string "הוא חלקלק וחלק וגם קטיפתי!$"

FallarborTown_Text_Azurill:
	.string "{STR_VAR_1}: רורירו לו.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "האם כבר אתגרת את פלאנרי,\n"
	.string "מנהיגת המכון של לברידג'?\p"
	.string "הסבא של הילדה היה מפורסם.\n"
	.string "הוא היה אחד מרביעיית העלית\l"
	.string "בליגת הפוקימון בשלב מסוים.\p"
	.string "זה לא יפתיע אותי לראות את פלאנרי\n"
	.string "הופכת למאמנת גדולה בזכות\l"
	.string "עצמה.$"

FallarborTown_Text_BattleTentSign:
	.string "אוהל הקרב אתר פולרבר\n"
	.string "”מי יתן והצוותים הגדולים ביותר יתאספו!“$"

FallarborTown_Text_TownSign:
	.string "עיירת פולרבר\n"
	.string "”קהילה חקלאית עם גנים קטנים.“$"

FallarborTown_Text_MoveTutorSign:
	.string "הבית של מלמד המהלכים\n"
	.string "“מהלכים חדשים נלמדים לפוקימונים.”$"

