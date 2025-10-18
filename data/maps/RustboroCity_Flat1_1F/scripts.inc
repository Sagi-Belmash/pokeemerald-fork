RustboroCity_Flat1_1F_MapScripts::
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man::
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman::
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility:
	.string "לכל פוקימון יש יכולת מיוחדת\n"
	.string "שהוא יכול להשתמש בה.$"

RustboroCity_Flat1_1F_Text_PokemonStrange:
	.string "פוקימונים הם יצורים כל כך מוזרים.$"

