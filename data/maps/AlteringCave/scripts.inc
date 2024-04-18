AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnTransition:
	setflag FLAG_LANDMARK_ALTERING_CAVE
	setflag FLAG_HIDE_GENESECT
	call_if_unset FLAG_CAUGHT_GENESECT, AlteringCave_EventScript_CheckForGVisible
	end

AlteringCave_EventScript_GiveJawFossil::
	giveitem ITEM_SAIL_FOSSIL
	removeobject 2
	setflag FLAG_HIDE_SAIL
	release
	end

AlteringCave_EventScript_CheckForGVisible::
	call_if_set FLAG_SYS_NATIONAL_DEX, AlteringCave_EventScript_GVisible
	return

AlteringCave_EventScript_GVisible::
	clearflag FLAG_HIDE_GENESECT
	return

AlteringCave_EventScript_GenesectBattle::
	lockall
	playmoncry SPECIES_GENESECT, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_GENESECT, 50, ITEM_LINKING_CORD
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, AlteringCave_EventScript_PostGenesectBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AlteringCave_EventScript_PostGenesectBattle
	releaseall
	end

AlteringCave_EventScript_PostGenesectBattle::
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_GENESECT
	setflag FLAG_CAUGHT_GENESECT
	end
