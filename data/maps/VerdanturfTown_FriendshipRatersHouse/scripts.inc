VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_PIKACHU
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "ת{SWAP_NUN}{ADD_YUD} לי לראות את הפוקימון שלך.\n"
	.string "אני אבדוק כמה הוא אוהב אותך.\p"
	.string "או.\n"
	.string "הפוקימון שלך…$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "הוא מעריץ אותך.\n"
	.string "הוא לא יכול לאהוב אותך יותר.\l"
	.string "אני אפילו שמחה לראות את זה.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "נראה שהוא שמח מאוד.\n"
	.string "הוא בבירור מחבב אותך מאוד.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "הוא מחבב אותך די הרבה.\n"
	.string "נראה שהוא רוצה להתפנק קצת.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "הוא מתרגל אליך.\n"
	.string "נראה שהוא מאמין בך.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "הוא עדיין לא התרגל אליך כל כך.\n"
	.string "הוא לא אוהב או שונא אותך.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "הוא מאוד חשדן.\n"
	.string "יש לו רשעות מפחידה בעיניים.\l"
	.string "הוא לא מחבב אותך בכלל.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "קצת קשה לי לומר את זה…\p"
	.string "הפוקימון שלך מתעב אותך.\n"
	.string "האם זה לא גורם לך לחוסר נוחות?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "{STR_VAR_1}: פיקא פיקא!$"

