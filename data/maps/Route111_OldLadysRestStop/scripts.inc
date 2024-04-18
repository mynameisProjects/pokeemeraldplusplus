Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	call_if_unset FLAG_ROTOM_CAUGHT, Route111_OldLadysRestStop_EventScript_Reset_Rotom_Trigger
	end

Route111_OldLadysRestStop_Movement_Player_Face_Up::
	face_up
	step_end

Route111_OldLadysRestStop_EventScript_Reset_Rotom_Trigger::
	setvar VAR_TRIGGER_ROTOM, 1
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_OldMan::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_TVStrange, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_EventScript_RotomJump::
	playmoncry SPECIES_ROTOM, CRY_MODE_ENCOUNTER
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route111_OldLadysRestStop_Movement_Player_Face_Up
	waitmovement 0
	msgbox Route111_OldLadysRestStop_Text_PokemonAppeared, MSGBOX_AUTOCLOSE
	setwildbattle SPECIES_ROTOM, 30, ITEM_SPELL_TAG
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, Route111_OldLadysRestStop_EventScript_PostRotomBattleRematch
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route111_OldLadysRestStop_EventScript_PostRotomBattleRematch
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Route111_OldLadysRestStop_EventScript_PostRotomBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route111_OldLadysRestStop_EventScript_PostRotomBattle
	releaseall
	end

Route111_OldLadysRestStop_EventScript_PostRotomBattleRematch::
	playmoncry SPECIES_ROTOM, CRY_MODE_ENCOUNTER
	waitmoncry
	end

Route111_OldLadysRestStop_EventScript_PostRotomBattle::
	setvar VAR_TRIGGER_ROTOM, 0
	setflag FLAG_ROTOM_CAUGHT
	end


Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Oh, dear, dear.\n"
	.string "Aren't your POKéMON exhausted?\p"
	.string "If you'd like, rest up here.\n"
	.string "That's a fine idea! You should do that.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "That's right.\n"
	.string "Take your time and rest up!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Oh, dear, dear.\n"
	.string "Are your POKéMON still tired?\p"
	.string "You should take another rest here.\n"
	.string "That's a fine idea. You should do that.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "Is that so?\n"
	.string "You don't need to be shy about it.$"

Route111_OldLadysRestStop_Text_PokemonAppeared:
	.string "A wild POKéMON jumped out!$"

Route111_OldLadysRestStop_Text_TVStrange:
	.string "That TV has been acting so strange\n"
	.string "lately...$"

