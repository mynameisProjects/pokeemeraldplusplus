FieryPath_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
	.byte 0

FieryPath_OnTransition:
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_MoveScottToFallarbor
	setflag FLAG_LANDMARK_FIERY_PATH
	call_if_set FLAG_SYS_NATIONAL_DEX, FieryPath_EventScripts_CheckMoltres
	call_if_unset FLAG_SYS_NATIONAL_DEX, FieryPath_EventScripts_HideMoltres
	end

FieryPath_EventScript_MoveScottToFallarbor::
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	return

FieryPath_EventScripts_CheckMoltres::
	call_if_unset FLAG_CAUGHT_MOLTRES, FieryPath_EventScripts_ShowMoltres
	call_if_set FLAG_CAUGHT_MOLTRES, FieryPath_EventScripts_HideMoltres
	end

FieryPath_EventScripts_ShowMoltres::
	clearflag FLAG_HIDE_MOLTRES
	end

FieryPath_EventScripts_HideMoltres::
	setflag FLAG_HIDE_MOLTRES
	end

FieryPath_EventScript_MoltresFight::
	lockall
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_MOLTRES, 60, ITEM_FLAME_PLATE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, FieryPath_EventScript_PostMoltresBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FieryPath_EventScript_PostMoltresBattle
	releaseall
	end

FieryPath_EventScript_PostMoltresBattle::
	fadescreen FADE_TO_BLACK
	removeobject 9
	fadescreen FADE_FROM_BLACK
	setflag FLAG_CAUGHT_MOLTRES
	end

