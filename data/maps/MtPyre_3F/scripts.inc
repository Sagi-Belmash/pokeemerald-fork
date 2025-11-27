MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "האווירה העשירה של ההר\n"
	.string "העלתה את הכוח העל חושי שלי!\p"
	.string "ילד{ADD_HEY} פשוט{ADD_HEY} כמוך…\n"
	.string "את{EMIT_HEY} חול{SWAP_MEM}{ADD_TAF} על ניצחון?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "אני שוקע ברחמים עצמיים…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "הכוחות העל חושיים שלי ודאי\n"
	.string "גדלו פי כמה, אבל…$"

MtPyre_3F_Text_KaylaIntro:
	.string "אהאהאהאהא!\p"
	.string "זה לא מקום לילדים, ובוודאי\n"
	.string "לא לך!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "הפסדתי בצורה כה נקייה…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "זה אומר שהאימונים שלי עדיין לא\n"
	.string "מספיקים…\p"
	.string "אני חייבת להמשיך לעבוד לכיוון\n"
	.string "הפסגה…\p"
	.string "קדימה, אני!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "למה באת לכאן?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "זה היה מדהים!\n"
	.string "את{EMIT_HEY} מאמ{SWAP_NUN}{ADD_TAF} מיוחד{ADD_TAF} מאוד.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "פוקימונים שכבר אינם בעולם הזה.\n"
	.string "פוקימונים שנמצאים איתך עכשיו.\p"
	.string "והפוקימונים שאת{EMIT_HEY} תפג{EMIT_VAV}ש{ADD_YUD}\n"
	.string "בעתיד…\p"
	.string "יש להוקיר את כולם באופן שווה.\n"
	.string "בבקשה זכ{EMIT_VAV}ר{ADD_YUD} זאת.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "הייתי רוצה לראות את הפוקימונים\n"
	.string "שלך כשהם יגדלו עוד קצת…\p"
	.string "בבקשה, אני צריכה לראות את הפוקינווט שלך.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "או, זה את{EMIT_HEY}…\p"
	.string "האם באת להראות לי את הפוקימונים\n"
	.string "הבוגרים שלך?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "איזה מדהים!\n"
	.string "את{EMIT_HEY} אדם מיוחד.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "פוקימונים שכבר אינם בעולם הזה.\n"
	.string "פוקימונים שנמצאים איתך עכשיו.\p"
	.string "והפוקימונים שאת{EMIT_HEY} תפג{EMIT_VAV}ש{ADD_YUD}\n"
	.string "בעתיד…\p"
	.string "יש להוקיר את כולם באופן שווה.\n"
	.string "אני רואה שזכרת את זה.$"

