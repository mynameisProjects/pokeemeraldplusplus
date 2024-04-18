AquaHideout_UnusedRubyMap3_MapScripts::
	.byte 0

AquaHideout_UnusedRubyMap3_EventScript_SplicerItem::
	finditem ITEM_DNA_SPLICERS
	end

AquaHideout_UnusedRubyMap3_EventScript_NSolarItem::
	finditem ITEM_N_SOLARIZER
	end

AquaHideout_UnusedRubyMap3_EventScript_NLunarItem::
	finditem ITEM_N_LUNARIZER
	end

AquaHideout_UnusedRubyMap3_EventScript_MewTwoBattle::
	lockall
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	waitmoncry
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 10  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	setwildbattle SPECIES_MEWTWO, 75, ITEM_PSYCHIUM_Z
	special BattleSetup_StartLegendaryBattle
	waitstate
	goto AquaHideout_UnusedRubyMap3_EventScript_PostMewTwoBattle
	releaseall
	end

AquaHideout_UnusedRubyMap3_EventScript_PostMewTwoBattle::
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_MEWTWO
	return

AquaHideout_UnusedRubyMap3_EventScript_Scientist1::
	lock
	faceplayer
	msgbox AquaHideout_UnusedRubyMap3_Text_Scientist1, MSGBOX_NPC
	release
	end

AquaHideout_UnusedRubyMap3_EventScript_Scientist2::
	lock
	faceplayer
	msgbox AquaHideout_UnusedRubyMap3_Text_Scientist2, MSGBOX_NPC
	release
	end

AquaHideout_UnusedRubyMap3_EventScript_Scientist3::
	lock
	msgbox AquaHideout_UnusedRubyMap3_Text_Scientist3, MSGBOX_DEFAULT
	release
	end

AquaHideout_UnusedRubyMap3_Text_Scientist1:
	.string "Plug this in here and that there...$"

AquaHideout_UnusedRubyMap3_Text_Scientist2:
	.string "Those grunts outside are forcing us\n"
	.string "to make this awful abomination...$"

AquaHideout_UnusedRubyMap3_Text_Scientist3:
	.string "They seem to busy to notice you.$"
