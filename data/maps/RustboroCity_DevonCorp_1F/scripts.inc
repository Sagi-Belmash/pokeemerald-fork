RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "שלום וברו{SWAP_CHAF}{ADD_HEY} הבא{ADD_HEY} לחברת\n"
	.string "דבון.\p"
	.string "אנחנו גאים לייצר מוצרים ותרופות\n"
	.string "שמשפרים את איכות החיים שלכם.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "אחד מחוקרי החברה שלנו בטיפשות\n"
	.string "נשדד ונלקחה ממנו חבילה חשובה.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "היי, הנעלה ריצה האלה!\n"
	.string "אלה אחד המוצרים שלנו!\p"
	.string "זה משמח אותי לראות מישהו\n"
	.string "שמשתמש במשהו שאנחנו ייצרנו.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "החבילה הגנובה ההיא…\p"
	.string "נו, היא אמנם חשובה, אבל זה לא משהו\n"
	.string "שמישהו באמת יכול להשתמש בו.\p"
	.string "לדעתי, הגנב הזה לא היה כל כך חכם.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "נשמע שהצליחו להחזיר את\n"
	.string "הסחורה הגנובה של דבון.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "מצטער, רק אנשים מורשים יכולים\n"
	.string "להיכנס לכאן.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "זה פשוט מטופש.\n"
	.string "איך בכלל הצליחו לשדוד אותנו?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "היי שם!\n"
	.string "את{EMIT_HEY} תמיד תהי{EMIT_HEY}{ADD_YUD} רצוי{ADD_HEY} כאן!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "דגימות של סלעים ומתכות מוצגות\n"
	.string "בתוך תיבת זכוכית.\p"
	.string "יש לוח עם כיתוב עליו…\p"
	.string "”תאגיד דבון התחילה את דרכה כיצרנית\n"
	.string "אבנים ממחצבות.\p"
	.string "”החברה גם ייצרה ברזל משיירי חול.\n"
	.string "”מההתחלה הצנועה הזו כיצרנית חומרי גלם,\n"
	.string "דבון התפתחה.\p"
	.string "”דבון כיום היא יצרנית של מגוון רחב\n"
	.string "של מוצרים תעשייתיים.“$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "אב־טיפוס ומוצרים ניסיוניים ממלאים\n"
	.string "את תיבת התצוגה מזכוכית.\p"
	.string "יש לוח עם תיאור עליו…\p"
	.string "”בנוסף למוצרים תעשייתיים,\n"
	.string "דבון גם משווקת תרופות ומוצרים שונים\l"
	.string "לאיכות חיים טובה יותר.\p"
	.string "”לאחרונה, דבון החלה לשווק כלים\n"
	.string "למאמני פוקימון, הכוללים\l"
	.string "פוכדורים ומערכות הפוקינווט.”$"

