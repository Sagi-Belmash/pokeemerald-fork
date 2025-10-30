VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	bufferspeciesname STR_VAR_1, SPECIES_RALTS
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "וואלי: הפסדתי לך, {PLAYER}, אבל אני\n"
	.string "לא מרגיש מדוכא יותר.\p"
	.string "כי יש לי מטרה חדשה בחיים.\n"
	.string "ביחד עם ה{STR_VAR_1} שלי, אני הולך\l"
	.string "לאתגר את מכוני הפוקימון ולהפוך\l"
	.string "למאמן נהדר.\p"
	.string "תחכ{EMIT_HEY}{ADD_YUD} לזה, {PLAYER}.\n"
	.string "אני הולך להיות חזק יותר ממך.\p"
	.string "כשאהיה, אני אאתגר אותך\n"
	.string "לקרב נוסף.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "וואלי: תחכ{EMIT_HEY}{ADD_YUD} לזה, {PLAYER}.\n"
	.string "אני הולך להיות חזק יותר ממך.\p"
	.string "כשאהיה, אני אאתגר אותך\n"
	.string "לקרב נוסף.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "דוד: או! {PLAYER}{KUN}!\n"
	.string "וואלי בבית הסמוך.\p"
	.string "אבל, תשמע{ADD_YUD}, יש משהו שאני צריך\n"
	.string "לספר לך.\p"
	.string "הסביבה הטבעית הזו עושה\n"
	.string "פלאים לבריאות של וואלי.\p"
	.string "אולי זו לא רק הסביבה.\n"
	.string "יכול להיות שזה הפוקימון שנותנים\l"
	.string "תקווה לילד.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "וואלי הלך לו…\n"
	.string "הוא יצא לבדו…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "דוד: זה נכון?\n"
	.string "וואלי הלך כל כך רחוק לגמרי\l"
	.string "לבדו…\p"
	.string "ובכן, אני חייב לתת לו קרדיט--הוא\n"
	.string "הבן של אחי הקטן.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "וונדה: ואת{EMIT_HEY}?\n"
	.string "או, נכון, אני מבינה!\p"
	.string "את{EMIT_HEY} {PLAYER} שואלי\n"
	.string "סיפר לי עלי{EMIT_VAV}{ADD_HEY}.\p"
	.string "אני דודה של וואלי.\n"
	.string "שמחה לפגוש אותך!\p"
	.string "אני חושבת שוואלי נהיה הרבה יותר נמרץ\n"
	.string "ובריא מאז שהוא הגיע לכאן.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "וונדה: אל תדאג{ADD_YUD} לגבי וואלי.\n"
	.string "הוא יהיה בסדר גמור.\p"
	.string "אני מכירה את הבן דוד הקטן שלי, ויש\n"
	.string "איתו גם פוקימון.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "בזכותך, אני יכול לראות את החברה\n"
	.string "שלי כל יום.\l"
	.string "שמח? בטח!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "החבר של הבת שלי הוא בחור עם\n"
	.string "הרבה מוטיבציה והתלהבות.\p"
	.string "הוא חופר מנהרה בלי הפסקה\n"
	.string "רק כדי שיוכל לראות את הבת שלי.\p"
	.string "הבת שלי קצת מודאגת,\n"
	.string "אז היא הולכת למנהרה הרבה.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "זה מדהים. החבר של הבת שלי\n"
	.string "חפר את המנהרה בידיו!\p"
	.string "זה כל כך לא ייאמן!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "אם משהו יקרה לוואלי,\n"
	.string "אני לעולם לא אוכל להביט בעיניים\l"
	.string "להורים שלו שבפטלבורג…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "וואלי היה באבר גרנדה?\p"
	.string "ההורים שלו בפטלבורג\n"
	.string "ידהמו מלשמוע את זה!$"

