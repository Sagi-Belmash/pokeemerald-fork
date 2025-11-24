MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "ווהו!\p"
	.string "שמעתי שקוראים לי איש המרסק סלעים,\n"
	.string "אבל אני חושב שזה קצת מעליב.\p"
	.string "אני חושב שמגיע לי קצת יותר כבוד,\n"
	.string "אולי כמו אדון מרסק הסלעים.\p"
	.string "ווהו!\p"
    .string "בכל מקרה, הפוקימונים שלך נראים די\n"
    .string "חזקים.\p"
	.string "אני אוהב את זה!\n"
	.string "הנה, קח את המכונה הנסתרת הזו!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "המ”נ הזה מכיל ריסוק.\p"
	.string "אם תתקל{ADD_YUD} בסלעים גדולים\n"
	.string "שחוסמים את הדרך…\p"
	.string "ובכן, תשתמש{ADD_YUD} במ”נ ותרסק{ADD_YUD} אותם\n"
	.string "מהדרך!\p"
	.string "כן, אדוני{ADD_TAF}! לרסק סלעים הצידה, אני אומר!\n"
	.string "ווהו!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "או, כן, אם תרסק{ADD_YUD} אבן, פוקימון\n"
	.string "עלול לקפוץ החוצה מהמסתור.\p"
	.string "ווהו!$"

