LilycoveCity_House1_MapScripts::
	.byte 0

LilycoveCity_House1_EventScript_ExpertM::
	msgbox LilycoveCity_House1_Text_PokemonPartnersNotTools, MSGBOX_NPC
	end

LilycoveCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_KECLEON
	msgbox LilycoveCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_House1_Text_PokemonPartnersNotTools:
    .string "פוקימונים הם שותפים של אנשים.\n"
    .string "הם לא הכלים שלנו.\p"
    .string "למרבה הצער, יש אנשים שלא\n"
    .string "מבינים זאת…$"

LilycoveCity_House1_Text_Kecleon:
	.string "{STR_VAR_1}: רורורו?$"

