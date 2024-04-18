AquaHideout_UnusedRubyMap1_MapScripts::
	.byte 0

AquaHideout_UnusedRubyMap1_EventScript_MewTwoStoneOne::
	finditem ITEM_MEWTWONITE_X
	end

AquaHideout_UnusedRubyMap1_EventScript_MewTwoStoneTwo::
	finditem ITEM_MEWTWONITE_Y
	end

AquaHideout_UnusedRubyMap1_EventScript_MAG1::
	trainerbattle_single TRAINER_MAG1_MEWTWO, AquaHideout_UnusedRubyMap1_Text_MAG1Intro, AquaHideout_UnusedRubyMap1_Text_MAG1Defeat
	msgbox AquaHideout_UnusedRubyMap1_Text_MAG1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_UnusedRubyMap1_EventScript_FMG1::
	trainerbattle_single TRAINER_FMG1_MEWTWO, AquaHideout_UnusedRubyMap1_Text_FMG1Intro, AquaHideout_UnusedRubyMap1_Text_FMG1Defeat
	msgbox AquaHideout_UnusedRubyMap1_Text_FMG1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_UnusedRubyMap1_EventScript_MMG1::
	trainerbattle_single TRAINER_MMG1_MEWTWO, AquaHideout_UnusedRubyMap1_Text_MMG1Intro, AquaHideout_UnusedRubyMap1_Text_MMG1Defeat
	msgbox AquaHideout_UnusedRubyMap1_Text_MMG1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_UnusedRubyMap1_EventScript_FAG1::
	trainerbattle_single TRAINER_FAG1_MEWTWO, AquaHideout_UnusedRubyMap1_Text_FAG1Intro, AquaHideout_UnusedRubyMap1_Text_FAG1Defeat
	msgbox AquaHideout_UnusedRubyMap1_Text_FAG1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_UnusedRubyMap1_Text_MAG1Intro:
	.string "Hey kid, this place is off limits!$"

AquaHideout_UnusedRubyMap1_Text_MAG1Defeat:
	.string "You're nothing!$"

AquaHideout_UnusedRubyMap1_Text_MAG1PostBattle:
	.string "The others will put you in your place.$"

AquaHideout_UnusedRubyMap1_Text_FMG1Intro:
	.string "We got wise and ditched our teams to\n"
	.string "make a new team!$"

AquaHideout_UnusedRubyMap1_Text_FMG1Defeat:
	.string "I can't believe it.$"

AquaHideout_UnusedRubyMap1_Text_FMG1PostBattle:
	.string "You won't stop our plans.$"

AquaHideout_UnusedRubyMap1_Text_MMG1Intro:
	.string "The boss is up to some weird stuff with\n"
	.string "some kinda lab POKéMON.$"

AquaHideout_UnusedRubyMap1_Text_MMG1Defeat:
	.string "I didn't sign up for this!$"

AquaHideout_UnusedRubyMap1_Text_MMG1PostBattle:
	.string "I don't get paid enough to deal with\n"
	.string "brats like you.$"

AquaHideout_UnusedRubyMap1_Text_FAG1Intro:
	.string "Stop trying! You can't stop us!$"

AquaHideout_UnusedRubyMap1_Text_FAG1Defeat:
	.string "Okay.. maybe you can.$"

AquaHideout_UnusedRubyMap1_Text_FAG1PostBattle:
	.string "Just wait till the boss hears about this...$"
