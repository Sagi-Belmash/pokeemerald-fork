Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "אני חובב המאובנים…\n"
	.string "אני בן אדם נחמד שאוהב מאובנים…\p"
	.string "רוצה מאובן?\p"
	.string "אבל כל המאובנים באזור הזה\n"
	.string "שייכים לי… כלום בשבילך…\p"
	.string "אם אינך מסוגל{ADD_TAF} להיות בלי\n"
	.string "מאובן, תסתכל{ADD_YUD} במדבר איפה שיש\l"
	.string "סלעים וחול שיכולים להסתיר\l"
	.string "מאובנים…$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "מצאת מאובן, לא כך?\n"
	.string "זה ממש נחמד… זה כל כך חלומי…\p"
	.string "מה תעש{EMIT_HEY}{ADD_YUD} עם המאובן הזה?\p"
	.string "ממה ששמעתי, דבון עושה מחקר\n"
	.string "על החייאת פוקימונים ממאובנים…\p"
	.string "אני אוהב את המאובנים שלי, אז אני לעולם לא\n"
	.string "אעשה דבר כזה…$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "מאובנים הם כל כך… נפלאים…\n"
	.string "זה כל כך חלומי…$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "או…\n"
	.string "זה לא בטוח בכיוון הזה…\p"
	.string "אני חרפתי שם, את{EMIT_HEY} מבי{SWAP_NUN}{ADD_HEY}…\n"
	.string "כשהקיר כולו קרס…\p"
	.string "אני חושב שיש מערה תת\n"
	.string "קרקעית עכשיו…\p"
	.string "אבל השארתי אותה כמו שהיא כי אני לא\n"
	.string "חושב שיש שם עוד מאובנים…$"

