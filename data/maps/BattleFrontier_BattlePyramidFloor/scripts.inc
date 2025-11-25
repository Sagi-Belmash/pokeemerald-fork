BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, LOCALID_NONE, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "זהו הודעה לדוגמה.$"

gText_BattlePyramidConfirmRest::
	.string "המשימה שלך בפירמידת הקרב תישמר\n"
	.string "כך שתוכל{ADD_YUD} לצאת לעכשיו.\l"
	.string "האם זה בסדר?$"

gText_BattlePyramidConfirmRetire::
	.string "האם את{EMIT_HEY} בטוח{ADD_HEY} שאת{EMIT_HEY} רוצה להפסיק\n"
	.string "את המשימה שלך בפירמידת הקרב?$"

BattlePyramid_Text_ExitHintUp1::
	.string "יציאת הקומה הזאת היא\n"
	.string "בכיוון הזה: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "יציאתה הקומה הזאת היא\n"
	.string "בכיוון הזה: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "יציאת הקומה הזאת היא\n"
	.string "בכיוון הזה: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "יציאת הקומה הזאת היא\n"
	.string "בכיוון הזה: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "היציאה בקומה הזאת היא\n"
	.string "בכיוון {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "היציאה בקומה הזאת היא\n"
	.string "בכיוון {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2::
	.string "היציאה בקומה הזאת היא\n"
	.string "בכיוון {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2::
	.string "היציאה בקומה הזאת היא\n"
	.string "בכיוון {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3::
	.string "היציאה היא לכיוון\n"
	.string "{UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "היציאה היא לכיוון\n"
	.string "{LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight3::
	.string "היציאה היא לכיוון\n"
	.string "{RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown3::
	.string "היציאה היא לכיוון\n"
	.string "{DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp4::
	.string "בקומה הזאת, היציאה היא איפשהו\n"
	.string "בכיוון {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "בקומה הזאת, היציאה היא איפשהו\n"
	.string "בכיוון {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4::
	.string "בקומה הזאת, היציאה היא איפשהו\n"
	.string "בכיוון {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4::
	.string "בקומה הזאת, היציאה היא איפשהו\n"
	.string "בכיוון {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5::
	.string "היציאה?\n"
	.string "זה בכיוון {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "היציאה?\n"
	.string "זה בכיוון {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight5::
	.string "היציאה?\n"
	.string "זה בכיוון {RIGHT_ARROW}ay.$"

BattlePyramid_Text_ExitHintDown5::
	.string "היציאה?\n"
	.string "זה בכיוון {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp6::
	.string "היציאה במקרה נמצאת\n"
	.string "בכיוון {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "היציאה במקרה נמצאת\n"
	.string "בכיוון {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6::
	.string "היציאה במקרה נמצאת\n"
	.string "בכיוון {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6::
	.string "היציאה במקרה נמצאת\n"
	.string "בכיוון {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "מחפשים פריטים?\p"
	.string "נשארו שמונה פריטים\n"
	.string "למצוא.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "מחפשים פריטים?\p"
	.string "נשארו שבעה פריטים\n"
	.string "למצוא.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "מחפשים פריטים?\p"
	.string "נשארו שישה פריטים\n"
	.string "למצוא.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "מחפשים פריטים?\p"
	.string "נשארו חמישה פריטים\n"
	.string "למצוא.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "מחפשים פריטים?\p"
	.string "נשארו ארבעה פריטים\n"
	.string "למצוא.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "מחפשים פריטים?\p"
	.string "נשארו שלושה פריטים\n"
	.string "למצוא.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "מחפשים פריטים?\p"
	.string "נשארו שני פריטים\n"
	.string "למצוא.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "מחפשים פריטים?\p"
	.string "נשאר פריט אחד\n"
	.string "למצוא.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "מחפשים פריטים?\p"
	.string "אין פריטים נוספים\n"
	.string "למצוא!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "מכיוון שניצחת, אני אספר לך\n"
	.string "סוד קטן!\p"
	.string "ישנם שמונה פריטים\n"
	.string "שנמצאים בסביבה כאן.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "מכיוון שניצחת, אני אספר לך\n"
	.string "סוד קטן!\p"
	.string "ישנם שבעה פריטים\n"
	.string "שנמצאים בסביבה כאן.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "מכיוון שניצחת, אני אספר לך\n"
	.string "סוד קטן!\p"
	.string "ישנם שישה פריטים\n"
	.string "שנמצאים בסביבה כאן.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "מכיוון שניצחת, אני אספר לך\n"
	.string "סוד קטן!\p"
	.string "ישנם חמישה פריטים\n"
	.string "שנמצאים בסביבה כאן.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "מכיוון שניצחת, אני אספר לך\n"
	.string "סוד קטן!\p"
	.string "ישנם ארבעה פריטים\n"
	.string "שנמצאים בסביבה כאן.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "מכיוון שניצחת, אני אספר לך\n"
	.string "סוד קטן!\p"
	.string "ישנם שלושה פריטים\n"
	.string "שנמצאים בסביבה כאן.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "מכיוון שניצחת, אני אספר לך\n"
	.string "סוד קטן!\p"
	.string "ישנם שני פריטים\n"
	.string "שנמצאים בסביבה כאן.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "מכיוון שניצחת, אני אספר לך\n"
	.string "סוד קטן!\p"
	.string "יש פריט אחד\n"
	.string "שנמצא בסביבה כאן.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "מכיוון שניצחת, אני אספר לך\n"
	.string "סוד קטן!\p"
	.string "לא נשאר דבר\n"
	.string "שנמצא בסביבה כאן.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "איך עומד מלאי הפריטים שלך?\p"
	.string "אני משער שנשארו שמונה פריטים\n"
	.string "שמחכים להימצא בקומה הזאת.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "איך עומד מלאי הפריטים שלך?\p"
	.string "אני משער שנשארו שבעה פריטים\n"
	.string "שמחכים להימצא בקומה הזאת.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "איך עומד מלאי הפריטים שלך?\p"
	.string "אני משער שנשארו שישה פריטים\n"
	.string "שמחכים להימצא בקומה הזאת.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "איך עומד מלאי הפריטים שלך?\p"
	.string "אני משער שנשארו חמישה פריטים\n"
	.string "שמחכים להימצא בקומה הזאת.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "איך עומד מלאי הפריטים שלך?\p"
	.string "אני משער שנשארו ארבעה פריטים\n"
	.string "שמחכים להימצא בקומה הזאת.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "איך עומד מלאי הפריטים שלך?\p"
	.string "אני משער שנשארו שלושה פריטים\n"
	.string "שמחכים להימצא בקומה הזאת.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "איך עומד מלאי הפריטים שלך?\p"
	.string "אני משער שנשארו שני פריטים\n"
	.string "שמחכים להימצא בקומה הזאת.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "איך עומד מלאי הפריטים שלך?\p"
	.string "אני משער שנשאר פריט אחד\n"
	.string "שמחכה להימצא בקומה הזאת.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "איך עומד מלאי הפריטים שלך?\p"
	.string "אני משער שאין יותר פריטים\n"
	.string "שמחכים להימצא בקומה הזאת.\l"
	.string "את{EMIT_HEY} תשמ{EMIT_VAV}ר{ADD_YUD} על עצמך!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "את{EMIT_HEY} חזק{ADD_HEY}, אז הרווחת רמז!\p"
	.string "נראה שישנם עוד שמונה\n"
	.string "פריטים על הקרקע.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "את{EMIT_HEY} חזק{ADD_HEY}, אז הרווחת רמז!\p"
	.string "נראה שישנם עוד שבעה\n"
	.string "פריטים על הקרקע.$"


BattlePyramid_Text_SixItemsRemaining4::
	.string "את{EMIT_HEY} חזק{ADD_HEY}, אז הרווחת רמז!\p"
	.string "נראה שישנם עוד שישה\n"
	.string "פריטים על הקרקע.$"


BattlePyramid_Text_FiveItemsRemaining4::
	.string "את{EMIT_HEY} חזק{ADD_HEY}, אז הרווחת רמז!\p"
	.string "נראה שישנם עוד חמישה\n"
	.string "פריטים על הקרקע.$"


BattlePyramid_Text_FourItemsRemaining4::
	.string "את{EMIT_HEY} חזק{ADD_HEY}, אז הרווחת רמז!\p"
	.string "נראה שישנם עוד ארבעה\n"
	.string "פריטים על הקרקע.$"


BattlePyramid_Text_ThreeItemsRemaining4::
	.string "את{EMIT_HEY} חזק{ADD_HEY}, אז הרווחת רמז!\p"
	.string "נראה שישנם עוד שלושה\n"
	.string "פריטים על הקרקע.$"


BattlePyramid_Text_TwoItemsRemaining4::
	.string "את{EMIT_HEY} חזק{ADD_HEY}, אז הרווחת רמז!\p"
	.string "נראה שישנם עוד שני\n"
	.string "פריטים על הקרקע.$"


BattlePyramid_Text_OneItemRemaining4::
	.string "את{EMIT_HEY} חזק{ADD_HEY}, אז הרווחת רמז!\p"
	.string "נראה שישנו עוד פריט\n"
	.string "אחד על הקרקע.$"


BattlePyramid_Text_ZeroItemsRemaining4::
	.string "את{EMIT_HEY} חזק{ADD_HEY}, אז הרווחת רמז!\p"
	.string "נראה שאין פריטים\n"
	.string "על הקרקע.$"


BattlePyramid_Text_EightItemsRemaining5::
	.string "בקומה הזאת של הפירמידה,\n"
	.string "שמעתי שיש שמונה פריטים…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "בקומה הזאת של הפירמידה,\n"
	.string "שמעתי שיש שבעה פריטים…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "בקומה הזאת של הפירמידה,\n"
	.string "שמעתי שיש שישה פריטים…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "בקומה הזאת של הפירמידה,\n"
	.string "שמעתי שיש חמישי פריטים…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "בקומה הזאת של הפירמידה,\n"
	.string "שמעתי שיש ארבעה פריטים…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "בקומה הזאת של הפירמידה,\n"
	.string "שמעתי שיש שלושה פריטים…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "בקומה הזאת של הפירמידה,\n"
	.string "שמעתי שיש שני פריטים…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "בקומה הזאת של הפירמידה,\n"
	.string "שמעתי שיש פריט אחד…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "בקומה הזאת של הפירמידה,\n"
	.string "שמעתי שאין פריטים…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "האם אספת פריטים כלשהם?\p"
	.string "אני מאמין שישנם עוד שמונה\n"
	.string "פריטים בקומה הזאת.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "האם אספת פריטים כלשהם?\p"
	.string "אני מאמין שישנם עוד שבעה\n"
	.string "פריטים בקומה הזאת.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "האם אספת פריטים כלשהם?\p"
	.string "אני מאמין שישנם עוד שישה\n"
	.string "פריטים בקומה הזאת.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "האם אספת פריטים כלשהם?\p"
	.string "אני מאמין שישנם עוד חמישה\n"
	.string "פריטים בקומה הזאת.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "האם אספת פריטים כלשהם?\p"
	.string "אני מאמין שישנם עוד ארבעה\n"
	.string "פריטים בקומה הזאת.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "האם אספת פריטים כלשהם?\p"
	.string "אני מאמין שישנם עוד שלושה\n"
	.string "פריטים בקומה הזאת.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "האם אספת פריטים כלשהם?\p"
	.string "אני מאמין שישנם עוד שני\n"
	.string "פריטים בקומה הזאת.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "האם אספת פריטים כלשהם?\p"
	.string "אני מאמין שישנו עוד פריט\n"
	.string "אחד בקומה הזאת.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "האם אספת פריטים כלשהם?\p"
	.string "אני מאמין שאין יותר פריטים\n"
	.string "בקומה הזאת.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "היית מדהי{SWAP_MEM}{ADD_HEY} ממש!\p"
	.string "אבל ישנם עדיין שבעה מאמנים\n"
	.string "קשוחים חוץ ממני!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "היית מדהי{SWAP_MEM}{ADD_HEY} ממש!\p"
	.string "אבל ישנם עדיין שישה מאמנים\n"
	.string "קשוחים חוץ ממני!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "היית מדהי{SWAP_MEM}{ADD_HEY} ממש!\p"
	.string "אבל ישנם עדיין חמישה מאמנים\n"
	.string "קשוחים חוץ ממני!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "היית מדהי{SWAP_MEM}{ADD_HEY} ממש!\p"
	.string "אבל ישנם עדיין ארבעה מאמנים\n"
	.string "קשוחים חוץ ממני!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "היית מדהי{SWAP_MEM}{ADD_HEY} ממש!\p"
	.string "אבל ישנם עדיין שלושה מאמנים\n"
	.string "קשוחים חוץ ממני!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "היית מדהי{SWAP_MEM}{ADD_HEY} ממש!\p"
	.string "אבל ישנם עדיין שני מאמנים\n"
	.string "קשוחים חוץ ממני!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "היית מדהי{SWAP_MEM}{ADD_HEY} ממש!\p"
	.string "אבל ישנו עדיין מאמן אחד\n"
	.string "קשוחים חוץ ממני!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "היית מדהי{SWAP_MEM}{ADD_HEY} ממש!\p"
	.string "לא נשאר אף אחד שיכול\n"
	.string "להביס אותך!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "זה כל כך מרגיז!\p"
	.string "אבל נשארו שבעה מאמנים!\n"
	.string "מישהו עוד ירשים אותך!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "זה כל כך מרגיז!\p"
	.string "אבל נשארו שישה מאמנים!\n"
	.string "מישהו עוד ירשים אותך!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "זה כל כך מרגיז!\p"
	.string "אבל נשארו חמישה מאמנים!\n"
	.string "מישהו עוד ירשים אותך!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "זה כל כך מרגיז!\p"
	.string "אבל נשארו ארבעה מאמנים!\n"
	.string "מישהו עוד ירשים אותך!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "זה כל כך מרגיז!\p"
	.string "אבל נשארו שלושה מאמנים!\n"
	.string "מישהו עוד ירשים אותך!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "זה כל כך מרגיז!\p"
	.string "אבל נשארו שני מאמנים!\n"
	.string "מישהו עוד ירשים אותך!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "זה כל כך מרגיז!\p"
	.string "אבל נשאר מאמן אחד!\n"
	.string "מישהו עוד ירשים אותך!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "זה כל כך מרגיז!\p"
	.string "אבל אין יותר מאמנים שיכולים\n"
	.string "להתמודד מולך!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "זה די מרשים!\p"
	.string "אבל יש עוד שבעה מאמנים\n"
	.string "בקומה הזאת. את{EMIT_HEY} יכול{ADD_HEY} להביס את כולם?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "זה די מרשים!\p"
	.string "אבל יש עוד שישה מאמנים\n"
	.string "בקומה הזאת. את{EMIT_HEY} יכול{ADD_HEY} להביס את כולם?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "זה די מרשים!\p"
	.string "אבל יש עוד חמישה מאמנים\n"
	.string "בקומה הזאת. את{EMIT_HEY} יכול{ADD_HEY} להביס את כולם?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "זה די מרשים!\p"
	.string "אבל יש עוד ארבעה מאמנים\n"
	.string "בקומה הזאת. את{EMIT_HEY} יכול{ADD_HEY} להביס את כולם?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "זה די מרשים!\p"
	.string "אבל יש עוד שלושה מאמנים\n"
	.string "בקומה הזאת. את{EMIT_HEY} יכול{ADD_HEY} להביס את כולם?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "זה די מרשים!\p"
	.string "אבל יש עוד שני מאמנים\n"
	.string "בקומה הזאת. את{EMIT_HEY} יכול{ADD_HEY} להביס את כולם?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "זה די מרשים!\p"
	.string "אבל יש עוד מאמן אחד\n"
	.string "בקומה הזאת. את{EMIT_HEY} יכול{ADD_HEY} להביס את כולם?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "זה די מרשים!\p"
	.string "עברת דרך כל המאמנים\n"
	.string "בקומה הזאת.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "אולי תוכל{ADD_YUD} להכניע\n"
	.string "את שבעת המאמנים שנשארו בקומה הזאת.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "אולי תוכל{ADD_YUD} להכניע\n"
	.string "את ששת המאמנים שנשארו בקומה הזאת.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "אולי תוכל{ADD_YUD} להכניע\n"
	.string "את חמשת המאמנים שנשארו בקומה הזאת.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "אולי תוכל{ADD_YUD} להכניע\n"
	.string "את ארבעת המאמנים שנשארו בקומה הזאת.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "אולי תוכל{ADD_YUD} להכניע\n"
	.string "את שלושת המאמנים שנשארו בקומה הזאת.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "אולי תוכל{ADD_YUD} להכניע\n"
	.string "את שני המאמנים שנשארו בקומה הזאת.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "אולי תוכל{ADD_YUD} להשלים את ההכנעה\n"
	.string "עם המאמן היחידי שנשאר בקומה הזאת.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "לא נשאר אף אחד שיכול\n"
	.string "להביס אותך כרגע…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "אולי יש לך את מה שנדרש כדי לנצח\n"
	.string "את שבעת המאמנים המומחים שנותרו.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "אולי יש לך את מה שנדרש כדי לנצח\n"
	.string "את ששת המאמנים המומחים שנותרו.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "אולי יש לך את מה שנדרש כדי לנצח\n"
	.string "את חמשת המאמנים המומחים שנותרו.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "אולי יש לך את מה שנדרש כדי לנצח\n"
	.string "את ארבעת המאמנים המומחים שנותרו.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "אולי יש לך את מה שנדרש כדי לנצח\n"
	.string "את שלושת המאמנים המומחים שנותרו.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "אולי יש לך את מה שנדרש כדי לנצח\n"
	.string "את שני המאמנים המומחים שנותרו.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "אולי יש לך את מה שנדרש כדי לנצח\n"
	.string "את המאמן המומחה היחידי שנותר.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "הכישורים שלך הם ללא דופי.\p"
	.string "אין כאן יותר מאמנים\n"
	.string "שיש להם סיכוי להביס אותך.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "האם את{EMIT_HEY} יכול{ADD_HEY} להמשיך ולנצח מול\n"
	.string "שבעת המאמנים שנותרו?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "האם את{EMIT_HEY} יכול{ADD_HEY} להמשיך ולנצח מול\n"
	.string "ששת המאמנים שנותרו?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "האם את{EMIT_HEY} יכול{ADD_HEY} להמשיך ולנצח מול\n"
	.string "חמשת המאמנים שנותרו?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "האם את{EMIT_HEY} יכול{ADD_HEY} להמשיך ולנצח מול\n"
	.string "ארבעת המאמנים שנותרו?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "האם את{EMIT_HEY} יכול{ADD_HEY} להמשיך ולנצח מול\n"
	.string "שלושת המאמנים שנותרו?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "האם את{EMIT_HEY} יכול{ADD_HEY} להמשיך ולנצח מול\n"
	.string "שני המאמנים שנותרו?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "האם את{EMIT_HEY} יכול{ADD_HEY} להמשיך ולנצח מול\n"
	.string "המאמן היחידי שנותר?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "אין יותר מאמנים שנותרו\n"
	.string "להתמודד מולך עכשיו…$"
