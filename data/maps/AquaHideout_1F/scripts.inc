AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "מה? מה? מה את{EMIT_HEY} רוצה מצוות אקווה?\p"
	.string "הבוס שלנו לא כאן! הוא יצא\n"
	.string "לחטוף משהו חשוב!\p"
	.string "… …\n"
	.string "לאן הוא הלך?\p"
	.string "וואהאהא! האם את{EMIT_HEY} באמת חושב{ADD_TAF} שאגיד\n"
	.string "לך משהו כל כך חשוב?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "מה? מה?\n"
	.string "את{EMIT_HEY} עובד{ADD_TAF} פשוט{ADD_HEY} של צוות מגמה?\p"
	.string "אני שומע שצוות מגמה מנסה\n"
	.string "להעיר פוקימון אדיר במחבוא\l"
	.string "שלהם.\p"
	.string "אבל איפה יכול להיות המחבוא שלהם?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "מה? מה? מה את{EMIT_HEY} רוצה מצוות אקווה?\p"
	.string "הבוס שלנו לא כאן!\n"
	.string "הוא יצא לגנוב צוללת!\p"
	.string "… …\n"
	.string "לאן הוא הלך?\p"
	.string "וואהאהא! האם את{EMIT_HEY} באמת חושב{ADD_TAF} שאגיד\n"
	.string "לך משהו כל כך חשוב?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "מה? מה? מה את{EMIT_HEY} רוצה מצוות אקווה?\p"
	.string "הבוס שלנו לא כאן! הוא בדרכו אל\n"
	.string "הר המוקד בדרך 221!\p"
	.string "… …\n"
	.string "למה הוא הלך?\p"
	.string "וואהאהא! האם את{EMIT_HEY} באמת חושב{ADD_TAF} שאגיד\n"
	.string "לך משהו כל כך חשוב?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "מה? מה?\n"
	.string "את{EMIT_HEY} עובד{ADD_TAF} פשוט{ADD_HEY} של צוות מגמה?\p"
	.string "אני שומע שצוות מגמה רודף אחרי\n"
	.string "פוקימון אדיר בהר הארובה.\p"
	.string "אבל איך נראה הפוקימון הזה?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "מה? מה? מה את{EMIT_HEY} רוצה מצוות אקווה?\p"
	.string "הבוס שלנו לא כאן!\n"
	.string "הוא בדרכו לעיר סלייטפורט!\p"
	.string "… …\n"
	.string "למה הוא הלך?\p"
	.string "וואהאהא! האם את{EMIT_HEY} באמת חושב{ADD_TAF} שאגיד\n"
	.string "לך משהו כל כך חשוב?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "אייייי!\n"
	.string "דמות חשודה אותרה!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "גרררר…\n"
	.string "איבדתי את זה!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "ספגתי את ההפסד עבור הצוות,\n"
	.string "אבל עשיתי את העבודה שלי…$"

