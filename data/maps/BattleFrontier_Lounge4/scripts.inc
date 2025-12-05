BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
    .string "אני תוהה אם היום ישדרו ראיונות\n"
    .string "עם מאמנים קשוחים?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
    .string "אם הייתי פותח מסעדה כאן,\n"
    .string "זה בוודאי היה מרוויח כסף.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
    .string "ווהו…\p"
    .string "אני צריך לנשום קצת אחרי\n"
    .string "כמה קרבות אינטנסיביים…\p"
    .string "אבל אפילו עכשיו, אני אף פעם לא לוקח הפסקה\n"
    .string "מלתכנן אסטרטגיה ושילובים.$"

