BattleFrontier_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FRONTIER_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_SKITTY
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon:
	.string "היה כאן מישהו שהשתמש בפוקימון\n"
	.string "שמעולם לא ראיתי.\p"
	.string "אף פעם לא למדתי עליו בבית הספר\n"
	.string "למאמנים לפחות.\p"
	.string "אני תוהה איפה אפשר לתפוס פוקימונים\n"
	.string "כאלה.$"

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
	.string "אוקיי! עצירה הבאה, זירת הקרב!\n"
	.string "כדאי שאקח את הפוקימון הנכון\l"
	.string "ממערכת האחסון במחשב.$"

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
	.string "צחקוק… אני הולכת לעבור כל אתגר\n"
	.string "רק עם התינוק הזה!$"

BattleFrontier_PokemonCenter_1F_Text_Skitty:
	.string "{STR_VAR_1}: מיא מיאאאה!$"

