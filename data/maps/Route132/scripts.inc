Route132_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route132_OnLoad
	.byte 0

Route132_OnLoad:
	setflag FLAG_HIDE_BLACEPHALON
	goto_if_set FLAG_MET_HOOPA_ONCE, Route132_EventScript_CheckIfCaught
	end

Route132_EventScript_CheckIfCaught::
	goto_if_unset FLAG_CAUGHT_BLACEPHALON, Route132_EventScript_ShowPortal
	end

Route132_EventScript_ShowPortal::
	clearflag FLAG_HIDE_BLACEPHALON
	end

Route132_EventScript_BlacephalonBattle::
	lockall
	playmoncry SPECIES_BLACEPHALON, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_BLACEPHALON, 50, ITEM_DREAD_PLATE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Route132_EventScript_PostBlacephalonBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route132_EventScript_PostBlacephalonBattle
	releaseall
	end

Route132_EventScript_PostBlacephalonBattle::
	fadescreen FADE_TO_BLACK
	removeobject 11
	setflag FLAG_HIDE_BLACEPHALON
	setflag FLAG_CAUGHT_BLACEPHALON
	fadescreen FADE_FROM_BLACK
	addvar VAR_ALL_HOOPA_PORTALS, 1
	end

Route132_EventScript_Gilbert::
	trainerbattle_single TRAINER_GILBERT, Route132_Text_GilbertIntro, Route132_Text_GilbertDefeat
	msgbox Route132_Text_GilbertPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Dana::
	trainerbattle_single TRAINER_DANA, Route132_Text_DanaIntro, Route132_Text_DanaDefeat
	msgbox Route132_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD, Route132_Text_RonaldIntro, Route132_Text_RonaldDefeat
	msgbox Route132_Text_RonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Kiyo::
	trainerbattle_single TRAINER_KIYO, Route132_Text_KiyoIntro, Route132_Text_KiyoDefeat
	msgbox Route132_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Paxton::
	trainerbattle_single TRAINER_PAXTON, Route132_Text_PaxtonIntro, Route132_Text_PaxtonDefeat
	msgbox Route132_Text_PaxtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Darcy::
	trainerbattle_single TRAINER_DARCY, Route132_Text_DarcyIntro, Route132_Text_DarcyDefeat
	msgbox Route132_Text_DarcyPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Jonathan::
	trainerbattle_single TRAINER_JONATHAN, Route132_Text_JonathanIntro, Route132_Text_JonathanDefeat
	msgbox Route132_Text_JonathanPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Makayla::
	trainerbattle_single TRAINER_MAKAYLA, Route132_Text_MakaylaIntro, Route132_Text_MakaylaDefeat
	msgbox Route132_Text_MakaylaPostBattle, MSGBOX_AUTOCLOSE
	end

