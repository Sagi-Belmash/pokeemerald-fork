VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "המחשבה שאני מתקרב לליגת הפוקימון…\n"
	.string "אני מקבל פחד במה…$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "לא יכולתי לעשות כלום…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "ליגת הפוקימון שוב התרחקה… איזה אכזבה…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "כדי לנצח בדרכך בליגת הפוקימון,\n"
	.string "את{EMIT_HEY} צרי{SWAP_CHAF}{ADD_HEY} את האמונים\l"
	.string "של הפוקימונים שלך.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "היחסים שלכם מבוססים על אמון מוצק.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "בזכות להיות יחד כל הזמן, אמון גדל\n"
	.string "בין פוקימונים למאמנים.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "זו לא המטרה. זה רק מקום\n"
	.string "בדרך לליגת הפוקימון.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "זה הדרך!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "את{EMIT_HEY} תצליח{ADD_YUD}, בטוח!\n"
	.string "כל הפוקימונים שלך להוטים לצאת לדרך!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "הפוקימונים שלי מעוררי השראה\n"
	.string "במימד הקוסמי!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "מעולם לא פגשתי מישהו כמוך לפניכן.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "אפילו מחוץ לקרב, אני מרגיש\n"
	.string "כוח מדהים שיוצא ממך\l"
	.string "ומהפוקימונים שלך.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "אוקיי, אין צורך להתעצבן!\n"
	.string "תרגע{ADD_YUD}, בוא{ADD_YUD} ניקח את זה בקלות!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "וואה!\n"
	.string "נפלא!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "בטח, זה דרך הניצחון.\p"
	.string "אבל היא לא כל כך שונה\n"
	.string "מהשביל שלקחת עד עכשיו.\p"
	.string "נס{EMIT_HEY}{ADD_YUD} להנות מהדברים בשאר\n"
	.string "הדרך!$"

