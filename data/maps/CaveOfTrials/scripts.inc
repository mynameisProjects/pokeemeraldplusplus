.set LOCALID_KOKO, 1
.set LOCALID_BULU, 2
.set LOCALID_FINI, 3
.set LOCALID_LELE, 4

CaveOfTrials_MapScripts::
	.byte 0

CaveOfTrials_EventScript_CheckIfWorthy::
	@call CaveOfTrials_EventScript_CheckIfComplete
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	goto_if_set FLAG_SYS_NATIONAL_DEX, CaveOfTrials_EventScript_Worthy
	goto_if_unset FLAG_SYS_NATIONAL_DEX, CaveOfTrials_EventScript_Unworthy
	end

CaveOfTrials_EventScript_Worthy::
	lock
	call_if_unset FLAG_HIDE_KOKO, CaveOfTrials_EventScript_KokoApproach
	call_if_unset FLAG_HIDE_BULU, CaveOfTrials_EventScript_BuluApproach
	call_if_unset FLAG_HIDE_FINI, CaveOfTrials_EventScript_FiniApproach
	call_if_unset FLAG_HIDE_LELE, CaveOfTrials_EventScript_LeleApproach
	call_if_unset FLAG_HIDE_KOKO, CaveOfTrials_EventScript_KokoBattle
	call_if_unset FLAG_HIDE_BULU, CaveOfTrials_EventScript_BuluBattle
	call_if_unset FLAG_HIDE_FINI, CaveOfTrials_EventScript_FiniBattle
	call_if_unset FLAG_HIDE_LELE, CaveOfTrials_EventScript_LeleBattle
	release
	end

CaveOfTrials_EventScript_KokoApproach::
	applymovement LOCALID_KOKO, CaveOfTrials_Movement_Koko
	waitmovement LOCALID_KOKO
	playmoncry SPECIES_TAPU_KOKO, CRY_MODE_ENCOUNTER
	waitmoncry
	return

CaveOfTrials_EventScript_BuluApproach::
	applymovement LOCALID_BULU, CaveOfTrials_Movement_Bulu
	waitmovement LOCALID_BULU
	turnobject LOCALID_BULU, DIR_SOUTH
	playmoncry SPECIES_TAPU_BULU, CRY_MODE_ENCOUNTER
	waitmoncry
	return

CaveOfTrials_EventScript_FiniApproach::
	applymovement LOCALID_FINI, CaveOfTrials_Movement_Fini
	waitmovement LOCALID_FINI
	turnobject LOCALID_FINI, DIR_SOUTH
	playmoncry SPECIES_TAPU_FINI, CRY_MODE_ENCOUNTER
	waitmoncry
	return

CaveOfTrials_EventScript_LeleApproach::
	applymovement LOCALID_LELE, CaveOfTrials_Movement_Lele
	waitmovement LOCALID_LELE
	playmoncry SPECIES_TAPU_LELE, CRY_MODE_ENCOUNTER
	waitmoncry
	return

CaveOfTrials_EventScript_KokoBattle::
	setwildbattle SPECIES_TAPU_KOKO, 50, ITEM_FIST_PLATE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CaveOfTrials_EventScript_PostKokoBattleRan
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, CaveOfTrials_EventScript_PostKokoBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CaveOfTrials_EventScript_PostKokoBattle
	return

CaveOfTrials_EventScript_PostKokoBattle::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_KOKO
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_KOKO
	return

CaveOfTrials_EventScript_PostKokoBattleRan::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_KOKO
	fadescreen FADE_FROM_BLACK
	return

CaveOfTrials_EventScript_BuluBattle::
	setwildbattle SPECIES_TAPU_BULU, 50, ITEM_ZAP_PLATE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CaveOfTrials_EventScript_PostBuluBattleRan
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, CaveOfTrials_EventScript_PostBuluBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CaveOfTrials_EventScript_PostBuluBattle
	return

CaveOfTrials_EventScript_PostBuluBattle::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_BULU
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_BULU
	return

CaveOfTrials_EventScript_PostBuluBattleRan::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_BULU
	fadescreen FADE_FROM_BLACK
	return

CaveOfTrials_EventScript_FiniBattle::
	setwildbattle SPECIES_TAPU_FINI, 50, ITEM_SPLASH_PLATE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CaveOfTrials_EventScript_PostFiniBattleRan
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, CaveOfTrials_EventScript_PostFiniBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CaveOfTrials_EventScript_PostFiniBattle
	return

CaveOfTrials_EventScript_PostFiniBattle::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_FINI
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_FINI
	return

CaveOfTrials_EventScript_PostFiniBattleRan::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_FINI
	fadescreen FADE_FROM_BLACK
	return

CaveOfTrials_EventScript_LeleBattle::
	setwildbattle SPECIES_TAPU_LELE, 50, ITEM_PIXIE_PLATE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CaveOfTrials_EventScript_PostLeleBattleRan
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, CaveOfTrials_EventScript_PostLeleBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CaveOfTrials_EventScript_PostLeleBattle
	return

CaveOfTrials_EventScript_PostLeleBattle::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_LELE
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_LELE
	return

CaveOfTrials_EventScript_PostLeleBattleRan::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_LELE
	fadescreen FADE_FROM_BLACK
	return

CaveOfTrials_EventScript_CheckIfComplete::
	call_if_unset FLAG_HIDE_KOKO, CaveOfTrials_EventScript_Ret
	call_if_unset FLAG_HIDE_BULU, CaveOfTrials_EventScript_Ret
	call_if_unset FLAG_HIDE_FINI, CaveOfTrials_EventScript_Ret
	call_if_unset FLAG_HIDE_LELE, CaveOfTrials_EventScript_Ret
	setvar VAR_TRIGGER_TAPUS, 1
	end

CaveOfTrials_EventScript_Ret::
	end

CaveOfTrials_EventScript_Unworthy::
	lock
	msgbox CaveOfTrials_Text_UnworthyAlert, MSGBOX_AUTOCLOSE
	release
	end

CaveOfTrials_Movement_Koko:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

CaveOfTrials_Movement_Bulu:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

CaveOfTrials_Movement_Fini:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

CaveOfTrials_Movement_Lele:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

CaveOfTrials_Text_UnworthyAlert:
	.string "...\p"
	.string "You are not yet worthy...\p"
	.string "...$"
