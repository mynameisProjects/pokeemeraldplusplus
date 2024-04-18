.set LOCALID_ROOT_FOSSIL, 1
.set LOCALID_CLAW_FOSSIL, 2

MirageTower_4F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MirageTower_4F_OnTransition
	.byte 0

MirageTower_4F_OnTransition:
	goto MirageTower_4F_EventScript_CheckCompletion
	end

MirageTower_4F_EventScript_CheckCompletion::
	goto_if_set FLAG_HIDE_MEW, MirageTower_4F_EventScript_CheckHoopaCaught
	end

MirageTower_4F_EventScript_CheckHoopaCaught::
	goto_if_unset FLAG_CAUGHT_HOOPA, MirageTower_4F_EventScript_CheckHoopaState
	end

MirageTower_4F_EventScript_CheckHoopaState::
	goto_if_unset FLAG_MET_HOOPA_ONCE, MirageTower_4F_EventScript_HoopaVisible
	goto_if_ge VAR_ALL_HOOPA_PORTALS, 11, MirageTower_4F_EventScript_HoopaVisible
	end

MirageTower_4F_EventScript_HoopaVisible::
	clearflag FLAG_HIDE_HOOPA
	end

MirageTower_4F_EventScript_HoopaInteraction::
	goto_if_ge VAR_ALL_HOOPA_PORTALS, 11, MirageTower_4F_EventScript_HoopaBattle
	goto_if_unset FLAG_ALL_PORTALS_CLOSED, MirageTower_4F_EventScript_HoopaRunOff
	end

MirageTower_4F_EventScript_HoopaRunOff::
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 32  @ num shakes
	setvar VAR_0x8007, 2   @ shake delay
	special ShakeCamera
	waitstate
	applymovement 4, MirageTower_4F_Movement_HoopaExit
	waitmovement 0
	fadescreen FADE_TO_BLACK
	removeobject 4
	removeobject 5
	setflag FLAG_MET_HOOPA_ONCE
	fadescreen FADE_FROM_BLACK
	lock
	msgbox MirageTower_4F_Text_PortalsEverywhere, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_Movement_HoopaExit:
	face_up
	walk_up
	step_end

MirageTower_4F_EventScript_HoopaBattle::
	lockall
	playmoncry SPECIES_HOOPA, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_HOOPA, 100, ITEM_PRISON_BOTTLE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MirageTower_4F_EventScript_PostHoopaBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MirageTower_4F_EventScript_PostHoopaBattle
	releaseall
	end

MirageTower_4F_EventScript_PostHoopaBattle::
	fadescreen FADE_TO_BLACK
	removeobject 4
	removeobject 5
	setflag FLAG_HIDE_HOOPA
	setflag FLAG_CAUGHT_HOOPA
	fadescreen FADE_FROM_BLACK
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_RootFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeRootFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveRootFossil
	giveitem ITEM_ROOT_FOSSIL
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	removeobject LOCALID_ROOT_FOSSIL
	delay 30
	setflag FLAG_CHOSE_ROOT_FOSSIL
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveRootFossil::
	msgbox MirageTower_4F_Text_LeftRootFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_ClawFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeClawFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveClawFossil
	giveitem ITEM_CLAW_FOSSIL
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	removeobject LOCALID_CLAW_FOSSIL
	delay 30
	setflag FLAG_CHOSE_CLAW_FOSSIL
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveClawFossil::
	msgbox MirageTower_4F_Text_LeaveClawFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_CollapseMirageTower::
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 32  @ num shakes
	setvar VAR_0x8007, 2   @ shake delay
	special ShakeCamera
	waitstate
	special DoMirageTowerCeilingCrumble
	waitstate
	call_if_set FLAG_CAUGHT_HOOPA, MirageTower_4F_EventScript_MirageFlags
	warp MAP_ROUTE111, 19, 59
	waitstate
	release
	end

MirageTower_4F_EventScript_MirageFlags::
	setvar VAR_MIRAGE_TOWER_STATE, 1
	clearflag FLAG_LANDMARK_MIRAGE_TOWER
	return

MirageTower_4F_Text_TakeRootFossil:
	.string "You found the ROOT FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the ROOT FOSSIL anyway?$"

MirageTower_4F_Text_LeftRootFossilAlone:
	.string "{PLAYER} left the ROOT FOSSIL alone.$"

MirageTower_4F_Text_TakeClawFossil:
	.string "You found the CLAW FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the CLAW FOSSIL anyway?$"

MirageTower_4F_Text_LeaveClawFossilAlone:
	.string "{PLAYER} left the CLAW FOSSIL alone.$"

MirageTower_4F_Text_PortalsEverywhere:
	.string "Portals have scattered across\n"
	.string "the world!$"
