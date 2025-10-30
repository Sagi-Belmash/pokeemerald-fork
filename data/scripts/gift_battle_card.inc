MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "תודה שהשתמשת במערכת המתנה\n"
	.string "המסתורית.\p"
	.string "כרטיס ספירת הקרבות שלך עוקב\n"
	.string "אחר שיאי הקרבות שלך נגד\l"
	.string "מאמנים עם אותו כרטיס.\p"
	.string "חפשו והלחמו במאמנים שיש להם\n"
	.string "את אותו כרטיס כמוכם.\p"
	.string "אתם יכולים לבדוק את הדירוג הכללי\n"
	.string "על ידי קריאת החדשות.\p"
	.string "בבקשה נסו את זה!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "תודה שהשתמשת במערכת מתנה\n"
	.string "מסתורית.\p"
	.string "ברכות!\p"
	.string "זכית בפרס על ניצחון\n"
	.string "שלושה קרבותs!\p"
	.string "אנו מקווים שתהיה לך השראה\n"
	.string "להמשיך להילחם.$"
