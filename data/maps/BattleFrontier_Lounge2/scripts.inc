BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "אהלן! כשזה מגיע לחדשות על\n"
	.string "חזית הקרב, אני מס' 1.\p"
	.string "את{EMIT_HEY} יכול{ADD_HEY}לחשוב עליי בתור\n"
	.string "משוגע על חזית הקרב.\p"
	.string "רק לוודא, אבל את{EMIT_HEY} מאמ{SWAP_NUN}{ADD_TAF}, נכון?\n"
	.string "אני אשמח לחלוק את החדשות החמות ביותר\l"
	.string "שאספתי על חזית הקרב.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "היי! עצרת כאן כדי לחקור אותי\n"
	.string "על המילה האחרונה? או, בסדר גמור!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "נו? נו? נו?\p"
	.string "אני בטוח שהמידע שלי היה\n"
	.string "שימושי מאוד לך, נכון?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "בוא{ADD_YUD} נראה עכשיו…\p"
	.string "נשמע שהמתקן {STR_VAR_1}\n"
	.string "הוא המקום הכי חם עכשיו.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "בוא{ADD_YUD} נראה עכשיו…\p"
	.string "נשמע שמגדל הקרב\n"
	.string "{STR_VAR_1} הוא הכי חם.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "אני בטוח שלא ידעת את זה!\p"
	.string "אחד מהמאמנים הבכירים האלה שסקוט\n"
	.string "קורא להם ראשי החזית נמצאת שם.\p"
	.string "זו מאמנת מסתורית הנקראת\n"
	.string "עלמת הסלון שמנהלת את המקום.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "האם נלחמת בעלמת הסלון?\p"
	.string "כשהיא מעריכה את היריב שלה,\n"
	.string "היא ככל הנראה משתמשת בפוקימונים הבאים:\p"
	.string "פוקימון חוש מסוג על חושי,\n"
	.string "פוקימון הר געש מסוג אש,\l"
	.string "ופוקימון ישן מסוג רגיל.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "האם נלחמת בעלמת הסלון\n"
	.string "כשהיא רצינית?\p"
	.string "כשהיא נלחמת בכל הכוח,\n"
	.string "היא ככל הנראה משתמשת בפוקימונים הבאים:\p"
	.string "פוקימון עדן דרקון ועל חושי,\n"
	.string "פוקימון רעם מסוג חשמל,\l"
	.string "ופוקימון ישן מסוג רגיל.$"

@ TILL HERE 2

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "אני בטוח שלא ידעת את זה!\p"
	.string "אחד מהמאמנים הבכירים האלה שסקוט\n"
	.string "קורא להם ראשי החזית נמצא שם.\p"
	.string "זהו מאמן ראוותני הנקרא\n"
	.string "אס הכיפה שמנהל את המקום.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "האם נלחמת באס הכיפה?\p"
	.string "כשהוא מקל ראש ביריב,\n"
	.string "הוא משתמש בשלושת הפוקימונים האלה:\p"
	.string "פוקימון דרקון מעופף,\n"
	.string "פוקימון דג בוץ מים ואדמה,\l"
	.string "ופוקימון להבה אש ומעופף.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "האם נלחמת באס הכיפה\n"
	.string "כשהוא רציני?\p"
	.string "כשהוא מדגים את האסטרטגיה שלו,\n"
	.string "הוא משתמש בשלושת הפוקימונים האלה:\p"
	.string "פוקימון עדן דרקון ומעופף,\n"
	.string "פוקימון דג בוץ מים ואדמה,\l"
	.string "ופוקימון רגל ברזל מסוג פלדה ועל חושי.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "אני בטוח שלא ידעת את זה!\p"
	.string "אחד מהמאמנים הבכירים האלה שסקוט\n"
	.string "קורא להם ראשי החזית נמצא שם.\p"
	.string "זהו מאמן מוזר הנקרא\n"
	.string "ראש המפעל שמנהל את המקום.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "האם נלחמת בראש המפעל\n"
	.string "כבר?\p"
	.string "ת{SWAP_NUN}{ADD_YUD} לי לחשוב… כשהוא יוצא לקרב,\n"
	.string "הוא פשוט מקבל שלושה פוקימונים שכורים.\p"
	.string "הוא נלחם בערך באותם תנאים כמוך.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "האם נלחמת בראש המפעל\n"
	.string "כשהוא רציני?\p"
	.string "כשהוא יוצא לקרב ברצינות,\n"
	.string "הוא עדיין מקבל שלושה פוקימונים שכורים.\p"
	.string "הוא נלחם תחת אותם תנאים כמוך.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "אני בטוח שלא ידעת את זה!\p"
	.string "אחד מהמאמנים הבכירים האלה שסקוט\n"
	.string "קורא להם ראשי החזית נמצאת שם.\p"
	.string "זו מאמנת מפחידה הנקראת\n"
	.string "מלכת הנהר שמנהלת את המקום.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "האם נלחמת במלכת הנהר\n"
	.string "לפניכן?\p"
	.string "כשהיא במצב רוח טוב, אומרים\n"
	.string "שהיא משתמשת בשלושת הפוקימונים האלה:\p"
	.string "פוקימון נחש ניב מסוג רעל,\n"
	.string "פוקימון יציקה חרק ואבן,\l"
	.string "ופוקימון עדין מסוג מים.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "האם נלחמת במלכת הנהר\n"
	.string "כשהיא רצינית?\p"
	.string "כשהיא עצבנית ברצינות, אומרים\n"
	.string "שהיא משתמשת בשלושת הפוקימונים האלה:\p"
	.string "פוקימון נחש ניב מסוג רעל,\n"
	.string "פוקימון נחש ברזל פלדה ואדמה,\l"
	.string "ופוקימון אכזרי מסוג מים ומעופף.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "אני בטוח שלא ידעת את זה!\p"
	.string "אחד מהמאמנים הבכירים האלה שסקוט\n"
	.string "קורא להם ראשי החזית נמצאת שם.\p"
	.string "זו מאמנת חמודה הנקראת\n"
	.string "שליטת הזירה שמנהלת את המקום.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "האם נלחמת בשליטת הזירה\n"
	.string "לפניכן?\p"
	.string "כשהיא מעריכה את היכולת של היריב,\n"
	.string "היא משתמשת לכאורה בפוקימונים הבאים:\p"
	.string "פוקימון קרן יחידה חרק ולחימה,\n"
	.string "פוקימון אור ירח מסוג אופל,\l"
	.string "ופוקימון השלה חרק ורוח.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "האם נלחמת בשליטת הזירה\n"
	.string "כשהיא רצינית?\p"
	.string "כשהיא נלחמת על אמת,\n"
	.string "היא משתמשת לכאורה בפוקימונים הבאים:\p"
	.string "פוקימון אור ירח מטיפוס אפל,\n"
	.string "פוקימון צל רוח ורעל\l"
	.string "ופוקימון פטרייה מסוג עשב ולחימה.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "אני בטוח שלא ידעת את זה!\p"
	.string "אחד מהמאמנים הבכירים האלה שסקוט\n"
	.string "קורא להם ראשי החזית נמצא שם.\p"
	.string "זהו מאמן זדוני הנקרא\n"
	.string "אדון הארמון שמנהל את המקום.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "האם נלחמת במכובד הארמון\n"
	.string "לפניכן?\p"
	.string "כשהוא בודק את רוח הלחימה של היריב,\n"
	.string "אומרים שהוא משתמש בפוקימונים הבאים:\p"
	.string "פוקימון עטלף מסוג רעל ומעופף,\n"
	.string "פוקימון עצלן מסוג רגיל, ופוקימון\l"
	.string "הובלה מסוג מים וקרח.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "האם נלחמת באדון הארמון\n"
	.string "כשהוא רציני?\p"
	.string "כשהוא משליך את כל כוחו אל הקרב,\n"
	.string "אומרים שהוא משתמש בפוקימונים הבאים:\p"
	.string "פוקימון אגדי מסוג אש,\n"
	.string "פוקימון עצלן מסוג רגיל,\l"
	.string "ופוקימון זוהר הקוטב מסוג מים.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "אני בטוח שלא ידעת את זה!\p"
	.string "אחד מהמאמנים הבכירים האלה שסקוט\n"
	.string "קורא להם ראשי החזית נמצא שם.\p"
	.string "זהו מאמן לוהט הנקרא\n"
	.string "מלך הפירמידה שמנהל את המקום.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "האם נלחמת במלך הפירמידה\n"
	.string "לפניכן?\p"
	.string "כשהוא בודק את כוח היריב,\n"
	.string "הוא ככל הנראה משתמש בפוקימונים הבאים:\p"
	.string "פוקימון פסגת אבן מסוג אבן,\n"
	.string "פוקימון קרחון מסוג קרח,\l"
	.string "ופוקימון ברזל מסוג פלדה.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "האם נלחמת במלך הפירמידה\n"
	.string "כשהוא רציני?\p"
	.string "כשהוא מלא בכוח לוהט,\n"
	.string "הוא ככל הנראה משתמש בפוקימונים הבאים:\p"
	.string "פוקימון הקפאה קרח ומעופף, פוקימון\n"
	.string "חשמלי חשמל ומעופף,\l"
	.string "ופוקימון להבה מסוג אש ומעופף.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "בטח, יש כמה מקומות שבהם\n"
	.string "את{EMIT_HEY} יכול{ADD_HEY}להיכנס לקרבות זוגות.\p"
	.string "אבל חדרי קרבות הזוגות של\n"
	.string "מגדל הקרב הם, כביכול, בסיסיים!\p"
	.string "הם המקום שבו את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} ללמוד על\n"
	.string "איך משחקים קרבות זוגות כאן\l"
	.string "בחזית הקרב.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "היזהר{ADD_YUD} בקרבות כאן.\p"
	.string "אני שומע שיש מאמנים שיש להם\n"
	.string "אסטרטגיות שהם פיתחו במיוחד\l"
	.string "לקרבות זוגות.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "ברגע שאת{EMIT_HEY} בטוח{ADD_HEY} ונוח{ADD_HEY}\n"
	.string "בקרבות זוגות כאן, את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY}\l"
	.string "לחשוב על אתגור מקומות אחרים\l"
	.string "שמציעים קרבות זוגות.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "כל מיני מאמנים מתאספים\n"
	.string "בסלון הקרב.\p"
	.string "רק תחש{EMIT_VAV}ב{ADD_YUD}--את{EMIT_HEY} עשוי{ADD_HEY} להיתקל\n"
	.string "בחברים או עוקבים שלך!\l"
	.string "כדאי לך להסתכל היטב!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "אם את{EMIT_HEY} עם חבר, ל{SWAP_CHAF}{ADD_YUD} לחדר\n"
	.string "קרב רב משתתפי קשר.\p"
	.string "אם את{EMIT_HEY} משחק{ADD_TAF} עם חבר חזק,\n"
	.string "את{EMIT_HEY} יכול{ADD_HEY}לצפות לראות יריבים קשוחים!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "איזה כוח איסוף חדשות מדהים!\n"
	.string "המנטור שלי הוא כמו אף אחד אחר!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "איזה כוח התבוננות מדהים!\n"
	.string "המנטור שלי הוא כמו אף אחד אחר!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "איזה כוח שכנוע מדהים!\n"
	.string "המנטור שלי הוא כמו אף אחד אחר!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "…מה זה המקום הזה?\n"
	.string "זה מפחיד אותי…$"

