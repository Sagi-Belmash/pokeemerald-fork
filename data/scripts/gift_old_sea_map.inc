MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "תודה שהשתמשת במערכת\n"
	.string "המתנה המסתורית.\p"
	.string "רק לוודא--את{EMIT_HEY} {PLAYER}?\p"
	.string "קיבלנו את מפת הים העתיקה הזאת\n"
	.string "שנשלחה אליך.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "נראה שהיא מיועדת לשימוש בנמל\n"
	.string "עיר ליליקוב.\p"
	.string "למה שלא תנס{EMIT_HEY}{ADD_YUD} ותרא{EMIT_HEY}{ADD_YUD}\n"
	.string "על מה מדובר?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "תודה שהשתמשת במערכת\n"
	.string "המתנה המסתורית.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "אוי, אני מצטער, {PLAYER}.\n"
	.string "תיק חפצי המפתח שלך מלא.\p"
	.string "אנא אחס{SWAP_NUN}{ADD_YUD} משהו במחשב שלך,\n"
	.string "ואז חז{EMIT_VAV}ר{ADD_YUD} לקחת את זה.$"
