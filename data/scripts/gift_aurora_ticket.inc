MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "תודה שהשתמשת במערכת\n"
	.string "המתנה המסתורית.\p"
	.string "את{EMIT_HEY} חייב{ADD_TAF} להיות {PLAYER}.\n"
	.string "יש כאן כרטיס בשבילך.$"

sText_AuroraTicketUseAtPort:
	.string "נראה שהוא מיועד לשימוש בנמל\n"
	.string "עיר ליליקוב.\p"
	.string "למה שלא תנס{EMIT_HEY}{ADD_YUD} ותרא{EMIT_HEY}{ADD_YUD}\n"
	.string "על מה מדובר?$"

sText_AuroraTicketThankYou:
	.string "תודה שהשתמשת במערכת\n"
	.string "המתנה המסתורית.$"

sText_AuroraTicketBagFull:
	.string "אוי, אני מצטער, {PLAYER}.\n"
	.string "תיק חפצי המפתח שלך מלא.\p"
	.string "אנא אחס{SWAP_NUN}{ADD_YUD} משהו במחשב שלך,\n"
	.string "ואז חז{EMIT_VAV}ר{ADD_YUD} לקחת את זה.$"
