FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "תשמע, ילד{ADD_HEY}, את{EMIT_HEY} עובד{ADD_TAF}\n"
	.string "על הפוקידע?\p"
	.string "הממ… ל{SWAP_CHAF}{ADD_YUD} לאזור הספארי.\n"
	.string "זאת ההצעה שלי.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "עשית משהו בפינת\n"
	.string "הרשומות?\p"
	.string "זה ממש מגניב. זה מערבב ומשווה\n"
	.string "את הרשומות של מאמנים.\p"
	.string "אני לא ממש יודע איך זה עובד,\n"
	.string "אבל זה מגניב. אפילו מרגש!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "או, ואו, יש לך פוקידע!\n"
	.string "והוא בדיוק כמו שלי!\p"
	.string "ידעת על מערכת שיחת הקרב\n"
	.string "של הפוקידע?\p"
	.string "אם תיכנס{ADD_YUD} אליה, תוכל{ADD_YUD} לשוחח עם\n"
	.string "מאמנים רשומים בכל עת.\p"
	.string "זה גם מראה אילו מאמנים\n"
	.string "רוצים קרב חוזר איתך.\p"
	.string "זה ממש שימושי! הבחורים של דבון\n"
	.string "באמת יודעים מה הם עושים!$"

