MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "מה, מה, מה?\p"
	.string "רק חברי צוות מגמה אמורים\n"
	.string "להיות כאן!\p"
	.string "אבל את{EMIT_HEY} לא לבוש{ADD_HEY} במדים של\n"
	.string "צוות מגמה…\p"
	.string "את{EMIT_HEY} מעוררת{ADD_TAF} את חשדי!\n"
	.string "הילח{SWAP_MEM}{ADD_YUD} בי!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "אייייי\n"
	.string "הכבוד שלי כחברת צוות מגמה…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "אם את{EMIT_HEY} סובל{ADD_TAF} מצמרמורות, כדאי\n"
	.string "לך להצטרף לצוות מגמה.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "עצ{EMIT_VAV}ר{ADD_YUD} בדיוק שם!\p"
	.string "את{EMIT_HEY} באמת לא מצפה ממני לסתום\n"
	.string "את הפה ולתת לך לחלוף על פני?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "אוו ואו!\n"
	.string "אני נכנע!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "אולי עדיף היה פשוט לתת לך\n"
	.string "לעבור ללא אתגר…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "אהאה!\n"
	.string "פולש{ADD_TAF}!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "גראאאה!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "כבר הפסדתי.\p"
	.string "האם אני באמת צריך להמשיך\n"
	.string "לרוץ במעגל?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "או, או!\n"
	.string "פולש{ADD_TAF}!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "מלמול…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "האמת, אני לא מומחה בקרבות…$"

