MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "החייאה היא נהדרת!\p"
	.string "ת{SWAP_NUN}{ADD_YUD} אותה לפוקימון שהתמוטט,\n"
	.string "והוא יקום לתחייה.\p"
	.string "אבל היזהר{ADD_YUD}, החייאה לא משחזרת\n"
	.string "נכ שהמהלכים השתמשו.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "דוחה יתר מונע הופעת פוקימונים חלשים.\p"
	.string "מבין כל תרסיסי ההדחה, הוא מחזיק\n"
	.string "הכי הרבה זמן.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "כדור רשת וכדור צלילה הם כדורי פוכדור נדירים\n"
	.string "שמיוצרים רק במוסדיפ.\p"
	.string "כדור רשת יעיל נגד פוקימונים\n"
	.string "מהסוג חרק ומהסוג מים.\p"
	.string "כדור צלילה עובד הכי טוב על פוקימונים\n"
	.string "שנמצאים בתחתית הים.$"

