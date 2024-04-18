.set LOCALID_RIVAL, 1

LittlerootTown_BrendansHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
	.byte 0

LittlerootTown_BrendansHouse_2F_OnTransition:
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos::
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_Ret
	goto LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos

LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_Ret
	@ Odd that the MaysHouse equivalent was used below instead
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
	setobjectxyperm LOCALID_RIVAL, 0, 2
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_2F_EventScript_Ret::
	return

LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
	return

LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan::
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	return

LittlerootTown_BrendansHouse_2F_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
	.2byte 0

LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SecretBase_EventScript_InitDecorations
	end

LittlerootTown_BrendansHouse_2F_EventScript_RivalsPokeBall::
	lockall
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan::
	delay 10
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 10
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth:
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest:
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest:
	delay_8
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast:
	walk_up
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

@ Unused, the player is already facing this direction so its unneeded
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_EventScript_PC::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC::
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Notebook::
	lockall
	msgbox PlayersHouse_2F_Text_PokepediaIntro, MSGBOX_DEFAULT
	scrollingmultichoice 3, 2, 2, 5, TRUE
	goto_if_eq VAR_RESULT, 0, PlayersHouse_2F_EventScript_KantoSelect
	goto_if_eq VAR_RESULT, 1, PlayersHouse_2F_EventScript_JohtoSelect
	goto_if_eq VAR_RESULT, 2, PlayersHouse_2F_EventScript_HoennSelect
	goto_if_eq VAR_RESULT, 3, PlayersHouse_2F_EventScript_SinnohSelect
	goto_if_eq VAR_RESULT, 4, PlayersHouse_2F_EventScript_UnovaSelect
	goto_if_eq VAR_RESULT, 5, PlayersHouse_2F_EventScript_KalosSelect
	goto_if_eq VAR_RESULT, 6, PlayersHouse_2F_EventScript_AlolaSelect
	goto_if_eq VAR_RESULT, 7, PlayersHouse_2F_EventScript_UBSelect
	releaseall
	end

PlayersHouse_2F_EventScript_KantoSelect::
	msgbox PlayersHouse_2F_Text_WhichPokemon, MSGBOX_DEFAULT
	scrollingmultichoice 4, 2, 2, 5, TRUE
	goto_if_eq VAR_RESULT, 0, PlayersHouse_2F_EventScript_Articuno
	goto_if_eq VAR_RESULT, 1, PlayersHouse_2F_EventScript_Zapdos
	goto_if_eq VAR_RESULT, 2, PlayersHouse_2F_EventScript_Moltres
	goto_if_eq VAR_RESULT, 3, PlayersHouse_2F_EventScript_Mew
	goto_if_eq VAR_RESULT, 4, PlayersHouse_2F_EventScript_Mewtwo
	releaseall
	end

PlayersHouse_2F_EventScript_Articuno::
	msgbox PlayersHouse_2F_Text_ArticunoInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Zapdos::
	msgbox PlayersHouse_2F_Text_ZapdosInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Moltres::
	msgbox PlayersHouse_2F_Text_MoltresInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Mewtwo::
	msgbox PlayersHouse_2F_Text_MewtwoInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Mew::
	msgbox PlayersHouse_2F_Text_MewInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_JohtoSelect::
	msgbox PlayersHouse_2F_Text_WhichPokemon, MSGBOX_DEFAULT
	scrollingmultichoice 5, 2, 2, 5, TRUE
	goto_if_eq VAR_RESULT, 0, PlayersHouse_2F_EventScript_Raikou
	goto_if_eq VAR_RESULT, 1, PlayersHouse_2F_EventScript_Entei
	goto_if_eq VAR_RESULT, 2, PlayersHouse_2F_EventScript_Suicune
	goto_if_eq VAR_RESULT, 3, PlayersHouse_2F_EventScript_Lugia
	goto_if_eq VAR_RESULT, 4, PlayersHouse_2F_EventScript_Hooh
	goto_if_eq VAR_RESULT, 5, PlayersHouse_2F_EventScript_Celebi
	releaseall
	end

PlayersHouse_2F_EventScript_Raikou::
	msgbox PlayersHouse_2F_Text_RaikouInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Entei::
	msgbox PlayersHouse_2F_Text_EnteiInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Suicune::
	msgbox PlayersHouse_2F_Text_SuicuneInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Lugia::
	msgbox PlayersHouse_2F_Text_LugiaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Hooh::
	msgbox PlayersHouse_2F_Text_HoohInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Celebi::
	msgbox PlayersHouse_2F_Text_CelebiInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_HoennSelect::
	msgbox PlayersHouse_2F_Text_WhichPokemon, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 2, 5, TRUE
	goto_if_eq VAR_RESULT, 0, PlayersHouse_2F_EventScript_Regirock
	goto_if_eq VAR_RESULT, 1, PlayersHouse_2F_EventScript_Regice
	goto_if_eq VAR_RESULT, 2, PlayersHouse_2F_EventScript_Registeel
	goto_if_eq VAR_RESULT, 3, PlayersHouse_2F_EventScript_Latias
	goto_if_eq VAR_RESULT, 4, PlayersHouse_2F_EventScript_Latios
	goto_if_eq VAR_RESULT, 5, PlayersHouse_2F_EventScript_Groudon
	goto_if_eq VAR_RESULT, 6, PlayersHouse_2F_EventScript_Kyogre
	goto_if_eq VAR_RESULT, 7, PlayersHouse_2F_EventScript_Rayquaza
	goto_if_eq VAR_RESULT, 8, PlayersHouse_2F_EventScript_Deoxys
	goto_if_eq VAR_RESULT, 9, PlayersHouse_2F_EventScript_Jirachi
	releaseall
	end

PlayersHouse_2F_EventScript_Regirock::
	msgbox PlayersHouse_2F_Text_RegirockInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Regice::
	msgbox PlayersHouse_2F_Text_RegiceInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Registeel::
	msgbox PlayersHouse_2F_Text_RegisteelInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Latias::
	msgbox PlayersHouse_2F_Text_LatiasInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Latios::
	msgbox PlayersHouse_2F_Text_LatiosInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Kyogre::
	msgbox PlayersHouse_2F_Text_KyogreInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Groudon::
	msgbox PlayersHouse_2F_Text_GroudonInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Rayquaza::
	msgbox PlayersHouse_2F_Text_RayquazaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Jirachi::
	msgbox PlayersHouse_2F_Text_JirachiInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Deoxys::
	msgbox PlayersHouse_2F_Text_DeoxysInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_SinnohSelect::
	msgbox PlayersHouse_2F_Text_WhichPokemon, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 2, 5, TRUE
	goto_if_eq VAR_RESULT, 0, PlayersHouse_2F_EventScript_Uxie
	goto_if_eq VAR_RESULT, 1, PlayersHouse_2F_EventScript_Mesprit
	goto_if_eq VAR_RESULT, 2, PlayersHouse_2F_EventScript_Azelf
	goto_if_eq VAR_RESULT, 3, PlayersHouse_2F_EventScript_Heatran
	goto_if_eq VAR_RESULT, 4, PlayersHouse_2F_EventScript_Regigigas
	goto_if_eq VAR_RESULT, 5, PlayersHouse_2F_EventScript_Cresselia
	goto_if_eq VAR_RESULT, 6, PlayersHouse_2F_EventScript_Darkrai
	goto_if_eq VAR_RESULT, 7, PlayersHouse_2F_EventScript_Dialga
	goto_if_eq VAR_RESULT, 8, PlayersHouse_2F_EventScript_Palkia
	goto_if_eq VAR_RESULT, 9, PlayersHouse_2F_EventScript_Giratina
	goto_if_eq VAR_RESULT, 10, PlayersHouse_2F_EventScript_Phione
	goto_if_eq VAR_RESULT, 11, PlayersHouse_2F_EventScript_Manaphy
	goto_if_eq VAR_RESULT, 12, PlayersHouse_2F_EventScript_Rotom
	goto_if_eq VAR_RESULT, 13, PlayersHouse_2F_EventScript_Shaymin
	goto_if_eq VAR_RESULT, 14, PlayersHouse_2F_EventScript_Arceus
	releaseall
	end

PlayersHouse_2F_EventScript_Uxie::
	msgbox PlayersHouse_2F_Text_UxieInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Mesprit::
	msgbox PlayersHouse_2F_Text_MespritInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Azelf::
	msgbox PlayersHouse_2F_Text_AzelfInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Heatran::
	msgbox PlayersHouse_2F_Text_HeatranInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Regigigas::
	msgbox PlayersHouse_2F_Text_RegigigasInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Cresselia::
	msgbox PlayersHouse_2F_Text_CresseliaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Darkrai::
	msgbox PlayersHouse_2F_Text_DarkraiInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Dialga::
	msgbox PlayersHouse_2F_Text_DialgaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Palkia::
	msgbox PlayersHouse_2F_Text_PalkiaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Giratina::
	msgbox PlayersHouse_2F_Text_GiratinaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Phione::
	msgbox PlayersHouse_2F_Text_PhioneInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Manaphy::
	msgbox PlayersHouse_2F_Text_ManaphyInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Rotom::
	msgbox PlayersHouse_2F_Text_RotomInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Shaymin::
	msgbox PlayersHouse_2F_Text_ShayminInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Arceus::
	msgbox PlayersHouse_2F_Text_ArceusInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_UnovaSelect::
	msgbox PlayersHouse_2F_Text_WhichPokemon, MSGBOX_DEFAULT
	scrollingmultichoice 8, 2, 2, 5, TRUE
	goto_if_eq VAR_RESULT, 0, PlayersHouse_2F_EventScript_Terrakion
	goto_if_eq VAR_RESULT, 1, PlayersHouse_2F_EventScript_Virizion
	goto_if_eq VAR_RESULT, 2, PlayersHouse_2F_EventScript_Cobalion
	goto_if_eq VAR_RESULT, 3, PlayersHouse_2F_EventScript_Tornadus
	goto_if_eq VAR_RESULT, 4, PlayersHouse_2F_EventScript_Thundurus
	goto_if_eq VAR_RESULT, 5, PlayersHouse_2F_EventScript_Landorus
	goto_if_eq VAR_RESULT, 6, PlayersHouse_2F_EventScript_Reshiram
	goto_if_eq VAR_RESULT, 7, PlayersHouse_2F_EventScript_Zekrom
	goto_if_eq VAR_RESULT, 8, PlayersHouse_2F_EventScript_Kyurem
	goto_if_eq VAR_RESULT, 9, PlayersHouse_2F_EventScript_Victini
	goto_if_eq VAR_RESULT, 10, PlayersHouse_2F_EventScript_Keldeo
	goto_if_eq VAR_RESULT, 11, PlayersHouse_2F_EventScript_Meloetta
	goto_if_eq VAR_RESULT, 12, PlayersHouse_2F_EventScript_Genesect
	releaseall
	end

PlayersHouse_2F_EventScript_Terrakion::
	msgbox PlayersHouse_2F_Text_TerrakionInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Virizion::
	msgbox PlayersHouse_2F_Text_VirizionInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Cobalion::
	msgbox PlayersHouse_2F_Text_CobalionInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Tornadus::
	msgbox PlayersHouse_2F_Text_TornadusInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Thundurus::
	msgbox PlayersHouse_2F_Text_ThundurusInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Landorus::
	msgbox PlayersHouse_2F_Text_LandorusInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Reshiram::
	msgbox PlayersHouse_2F_Text_ReshiramInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Zekrom::
	msgbox PlayersHouse_2F_Text_ZekromInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Kyurem::
	msgbox PlayersHouse_2F_Text_KyuremInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Victini::
	msgbox PlayersHouse_2F_Text_VictiniInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Keldeo::
	msgbox PlayersHouse_2F_Text_KeldeoInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Meloetta::
	msgbox PlayersHouse_2F_Text_MeloettaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Genesect::
	msgbox PlayersHouse_2F_Text_GenesectInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_KalosSelect::
	msgbox PlayersHouse_2F_Text_WhichPokemon, MSGBOX_DEFAULT
	scrollingmultichoice 9, 2, 2, 5, TRUE
	goto_if_eq VAR_RESULT, 0, PlayersHouse_2F_EventScript_Xerneas
	goto_if_eq VAR_RESULT, 1, PlayersHouse_2F_EventScript_Yveltal
	goto_if_eq VAR_RESULT, 2, PlayersHouse_2F_EventScript_Zygarde
	goto_if_eq VAR_RESULT, 3, PlayersHouse_2F_EventScript_Diancie
	goto_if_eq VAR_RESULT, 4, PlayersHouse_2F_EventScript_Hoopa
	goto_if_eq VAR_RESULT, 5, PlayersHouse_2F_EventScript_Volcanion
	releaseall
	end

PlayersHouse_2F_EventScript_Xerneas::
	msgbox PlayersHouse_2F_Text_XerneasInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Yveltal::
	msgbox PlayersHouse_2F_Text_YveltalInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Zygarde::
	msgbox PlayersHouse_2F_Text_ZygardeInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Diancie::
	msgbox PlayersHouse_2F_Text_DiancieInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Hoopa::
	msgbox PlayersHouse_2F_Text_HoopaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Volcanion::
	msgbox PlayersHouse_2F_Text_VolcanionInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_AlolaSelect::
	msgbox PlayersHouse_2F_Text_WhichPokemon, MSGBOX_DEFAULT
	scrollingmultichoice 10, 2, 2, 5, TRUE
	goto_if_eq VAR_RESULT, 0, PlayersHouse_2F_EventScript_TypeN
	goto_if_eq VAR_RESULT, 1, PlayersHouse_2F_EventScript_Tapus
	goto_if_eq VAR_RESULT, 2, PlayersHouse_2F_EventScript_Solgaleo
	goto_if_eq VAR_RESULT, 3, PlayersHouse_2F_EventScript_Lunala
	goto_if_eq VAR_RESULT, 4, PlayersHouse_2F_EventScript_Magearna
	goto_if_eq VAR_RESULT, 5, PlayersHouse_2F_EventScript_Marshadow
	goto_if_eq VAR_RESULT, 6, PlayersHouse_2F_EventScript_Zeraora
	goto_if_eq VAR_RESULT, 7, PlayersHouse_2F_EventScript_Meltan
	releaseall
	end

PlayersHouse_2F_EventScript_TypeN::
	msgbox PlayersHouse_2F_Text_TypeNInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Tapus::
	msgbox PlayersHouse_2F_Text_TapusInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Solgaleo::
	msgbox PlayersHouse_2F_Text_SolgaleoInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Lunala::
	msgbox PlayersHouse_2F_Text_LunalaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Magearna::
	msgbox PlayersHouse_2F_Text_MagearnaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Marshadow::
	msgbox PlayersHouse_2F_Text_MarshadowInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Zeraora::
	msgbox PlayersHouse_2F_Text_ZeraoraInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Meltan::
	msgbox PlayersHouse_2F_Text_MeltanInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_UBSelect::
	msgbox PlayersHouse_2F_Text_WhichPokemon, MSGBOX_DEFAULT
	scrollingmultichoice 11, 2, 2, 5, TRUE
	goto_if_eq VAR_RESULT, 0, PlayersHouse_2F_EventScript_Nihilego
	goto_if_eq VAR_RESULT, 1, PlayersHouse_2F_EventScript_Buzzwole
	goto_if_eq VAR_RESULT, 2, PlayersHouse_2F_EventScript_Pheromosa
	goto_if_eq VAR_RESULT, 3, PlayersHouse_2F_EventScript_Xurkitree
	goto_if_eq VAR_RESULT, 4, PlayersHouse_2F_EventScript_Celesteela
	goto_if_eq VAR_RESULT, 5, PlayersHouse_2F_EventScript_Kartana
	goto_if_eq VAR_RESULT, 6, PlayersHouse_2F_EventScript_Guzzlord
	goto_if_eq VAR_RESULT, 7, PlayersHouse_2F_EventScript_Poipole
	goto_if_eq VAR_RESULT, 8, PlayersHouse_2F_EventScript_Stakataka
	goto_if_eq VAR_RESULT, 9, PlayersHouse_2F_EventScript_Blacephalon
	goto_if_eq VAR_RESULT, 10, PlayersHouse_2F_EventScript_Necrozma
	releaseall
	end

PlayersHouse_2F_EventScript_Nihilego::
	msgbox PlayersHouse_2F_Text_NihilegoInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Buzzwole::
	msgbox PlayersHouse_2F_Text_BuzzwoleInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Pheromosa::
	msgbox PlayersHouse_2F_Text_PheromosaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Xurkitree::
	msgbox PlayersHouse_2F_Text_XurkitreeInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Celesteela::
	msgbox PlayersHouse_2F_Text_CelesteelaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Kartana::
	msgbox PlayersHouse_2F_Text_KartanaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Guzzlord::
	msgbox PlayersHouse_2F_Text_GuzzlordInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Poipole::
	msgbox PlayersHouse_2F_Text_PoipoleInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Stakataka::
	msgbox PlayersHouse_2F_Text_StakatakaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Blacephalon::
	msgbox PlayersHouse_2F_Text_BlacephalonInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Necrozma::
	msgbox PlayersHouse_2F_Text_NecrozmaInfo, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_GameCube::
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
	end

PlayersHouse_2F_Text_PokepediaIntro:
	.string "It's a POKépedia! Which region's\n"
	.string "POKéMON would you like to learn about?$"

PlayersHouse_2F_Text_WhichPokemon:
	.string "Which POKéMON do you want to learn\n"
	.string "more about?$"

PlayersHouse_2F_Text_ArticunoInfo:
	.string "This legendary bird is rumored\n"
	.string "to dwell in the coldest room of\l"
	.string "Shoal Cave.$"

PlayersHouse_2F_Text_ZapdosInfo:
	.string "This legendary bird loves\n"
	.string "making a home in power plants.$"

PlayersHouse_2F_Text_MoltresInfo:
	.string "This legendary bird sticks to\n"
	.string "hot paths around the region when\l"
	.string "possible.$"

PlayersHouse_2F_Text_MewtwoInfo:
	.string "Mewtwo is an artificial POKéMON\p"
	.string "Supposedly, there is a team working\n"
	.string "to recreate it in a hidden lab near\l"
	.string "Pacifidlog Town.$"

PlayersHouse_2F_Text_MewInfo:
	.string "The legendary Mew is thought to live\n"
	.string "on a faraway island. Sometimes parents\l"
	.string "give their children tickets to go there.$"

PlayersHouse_2F_Text_RaikouInfo:
	.string "This POKéMON can be found roaming\n"
	.string "the region. Check your POKéDEX for\l"
	.string "more information!$"

PlayersHouse_2F_Text_EnteiInfo:
	.string "This POKéMON can be found roaming\n"
	.string "the region. Check your POKéDEX for\l"
	.string "more information!$"

PlayersHouse_2F_Text_SuicuneInfo:
	.string "This POKéMON can be found roaming\n"
	.string "the region. Check your POKéDEX for\l"
	.string "more information!$"

PlayersHouse_2F_Text_LugiaInfo:
	.string "Both Lugia and Ho-oh are thought to\n"
	.string "live on Navel Rock, rulers of the sky\l"
	.string "above and water below.\p"
	.string "Some parents are willing to send their\n"
	.string "brave little trainers there!$"

PlayersHouse_2F_Text_HoohInfo:
	.string "Both Ho-oh and Lugia are thought to\n"
	.string "live on Navel Rock, rulers of the sky\l"
	.string "above and water below.\p"
	.string "Some parents are willing to send their\n"
	.string "brave little trainers there!$"

PlayersHouse_2F_Text_CelebiInfo:
	.string "Celebi is the time travel POKéMON.\p"
	.string "Some have once believed that it would\n"
	.string "appear to strong trainers in the woods.$"

PlayersHouse_2F_Text_RegirockInfo:
	.string "A member of the legendary giant POKéMON,\n"
	.string "it likes to hide in old desert ruins,\l"
	.string "away from humans and POKéMON alike.$"

PlayersHouse_2F_Text_RegiceInfo:
	.string "A member of the legendary giant POKéMON,\n"
	.string "it is said to hide out on a frigid island\l"
	.string "cave away from humans and POKéMON alike.$"

PlayersHouse_2F_Text_RegisteelInfo:
	.string "A member of the legendary giant POKéMON,\n"
	.string "it likes to hide in ancient tombs,\l"
	.string "away from humans and POKéMON alike.$"

PlayersHouse_2F_Text_LatiasInfo:
	.string "Latias belongs to the Eon Duo with its\n"
	.string "twin, Latios. It may be seen soaring\l"
	.string "around the Hoenn region, or resting on\p"
	.string "an island south of the region.$"

PlayersHouse_2F_Text_LatiosInfo:
	.string "Latios belongs to the Eon Duo with its\n"
	.string "twin, Latias. It may be seen soaring\l"
	.string "around the Hoenn region, or resting on\p"
	.string "an island south of the region.$"

PlayersHouse_2F_Text_KyogreInfo:
	.string "A legendary POKéMON, ruler of the ocean.\n"
	.string "No one is quite sure where it lives.$"

PlayersHouse_2F_Text_GroudonInfo:
	.string "A legendary POKéMON, ruler of the land.\n"
	.string "No one is quite sure where it lives.$"

PlayersHouse_2F_Text_RayquazaInfo:
	.string "A legendary POKéMON, ruler of the sky.\n"
	.string "It is thought to be a peace-maker\l"
	.string "POKéMON that lives in a high tower.$"

PlayersHouse_2F_Text_JirachiInfo:
	.string "Often, this POKéMON can be found\n"
	.string "granting wishes to young POKéMON\l"
	.string "trainers in their rooms at night.$"

PlayersHouse_2F_Text_DeoxysInfo:
	.string "Not much is known about this alien\n"
	.string "POKéMON other than it currently dwells\l"
	.string "on an island far away...\p"
	.string "Many people wish for a special ticket\n"
	.string "to see such a fascinating POKéMON.$"

PlayersHouse_2F_Text_UxieInfo:
	.string "This POKéMON can be found roaming\n"
	.string "the region. Check your POKéDEX for\l"
	.string "more information!$"

PlayersHouse_2F_Text_MespritInfo:
	.string "This POKéMON can be found roaming\n"
	.string "the region. Check your POKéDEX for\l"
	.string "more information!$"

PlayersHouse_2F_Text_AzelfInfo:
	.string "This POKéMON can be found roaming\n"
	.string "the region. Check your POKéDEX for\l"
	.string "more information!$"

PlayersHouse_2F_Text_HeatranInfo:
	.string "The Lava Dome POKéMON, Heatran\n"
	.string "loves to warm it's body in volcanoes\l"
	.string "and on hot mountain tops.$"

PlayersHouse_2F_Text_RegigigasInfo:
	.string "There is a strange saying associated\n"
	.string "with this colossal POKéMON:\p"
	.string "Three brothers brought together to\n"
	.string "a sealed salt water room.\p"
	.string "No one yet knows what this means.$"

PlayersHouse_2F_Text_CresseliaInfo:
	.string "Called the Lunar POKéMON, Cresselia\n"
	.string "lives in the dream world of\l"
	.string "imaginative trainers.\p"
	.string "It is said that sailors arriving at\n"
	.string "port often seek to meet this POKéMON\l"
	.string "in their dreams.$"

PlayersHouse_2F_Text_DarkraiInfo:
	.string "The Pictch-Black POKéMON, Darkrai\n"
	.string "lives in the nightmare world of\l"
	.string "troubled trainers.$"

PlayersHouse_2F_Text_DialgaInfo:
	.string "Not much is known about this legendary\n"
	.string "space POKéMON, though the famed\l"
	.string "POKéMON trainer Steven Stone is\l"
	.string "actively studying their realm in\l"
	.string "Mossdeep.$"

PlayersHouse_2F_Text_PalkiaInfo:
	.string "Not much is known about this legendary\n"
	.string "space POKéMON, though the famed\l"
	.string "POKéMON trainer Steven Stone is\l"
	.string "actively studying their realm in\l"
	.string "Mossdeep.$"

PlayersHouse_2F_Text_GiratinaInfo:
	.string "Not much is known about this legendary\n"
	.string "space POKéMON, though the famed\l"
	.string "POKéMON trainer Steven Stone is\l"
	.string "actively studying their realm in\l"
	.string "Mossdeep.$"

PlayersHouse_2F_Text_PhioneInfo:
	.string "This quiet and quant little POKéMON can\n"
	.string "sometimes be seen playing with trainers\l"
	.string "in the ocean.\p"
	.string "It is thought to live underwater.$"

PlayersHouse_2F_Text_ManaphyInfo:
	.string "This fun-loving and social little\n"
	.string "POKéMON is sometimes seen playing with\l"
	.string "trainers in the ocean.\p"
	.string "It is thought to live underwater.$"

PlayersHouse_2F_Text_RotomInfo:
	.string "Rotom is a prankster POKéMON.\p"
	.string "They can often be found hiding in\n"
	.string "the unused electronics of old people.$"

PlayersHouse_2F_Text_ShayminInfo:
	.string "Shaymin is an interesting POKéMON with\n"
	.string "two forms. It likes to roam the woods.$"

PlayersHouse_2F_Text_ArceusInfo:
	.string "Believed to be the first POKéMON, the\n"
	.string "creator of all life. It will often\l"
	.string "spend extended time with exceptionally\l"
	.string "strong trainers.\p"
	.string "Perhaps if you go to the highest tower,\n"
	.string "you might catch a glimpse of it?$"

PlayersHouse_2F_Text_TerrakionInfo:
	.string "This POKéMON can be found roaming\n"
	.string "the region. Check your POKéDEX for\l"
	.string "more information!$"

PlayersHouse_2F_Text_VirizionInfo:
	.string "This POKéMON can be found roaming\n"
	.string "the region. Check your POKéDEX for\l"
	.string "more information!$"

PlayersHouse_2F_Text_CobalionInfo:
	.string "This POKéMON can be found roaming\n"
	.string "the region. Check your POKéDEX for\l"
	.string "more information!$"

PlayersHouse_2F_Text_TornadusInfo:
	.string "This POKéMON can be found roaming\n"
	.string "the region. Check your POKéDEX for\l"
	.string "more information!$"

PlayersHouse_2F_Text_ThundurusInfo:
	.string "This POKéMON can be found roaming\n"
	.string "the region. Check your POKéDEX for\l"
	.string "more information!$"

PlayersHouse_2F_Text_LandorusInfo:
	.string "This POKéMON can be found roaming\n"
	.string "the region. Check your POKéDEX for\l"
	.string "more information!$"

PlayersHouse_2F_Text_ReshiramInfo:
	.string "Is that blue-eyes-white-dragon?\n"
	.string "Nope! It's Reshiram!\p"
	.string "Rumor has it that it is dwelling with\n"
	.string "its partner somewhere near the\l"
	.string "battle frontier.$"

PlayersHouse_2F_Text_ZekromInfo:
	.string "Don't let this POKéMON's deep black\n"
	.string "coat fool you. There is a fearsome\l"
	.string "dragon beneath!\p"
	.string "Rumor has it that it is dwelling with\n"
	.string "its partner somewhere near the\l"
	.string "battle frontier.$"

PlayersHouse_2F_Text_KyuremInfo:
	.string "This fearsome icy dragon likes to\n"
	.string "dwell in low, cold places. If the\l"
	.string "timing is right, you might be able to\l"
	.string "to see it!$"

PlayersHouse_2F_Text_VictiniInfo:
	.string "Victini is a lucky POKéMON!\p"
	.string "Perhaps you can find it somewhere in\n"
	.string "the cozmos?$"

PlayersHouse_2F_Text_KeldeoInfo:
	.string "Keldeo is considered a Sword of Justice,\n"
	.string "a protector POKéMON. It is the sworn\l"
	.string "enemy of the legendary Kyurem.\p"
	.string "Maybe finding one will lead to the other?$"

PlayersHouse_2F_Text_MeloettaInfo:
	.string "This POKéMON is a melodic force to be\n"
	.string "reckoned with. It sings its sweet song\l"
	.string "to trainers just beginning their journey.$"

PlayersHouse_2F_Text_GenesectInfo:
	.string "This ancient POKéMON is a run-away,\n"
	.string "technology-enhanced fossil come to life!\p"
	.string "Like the cannon on its back, it likes to\n"
	.string "dwell in changing caves.$"

PlayersHouse_2F_Text_XerneasInfo:
	.string "Supposedly, there is a hidden forest\n"
	.string "near the Weather Institute where this\l"
	.string "life-giving POKéMON finds solace.$"

PlayersHouse_2F_Text_YveltalInfo:
	.string "Hidden far away in a hideout somewhere,\n"
	.string "many believe this POKéMON is evil in\l"
	.string "in nature.\p"
	.string "It would not be a surprise if it was\n"
	.string "working with an evil organization.$"

PlayersHouse_2F_Text_ZygardeInfo:
	.string "The Order POKéMON. Zygarde is a\n"
	.string "mysterious POKéMON that likes to live\l"
	.string "in green caves.$"

PlayersHouse_2F_Text_DiancieInfo:
	.string "A small, beautiful jewel POKéMON. It\n"
	.string "most likely lives tucked away in a\l"
	.string "cave of granite.$"

PlayersHouse_2F_Text_HoopaInfo:
	.string "Hoopa is a dangerous, mischevieus\n"
	.string "POKéMON.\p"
	.string "Always changing and causing mirages, it\n"
	.string "never ceases creating portals and\l"
	.string "trouble.\p"
	.string "It never stays in one place, but could be\n"
	.string "found in often-vanishing places.$"

PlayersHouse_2F_Text_VolcanionInfo:
	.string "The Steam POKéMON, Volcanion\n"
	.string "loves to warm it's body in volcanoes\l"
	.string "and on hot mountain tops.$"

PlayersHouse_2F_Text_TypeNInfo:
	.string "This POKéMON is not naturally born,\n"
	.string "rather it was created by a scientist\l"
	.string "at the Weather Institiute in an\l"
	.string "attempt to control the weather.$"

PlayersHouse_2F_Text_TapusInfo:
	.string "Guardians of the Alolan Islands, the\n"
	.string "4 Tapu POKéMON may travel to other\l"
	.string "regions to battle strong trainers.\p"
	.string "They were most recently spotted in\n"
	.string "a cave off of Route 107.$"

PlayersHouse_2F_Text_SolgaleoInfo:
	.string "A powerful final evolution of the\n"
	.string "Cosmog line, when Cosmoem evolves\l"
	.string "during the day.\p"
	.string "Cosmog can be found in ghostly\n"
	.string "towers.$"

PlayersHouse_2F_Text_LunalaInfo:
	.string "A powerful final evolution of the\n"
	.string "Cosmog line, when Cosmoem evolves\l"
	.string "during the night.\p"
	.string "Cosmog can be found in ghostly\n"
	.string "towers.$"

PlayersHouse_2F_Text_MagearnaInfo:
	.string "Magearna is an artificial POKéMON.\n"
	.string "Many believe its steel parts come from\l"
	.string "meteors that fell to the earth.$"

PlayersHouse_2F_Text_MarshadowInfo:
	.string "The Gloomdweller POKéMON. No one\n"
	.string "even knows if this POKéMON exists.\p"
	.string "Rumors of it living in a hidden\n"
	.string "forest are rampant, but it remains\l"
	.string "unconfirmed.$"

PlayersHouse_2F_Text_ZeraoraInfo:
	.string "This POKéMON was born from an\n"
	.string "explosive mix of lightning and\l"
	.string "erupting volcano.\p"
	.string "Somewhere out there it may dwell\n"
	.string "on the slab that was scorched by\l"
	.string "the strike.$"

PlayersHouse_2F_Text_MeltanInfo:
	.string "Meltan, a cute liquid metal POKéMON,\n"
	.string "has a distinct interest in fossils.\p"
	.string "Where lost fossils may be found,\n"
	.string "so a Meltan may be found as well.$"

PlayersHouse_2F_Text_NihilegoInfo:
	.string "A beast POKéMON from another world,\n"
	.string "brought here through a portal on\p"
	.string "Route 129.$"

PlayersHouse_2F_Text_BuzzwoleInfo:
	.string "A beast POKéMON from another world,\n"
	.string "brought here through a portal on\p"
	.string "Route 103.$"

PlayersHouse_2F_Text_PheromosaInfo:
	.string "A beast POKéMON from another world,\n"
	.string "brought here through a portal on\p"
	.string "Route 110.$"

PlayersHouse_2F_Text_XurkitreeInfo:
	.string "A beast POKéMON from another world,\n"
	.string "brought here through a portal in\p"
	.string "Evergrande City.$"

PlayersHouse_2F_Text_CelesteelaInfo:
	.string "A beast POKéMON from another world,\n"
	.string "brought here through a portal on\p"
	.string "Route 114.$"

PlayersHouse_2F_Text_KartanaInfo:
	.string "A beast POKéMON from another world,\n"
	.string "brought here through a portal on\p"
	.string "Route 118.$"

PlayersHouse_2F_Text_GuzzlordInfo:
	.string "A beast POKéMON from another world,\n"
	.string "brought here through a portal in\p"
	.string "Sootopolis City.$"

PlayersHouse_2F_Text_PoipoleInfo:
	.string "A beast POKéMON from another world,\n"
	.string "brought here through a portal on\p"
	.string "Route 109.$"

PlayersHouse_2F_Text_StakatakaInfo:
	.string "A beast POKéMON from another world,\n"
	.string "brought here through a portal on\p"
	.string "Route 115.$"

PlayersHouse_2F_Text_BlacephalonInfo:
	.string "A beast POKéMON from another world,\n"
	.string "brought here through a portal on\p"
	.string "Route 132.$"

PlayersHouse_2F_Text_NecrozmaInfo:
	.string "A beast POKéMON from another world,\n"
	.string "brought here through a portal on\p"
	.string "Mt. Pyre.$"

PlayersHouse_2F_Text_ClockIsStopped:
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"

PlayersHouse_2F_Text_HowDoYouLikeYourRoom:
	.string "MOM: {PLAYER}, how do you like your\n"
	.string "new room?\p"
	.string "Good! Everything's put away neatly!\p"
	.string "They finished moving everything in\n"
	.string "downstairs, too.\p"
	.string "POKéMON movers are so convenient!\p"
	.string "Oh, you should make sure that\n"
	.string "everything's all there on your desk.$"

PlayersHouse_2F_Text_Notebook:
	.string "{PLAYER} flipped open the notebook.\p"
	.string "ADVENTURE RULE NO. 1\n"
	.string "Open the MENU with START.\p"
	.string "ADVENTURE RULE NO. 2\n"
	.string "Record your progress with SAVE.\p"
	.string "The remaining pages are blank…$"

Common_Text_LookCloserAtMap:
	.string "{PLAYER} took a closer look at the\n"
	.string "HOENN region map.$"

PlayersHouse_2F_Text_ItsAGameCube:
	.string "It's a Nintendo GameCube.\p"
	.string "A Game Boy Advance is connected to\n"
	.string "serve as the Controller.$"
