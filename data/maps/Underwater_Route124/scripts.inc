Underwater_Route124_MapScripts::
	.byte 0

Underwater_Route124_EventScript_ManaphyFight::
	lockall
	playmoncry SPECIES_MANAPHY, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_MANAPHY, 35, ITEM_NEVER_MELT_ICE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Underwater_Route124_EventScript_PostManaphyBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Underwater_Route124_EventScript_PostManaphyBattle
	releaseall
	end

Underwater_Route124_EventScript_PostManaphyBattle::
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_MANAPHY
	end

