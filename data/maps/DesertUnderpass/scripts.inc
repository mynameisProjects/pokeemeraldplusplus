.set LOCALID_FOSSIL, 1

DesertUnderpass_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
	.byte 0

DesertUnderpass_OnTransition:
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
	setflag FLAG_HIDE_MELTAN
	call_if_unset FLAG_CAUGHT_MELTAN, DesertUnderpass_EventScript_CheckNat
	end

DesertUnderpass_EventScript_CheckNat::
	call_if_set FLAG_SYS_NATIONAL_DEX, DesertUnderpass_EventScript_ShowMeltan
	end

DesertUnderpass_EventScript_ShowMeltan::
	clearflag FLAG_HIDE_MELTAN
	end

DesertUnderpass_EventScript_MeltanFight::
	lockall
	playmoncry SPECIES_MELTAN, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_MELTAN, 5, ITEM_IRON_PLATE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, DesertUnderpass_EventScript_PostMeltanBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DesertUnderpass_EventScript_PostMeltanBattle
	releaseall
	end

DesertUnderpass_EventScript_PostMeltanBattle::
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_MELTAN
	setflag FLAG_CAUGHT_MELTAN
	end

DesertUnderpass_EventScript_Fossil::
	lock
	faceplayer
	goto_if_set FLAG_CHOSE_ROOT_FOSSIL, DesertUnderpass_EventScript_GiveClawFossil
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, DesertUnderpass_EventScript_GiveRootFossil
	release
	end

DesertUnderpass_EventScript_GiveClawFossil::
	giveitem ITEM_CLAW_FOSSIL
	removeobject LOCALID_FOSSIL
	release
	end

DesertUnderpass_EventScript_GiveRootFossil::
	giveitem ITEM_ROOT_FOSSIL
	removeobject LOCALID_FOSSIL
	release
	end

@ Unused
DesertUnderpass_Text_FoundRootFossil::
	.string "{PLAYER} found the ROOT FOSSIL.$"

@ Unused
DesertUnderpass_Text_FoundClawFossil::
	.string "{PLAYER} found the CLAW FOSSIL.$"

