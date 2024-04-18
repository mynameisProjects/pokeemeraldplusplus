MagmaHideout_3F_4R_MapScripts::
	.byte 0

MagmaHideout_3F_4R_EventScript_YveltalFight::
	lockall
	playmoncry SPECIES_YVELTAL, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_YVELTAL, 50, ITEM_MEADOW_PLATE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MagmaHideout_3F_4R_EventScript_PostYveltalBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MagmaHideout_3F_4R_EventScript_PostYveltalBattle
	releaseall
	end

MagmaHideout_3F_4R_EventScript_PostYveltalBattle::
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_YVELTAL
	end

