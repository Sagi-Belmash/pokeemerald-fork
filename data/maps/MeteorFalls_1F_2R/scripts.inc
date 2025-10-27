MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "כאן זה המקום שבו מאמני דרקונים\n"
	.string "מתאמנים.\p"
	.string "אפילו האלוף מבקר.\n"
	.string "עכשיו את{EMIT_HEY} מבי{SWAP_NUN}{ADD_HEY} כמה המקום הזה מיוחד?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "אחח!\n"
	.string "לא ציפיתי שתהי{EMIT_HEY}{ADD_YUD} כל כך חזק{ADD_HEY}!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "הדרך מלפנים ארוכה וקשה.\p"
	.string "מתי הפוקימונים שלי ואני נהיה\n"
	.string "הכי טובים?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "אני רוצה ללמוד עוד על הכוח שלך.\n"
	.string "בוא{ADD_YUD} אני ארשום אותך בפוקינווט שלי.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "מאז שנפגשנו, התאמנו הרבה\n"
	.string "כדי להיות מספר אחד.\p"
	.string "עז{EMIT_VAV}ר{ADD_YUD} לנו לראות כמה\n"
	.string "התחזקנו!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "אחח!\n"
	.string "לא ציפיתי שתהי{EMIT_HEY}{ADD_YUD} כל כך חזק{ADD_HEY}!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "כמובן שהתמדת באימוני\n"
	.string "פוקימון שלך.\p"
	.string "כל עוד את{EMIT_HEY} נשאר{ADD_TAF} חזק{ADD_HEY}, גם אני אוכל\n"
	.string "להתחזק!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "ג'ון: תמיד נלחמנו בפוקימונים\n"
	.string "ביחד, כצמד.\l"
	.string "יש לנו ביטחון בעצמנו.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "ג'ון: אוי, באמת.\n"
	.string "הפסדנו, אשתי היקרה.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "ג'ון: אנחנו נשואים כבר חמישים שנה.\p"
	.string "עכשיו כשאני חושב על זה, עוד לא\n"
	.string "הצלחתי לנצח את אשתי בקרב.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "ג'ון: ובכן, ובכן, איזה מאמ{SWAP_NUN}{ADD_TAF} צעיר{ADD_HEY}!\p"
	.string "תרצ{EMIT_HEY}{ADD_YUD} להילחם בנו? אם כן, תצטר{SWAP_CHAF}{ADD_YUD}\n"
	.string "לחזור עם עוד פוקימונים.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "ג'ון: מאמ{SWAP_NUN}{ADD_TAF} צעיר{ADD_HEY}, אם תצא \n"
	.string "ההזדמנות, האם תילח{SWAP_MEM}{ADD_YUD} בנו שוב?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "ג'יי: אנחנו נשואים כבר\n"
	.string "חמישים שנה.\p"
	.string "הקשר שמשותף לנו כזוג\n"
	.string "לא יכול להישבר לעולם.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "ג'יי: אוי, יקירי.\n"
	.string "הפסדנו, בעלי היקר.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "ג'יי: חמישים שנות נישואים…\p"
	.string "אם אי פעם רבנו, תמיד פתרנו את זה\n"
	.string "בקרב פוקימונים…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "ג'ון: ובכן, ובכן, איזה מאמ{SWAP_NUN}{ADD_TAF} צעיר{ADD_HEY}!\p"
	.string "תרצ{EMIT_HEY}{ADD_YUD} להילחם בנו? אם כן, תצטר{SWAP_CHAF}{ADD_YUD}\n"
	.string "לחזור עם עוד פוקימונים.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "ג'ון: תמיד נלחמנו בפוקימונים\n"
	.string "ביחד, כצמד.\l"
	.string "יש לנו ביטחון בעצמנו.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "ג'ון: אוי, באמת.\n"
	.string "הפסדנו, אשתי היקרה.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "ג'ון: נשואים כבר חמישים שנה\p"
	.string "במבט לאחור, אשתי היקרה ואני,\n"
	.string "נלחמנו יום-יום ללא הפסקה…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "ג'ון: ובכן, ובכן, איזה מאמ{SWAP_NUN}{ADD_TAF} צעיר{ADD_HEY}!\p"
	.string "תרצ{EMIT_HEY}{ADD_YUD} להילחם בנו? אם כן, תצטר{SWAP_CHAF}{ADD_YUD}\n"
	.string "לחזור עם עוד פוקימונים.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "ג'יי: אנחנו נשואים כבר\n"
	.string "חמישים שנה.\p"
	.string "תמיד תמכנו אחד בשני.\n"
	.string "זה מה שחיזק אותנו.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "ג'יי: אוי, יקירי.\n"
	.string "הפסדנו, בעלי היקר.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "ג'יי: חמישים שנות נישואים…\n"
	.string "הרבה דברים קרו.\p"
	.string "אני מקווה שנמשיך ליצור\n"
	.string "זכרונות משמחים ביחד.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "ג'ון: ובכן, ובכן, איזה מאמ{SWAP_NUN}{ADD_TAF} צעיר{ADD_HEY}!\p"
	.string "תרצ{EMIT_HEY}{ADD_YUD} להילחם בנו? אם כן, תצטר{SWAP_CHAF}{ADD_YUD}\n"
	.string "לחזור עם עוד פוקימונים.$"

