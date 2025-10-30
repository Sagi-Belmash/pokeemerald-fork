PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "הים בין פסיפידלוג לסלייטפורט\n"
	.string "הוא בעל זרם מהיר.\p"
	.string "אם תחליט{ADD_YUD} להשתמש בגלישה, את{EMIT_HEY} עלול{ADD_YUD} לסיים\n"
	.string "להיסחף למקום אחר.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "רואה, זה לא נחמד?\n"
	.string "הבתים האלה על המים!\p"
	.string "נולדתי כאן!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "העמוד שמיים?\p"
	.string "…או, את{EMIT_HEY} בטח מתכוו{SWAP_NUN}{ADD_TAF} למגדל, tall\n"
	.string "הגבוה-גבוה ההוא קצת יותר רחוק.\p"
	.string "אם שאלת אותי, לא הייתי מטפס עליו.\n"
	.string "זה מפחיד מדי לטפס לכזה גובה.\p"
	.string "החיים בגובה פני הים בפסיפידלוג,\n"
	.string "זה מתאים לי בול.$"

PacifidlogTown_Text_TownSign:
	.string "עיירת פסיפידלוג\p"
	.string "”היכן ששמש הבוקר מחייכת אל\n"
	.string "המים.“$"

