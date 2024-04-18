FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_LittleGirl::
	call_if_unset FLAG_RECEIVED_VICTINI FallarborTown_CozmosHouse_EventScript_WantVictini
	call_if_set FLAG_RECEIVED_VICTINI FallarborTown_CozmosHouse_EventScript_TakeCareOfIt
	end

FallarborTown_CozmosHouse_EventScript_WantVictini::
	lock
	msgbox FallarborTown_CozmosHouse_Text_MomCutsApples MSGBOX_DEFAULT
	showmonpic SPECIES_VICTINI, 10, 3
	msgbox FallarborTown_CozmosHouse_Text_WantPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_OhOK
	goto FallarborTown_CozmosHouse_EventScript_GiveVictini
	end

FallarborTown_CozmosHouse_EventScript_OhOK::
	hidemonpic
	msgbox FallarborTown_CozmosHouse_Text_OhOK, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_CozmosHouse_EventScript_GiveVictini::
	bufferspeciesname STR_VAR_1, SPECIES_VICTINI
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_VICTINI
	givemon SPECIES_VICTINI, 15
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, FallarborTown_CozmosHouse_EventScript_SendVictiniToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, FallarborTown_CozmosHouse_EventScript_SendVictiniToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

FallarborTown_CozmosHouse_EventScript_SendVictiniToParty::
	call FallarborTown_CozmosHouse_EventScript_ReceivedVictiniPokemon
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_ReceivedVictini
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto FallarborTown_CozmosHouse_EventScript_ReceivedVictini
	end

FallarborTown_CozmosHouse_EventScript_SendVictiniToPC::
	call FallarborTown_CozmosHouse_EventScript_ReceivedVictiniPokemon
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_VictiniTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto FallarborTown_CozmosHouse_EventScript_VictiniTransferredToPC
	end

FallarborTown_CozmosHouse_EventScript_VictiniTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto FallarborTown_CozmosHouse_EventScript_ReceivedVictini
	end

FallarborTown_CozmosHouse_EventScript_ReceivedVictini::
	hidemonpic
	msgbox FallarborTown_CozmosHouse_Text_TakeCareOfIt MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_CozmosHouse_EventScript_ReceivedVictiniPokemon::
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	setflag FLAG_RECEIVED_VICTINI
	return

FallarborTown_CozmosHouse_EventScript_TakeCareOfIt::
	lock
	msgbox FallarborTown_CozmosHouse_Text_TakeCareOfIt MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "PROF. COZMO: Oh…\n"
	.string "I never should have let myself be\l"
	.string "conned into telling TEAM MAGMA where\l"
	.string "you can find METEORITES…\p"
	.string "That METEORITE from METEOR FALLS…\n"
	.string "It's never going to be mine now…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "Oh!\n"
	.string "Hah?\p"
	.string "That item…\p"
	.string "Could it be?\p"
	.string "Is it the METEORITE that TEAM MAGMA\n"
	.string "took from METEOR FALLS?\p"
	.string "Please, may I have it?\p"
	.string "I'm not asking for it for free.\n"
	.string "How about in exchange for this TM?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "PROF. COZMO: This TM, it represents\n"
	.string "my feeling of gratitude.\l"
	.string "Please use it!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "PROF. COZMO: Oh, I can't believe it.\n"
	.string "This is really, really great!\p"
	.string "This is really going to help my research!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "PROF. COZMO: Oh, but…\n"
	.string "I'm crushed with disappointment…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "PROF. COZMO: Please, may I have that\n"
	.string "METEORITE?\p"
	.string "I'm not asking for it for free.\n"
	.string "How about in exchange for this TM?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "PROF. COZMO went off to METEOR FALLS\n"
	.string "on ROUTE 114 with some people from\l"
	.string "TEAM MAGMA.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Poor PROF. COZMO…\n"
	.string "He's so depressed… I feel sorry for him.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Look at PROF. COZMO…\n"
	.string "He's so happy! I think it's cute.$"

FallarborTown_CozmosHouse_Text_MomCutsApples:
	.string "My mommy always cuts my apples\n"
	.string "for me.\p"
	.string "...\p"
	.string "I found a POKéMON that looks like\n"
	.string "my apples!$"

FallarborTown_CozmosHouse_Text_WantPokemon:
	.string "Do you want it?$"

FallarborTown_CozmosHouse_Text_OhOK:
	.string "Oh, OK.$"

FallarborTown_CozmosHouse_Text_TakeCareOfIt:
	.string "Take good care of it!!$"

FallarborTown_CozmosHouse_Text_Received:
	.string "{PLAYER} received the {STR_VAR_1}!$"

