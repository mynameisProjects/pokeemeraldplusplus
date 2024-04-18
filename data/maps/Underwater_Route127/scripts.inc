Underwater_Route127_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route127_OnResume
	.byte 0

Underwater_Route127_OnResume:
	call AbnormalWeather_Underwater_SetupEscapeWarp
	end

Underwater_Route127_EventScript_PhioneFight::
	lockall
	playmoncry SPECIES_PHIONE, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_PHIONE, 35, ITEM_TOXIC_PLATE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Underwater_Route127_EventScript_PostPhioneBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Underwater_Route127_EventScript_PostPhioneBattle
	releaseall
	end

Underwater_Route127_EventScript_PostPhioneBattle::
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_PHIONE
	end

