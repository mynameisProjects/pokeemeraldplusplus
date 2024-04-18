EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	setflag FLAG_HIDE_XURKITREE
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	goto_if_set FLAG_MET_HOOPA_ONCE, EverGrandeCity_EventScript_CheckIfCaught
	end

EverGrandeCity_EventScript_CheckIfCaught::
	goto_if_unset FLAG_CAUGHT_XURKITREE, EverGrandeCity_EventScript_ShowPortal
	end

EverGrandeCity_EventScript_ShowPortal::
	clearflag FLAG_HIDE_XURKITREE
	end

EverGrandeCity_EventScript_XurkitreeBattle::
	lockall
	playmoncry SPECIES_XURKITREE, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_XURKITREE, 50, ITEM_MIND_PLATE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, EverGrandeCity_EventScript_PostXurkitreeBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, EverGrandeCity_EventScript_PostXurkitreeBattle
	releaseall
	end

EverGrandeCity_EventScript_PostXurkitreeBattle::
	fadescreen FADE_TO_BLACK
	removeobject 1
	setflag FLAG_HIDE_XURKITREE
	setflag FLAG_CAUGHT_XURKITREE
	fadescreen FADE_FROM_BLACK
	addvar VAR_ALL_HOOPA_PORTALS, 1
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"

