ScorchedSlab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_OnTransition
	.byte 0

ScorchedSlab_OnTransition:
	setflag FLAG_LANDMARK_SCORCHED_SLAB
	setflag FLAG_HIDE_ZERAORA
	call_if_unset FLAG_CAUGHT_ZERAORA, ScorchedSlab_EventScript_CheckNat
	end

ScorchedSlab_EventScript_CheckNat::
	call_if_set FLAG_SYS_NATIONAL_DEX, ScorchedSlab_EventScript_ShowZeraora
	end

ScorchedSlab_EventScript_ShowZeraora::
	clearflag FLAG_HIDE_ZERAORA
	end

ScorchedSlab_EventScript_ZeraoraFight::
	lockall
	playmoncry SPECIES_ZERAORA, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_ZERAORA, 45, ITEM_MAGNET
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, ScorchedSlab_EventScript_PostZeraoraBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ScorchedSlab_EventScript_PostZeraoraBattle
	releaseall
	end

ScorchedSlab_EventScript_PostZeraoraBattle::
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_ZERAORA
	setflag FLAG_CAUGHT_ZERAORA
	end
