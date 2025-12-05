SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "אהאהאהא!\p"
    .string "איך הצלחת להגיע לכאן בלי\n"
    .string "צוללת?\l"
	.string "איזה ילד{ADD_HEY} מרשי{SWAP_MEM}{ADD_HEY}!\p"
    .string "אבל… זה לא ילך שאת{EMIT_HEY}\n"
    .string "תתערב{ADD_YUD} כאן.\p"
    .string "ואני כן רוצה נקמה על מה שקרה\n"
    .string "במכון מזג האוויר…\p"
    .string "אני הולכת לתת לך טעימה קטנה\n"
    .string "של כאב! השל{ADD_YUD}{SWAP_MEM}{ADD_YUD} עם זה!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "אהאהאהא!\p"
	.string "אאוץ'!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "אהאהאהא!\n"
    .string "את{EMIT_HEY} כל כך חזק{ADD_HEY} לעזאזל.\p"
    .string "זה נורא מאכזב שאת{EMIT_HEY} לא חבר{ADD_HEY}\n"
    .string "בצוות אקווה.\p"
    .string "היית יכול{ADD_HEY} להנות מהעולם הנהדר\n"
    .string "שהבוס שלנו הבטיח\l"
    .string "כמי שמאיתנו…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "כדי שהחלום שלנו יהפוך למציאות,\n"
    .string "אנחנו צריכים את הכוח של הפוקימון.\p"
    .string "אבל מתערבים כמוך משתמשים בכוח\n"
    .string "של הפוקימון כדי להתעסק איתנו\l"
    .string "אפילו במקום כזה!\p"
    .string "החיים פשוט לא עובדים בדרך\n"
    .string "שאנחנו צריכים!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "גוואה!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "אתה יודע, אנחנו לא מעזים להטיל\n"
    .string "ספק במניעים של המנהיג שלנו.\p"
    .string "אבל הנה את{EMIT_HEY}, סתם איזה פרחח{ADD_YUD}{ADD_TAF},\n"
    .string "שיוצא{ADD_TAF} נגד הבוס שלנו.\p"
    .string "אולי...\n"
    .string "את{EMIT_HEY} בטח משהו…$"
