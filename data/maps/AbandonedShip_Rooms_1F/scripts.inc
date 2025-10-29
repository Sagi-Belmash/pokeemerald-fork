AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "ספינות מהסוג הזה הן נדירות, אז אני\n"
	.string "מסתכל מסביב.\p"
	.string "המממ…\n"
	.string "נראה שיש עוד תאים…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "מה בעולם גרם לך\n"
	.string "לבוא לכאן? את{EMIT_HEY} בטח סקר{SWAP_NUN}{ADD_YUD}{ADD_TAF}!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "לא רק סקר{SWAP_NUN}{ADD_YUD}{ADD_TAF}, אלא גם חזק{ADD_HEY}…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "האיש שבחדר הסמוך…\p"
	.string "הוא אומר שהוא רק תייר,\n"
	.string "אבל אני לא בטוחה בזה.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "אתה מאמ{SWAP_NUN}{ADD_TAF} כל כך חזק{ADD_HEY}!\n"
	.string "תני לי לרשום אותך בתור מזכרת!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "מה בעולם גרם לך\n"
	.string "לחזור לכאן? את{EMIT_HEY} באמת חייב{ADD_TAF} להיות סקר{SWAP_NUN}{ADD_YUD}{ADD_TAF}!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "את{EMIT_HEY} לא חזק{ADD_HEY} מדי?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "אני בטוחה שהאיש הזה זומם משהו!\n"
	.string "הוא פשוט מתנהג בצורה כל כך חשודה!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "אאאההה!\n"
	.string "מצאו אותי! …הא?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "אה, את{EMIT_HEY} לא אמא שלי.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "I'm in trouble with my mom, so I ran.\n"
	.string "Keep it a secret where I am!$"

