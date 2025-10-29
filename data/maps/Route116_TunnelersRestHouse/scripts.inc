Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "מנהרת רסטרף הזאת שם…\p"
	.string "בהתחלה, היה לנו צוות ענק שקדח\n"
	.string "דרך הסלע עם המכונות החדישות ביותר.\l"
	.string "אבל, היינו חייבים להפסיק.\p"
	.string "התברר שתהיה לזה השפעה\n"
	.string "שלילית על הפוקימונים הפראיים\l"
	.string "באזור.\p"
	.string "אז, אין לנו מה לעשות חוץ מאשר\n"
	.string "להסתובב פה בחוסר מעש.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "יש איש שחופר את דרכו לורדנטרף\n"
	.string "לבד לגמרי.\l"
	.string "הוא נואש לעבור דרכה.\p"
	.string "הוא אומר שאם הוא יחפור לאט לאט\n"
	.string "בלי להשתמש במכונות, הוא לא\l"
	.string "יפריע לפוקימונים, והוא ימנע\l"
	.string "פגיעה בסביבה הטבעית.\p"
	.string "מעניין אם הוא כבר הצליח לעבור.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "כדי להגיע לורדנטרף בלי להשתמש\n"
	.string "במנהרה הזו, תצטר{SWAP_CHAF}{ADD_YUD} לחצות את\l"
	.string "הים לדופורד, להפליג לסלייטפורט,\l"
	.string "ואז לטייל דרך מוויל.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "שמעת? המנהרה לורדנטרף\n"
	.string "נפרצה!\p"
	.string "לפעמים, אם מקווים חזק מספיק,\n"
	.string "חלומות מתגשמים.$"

