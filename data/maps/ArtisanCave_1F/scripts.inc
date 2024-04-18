ArtisanCave_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ArtisanCave_1F_OnTransition
	.byte 0

ArtisanCave_1F_OnTransition:
	setflag FLAG_HIDE_ZEKROM
	setflag FLAG_HIDE_RESHIRAM
	call_if_unset FLAG_CAUGHT_ZEKROM, ArtisanCave_1F_EventScript_CheckForZVisible
	call_if_unset FLAG_CAUGHT_RESHIRAM, ArtisanCave_1F_EventScript_CheckForRVisible
	end

ArtisanCave_1F_EventScript_CheckForZVisible::
	call_if_set FLAG_SYS_NATIONAL_DEX, ArtisanCave_1F_EventScript_ZVisible
	return

ArtisanCave_1F_EventScript_CheckForRVisible::
	call_if_set FLAG_SYS_NATIONAL_DEX, ArtisanCave_1F_EventScript_RVisible
	return

ArtisanCave_1F_EventScript_ZVisible::
	clearflag FLAG_HIDE_ZEKROM
	return

ArtisanCave_1F_EventScript_RVisible::
	clearflag FLAG_HIDE_RESHIRAM
	return

ArtisanCave_1F_EventScript_CheckIfBothDefeated::
	goto_if_unset FLAG_CAUGHT_ZEKROM, ArtisanCave_1F_EventScript_Ret
	goto_if_unset FLAG_CAUGHT_RESHIRAM, ArtisanCave_1F_EventScript_Ret
	setflag FLAG_BW_DEFEATED
	end

ArtisanCave_1F_EventScript_Ret::
	end

ArtisanCave_1F_EventScript_ZekromBattle::
	lockall
	playmoncry SPECIES_ZEKROM, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_ZEKROM, 60, ITEM_BLACK_FLUTE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, ArtisanCave_1F_EventScript_PostZekromBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArtisanCave_1F_EventScript_PostZekromBattle
	releaseall
	end

ArtisanCave_1F_EventScript_PostZekromBattle::
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_ZEKROM
	setflag FLAG_CAUGHT_ZEKROM
	goto ArtisanCave_1F_EventScript_CheckIfBothDefeated
	end

ArtisanCave_1F_EventScript_ReshiramBattle::
	lockall
	playmoncry SPECIES_RESHIRAM, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_RESHIRAM, 60, ITEM_WHITE_FLUTE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, ArtisanCave_1F_EventScript_PostReshiramBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArtisanCave_1F_EventScript_PostReshiramBattle
	releaseall
	end

ArtisanCave_1F_EventScript_PostReshiramBattle::
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_RESHIRAM
	setflag FLAG_CAUGHT_RESHIRAM
	goto ArtisanCave_1F_EventScript_CheckIfBothDefeated
	end
