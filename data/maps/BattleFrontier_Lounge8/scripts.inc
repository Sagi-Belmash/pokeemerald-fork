BattleFrontier_Lounge8_MapScripts::
	.byte 0

BattleFrontier_Lounge8_EventScript_Man::
	msgbox BattleFrontier_Lounge8_Text_WhatATrainerNeeds, MSGBOX_NPC
	end

BattleFrontier_Lounge8_EventScript_Woman::
	msgbox BattleFrontier_Lounge8_Text_KnowAboutFrontierBrains, MSGBOX_NPC
	end

BattleFrontier_Lounge8_EventScript_NinjaBoy::
	msgbox BattleFrontier_Lounge8_Text_ToldMeIHaveTalentForBattling, MSGBOX_NPC
	end

BattleFrontier_Lounge8_Text_WhatATrainerNeeds:
    .string "מה שמאמן צריך…\p"
    .string "ידע…\n"
    .string "אסטרטגיה…\l"
    .string "מזל…\l"
    .string "אומץ…\l"
    .string "רוח…\l"
    .string "גבורה…\l"
    .string "וכישרון…\p"
    .string "טוב, אצלי הכול מסודר!\n"
    .string "אני אהיה בלתי עציר בכל מבנה!\p"
    .string "הא? פוקימון?\n"
    .string "מה זה?$"

BattleFrontier_Lounge8_Text_KnowAboutFrontierBrains:
    .string "את{EMIT_HEY} מכיר{ADD_HEY} את ראשי החזית?\p"
    .string "זה מה שסקוט קורא לשבעת\n"
    .string "המאמנים המיוחדים שמנהלים את\l"
    .string "שבעת המתקנים בחזית הקרב.$"

BattleFrontier_Lounge8_Text_ToldMeIHaveTalentForBattling:
    .string "במגדל הקרב, נערה מבוגרת\n"
    .string "אמרה לי שיש לי הרבה כישרון\l"
    .string "לקרבות!\p"
    .string "אבל אני יותר אוהב תחרויות פוקימון!\p"
    .string "רק שאני לא טוב בתחרויות!\p"
    .string "נראה שכישרון ואהבה לדבר\n"
    .string "הם לא אותו דבר.$"

