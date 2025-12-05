MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "תודה שהשתמשת במערכת\n"
	.string "המתנה המסתורית.\p"
	.string "את{EMIT_HEY} חייב{ADD_TAF} להיות {PLAYER}.\n"
	.string "יש כאן כרטיס בשבילך.$"

sText_MysticTicketUseAtPort:
	.string "נראה שהוא מיועד לשימוש בנמל\n"
	.string "עיר ליליקוב.\p"
	.string "למה שלא תנס{EMIT_HEY}{ADD_YUD} ותרא{EMIT_HEY}{ADD_YUD}\n"
	.string "על מה מדובר?$"

sText_MysticTicketThankYou:
	.string "תודה שהשתמשת במערכת\n"
	.string "המתנה המסתורית.$"

sText_MysticTicketBagFull:
	.string "אוי, אני מצטער, {PLAYER}.\n"
	.string "תיק חפצי המפתח שלך מלא.\p"
	.string "אנא אחס{SWAP_NUN}{ADD_YUD} משהו במחשב שלך,\n"
	.string "ואז חז{EMIT_VAV}ר{ADD_YUD} לקחת את זה.$"
