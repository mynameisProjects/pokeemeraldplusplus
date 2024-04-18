Route119_HiddenForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_HiddenForest_OnTransition
	.byte 0

Route119_HiddenForest_OnTransition::
	setflag FLAG_HIDE_MARSHADOW
	call_if_set FLAG_HIDE_XERNEAS, Route119_HiddenForest_EventScript_CheckMarsh
	end

Route119_HiddenForest_EventScript_CheckMarsh::
	call_if_unset FLAG_CAUGHT_MARSHADOW, Route119_HiddenForest_EventScript_CheckNat
	end

Route119_HiddenForest_EventScript_CheckNat::
	call_if_set FLAG_SYS_NATIONAL_DEX, Route119_HiddenForest_EventScript_ShowMarsh
	end

Route119_HiddenForest_EventScript_ShowMarsh::
	clearflag FLAG_HIDE_MARSHADOW
	end

Route119_HiddenForest_EventScript_MarshadowFight::
	lockall
	playmoncry SPECIES_MARSHADOW, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_MARSHADOW, 50, ITEM_MARSHADIUM_Z
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Route119_HiddenForest_EventScript_PostMarshadowBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route119_HiddenForest_EventScript_PostMarshadowBattle
	releaseall
	end

Route119_HiddenForest_EventScript_PostMarshadowBattle::
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_MARSHADOW
	setflag FLAG_CAUGHT_MARSHADOW
	end

Route119_HiddenForest_EventScripts_WarpBack1::
	warp MAP_ROUTE119, 3
	end

Route119_HiddenForest_EventScripts_WarpBack2::
	warp MAP_ROUTE119, 3
	end

Route119_HiddenForest_EventScript_XerneasFight::
	lockall
	playmoncry SPECIES_XERNEAS, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_XERNEAS, 50, ITEM_GRASS_GEM
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Route119_HiddenForest_EventScript_PostXerneasBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route119_HiddenForest_EventScript_PostXerneasBattle
	releaseall
	end

Route119_HiddenForest_EventScript_PostXerneasBattle::
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_XERNEAS
	end
