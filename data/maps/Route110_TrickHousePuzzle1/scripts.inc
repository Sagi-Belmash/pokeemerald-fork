Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} כתב{ADD_HEY} את הקוד הסודי\n"
	.string "על הדלת.\p"
	.string "”מאסטר הטריקים הוא מדהים.“\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "אני אחתוך ואקרע את דרכי לניצחון\n"
	.string "בעזרת חיתוך, שזה עתה למדנו!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "למה את{EMIT_HEY} כל כך רציני{ADD_TAF}?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "אני אף פעם לא מתעייפת מלחתוך\n"
	.string "ולקרוע!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "אני נכנסתי בטעות לתוך הבית\n"
	.string "המוזר הזה…$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "ועכשיו הפסדתי…$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "נאבדה לי הדרך, הפסדתי בקרב, ועכשיו\n"
	.string "אני אפילו עוד יותר אבוד… אני לא יכול לצאת…$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "מי הוא בכלל מאסטר הטריקים?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "הפסדתי בזמן שהייתי שקוע במחשבות!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "את{EMIT_HEY} חזק{ADD_HEY}!\n"
	.string "מי את{EMIT_HEY} בכלל?$"

