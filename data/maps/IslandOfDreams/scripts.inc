IslandOfDreams_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, IslandOfDreams_Top_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, IslandOfDreams_Top_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, IslandOfDreams_Top_OnWarp
	.byte 0

IslandOfDreams_Top_OnResume::
	goto_if_set FLAG_DREAM_STATE, IslandOfDreams_EventScript_PrepareCresselia
	goto_if_unset FLAG_DREAM_STATE, IslandOfDreams_EventScript_PrepareDarkrai
	end

IslandOfDreams_Top_OnTransition::
	goto_if_set FLAG_DREAM_STATE, IslandOfDreams_EventScript_PrepareCresselia
	goto_if_unset FLAG_DREAM_STATE, IslandOfDreams_EventScript_PrepareDarkrai
	end

IslandOfDreams_Top_OnWarp::
	goto_if_set FLAG_DREAM_STATE, IslandOfDreams_EventScript_PrepareCresselia
	goto_if_unset FLAG_DREAM_STATE, IslandOfDreams_EventScript_PrepareDarkrai
	end

IslandOfDreams_EventScript_PrepareCresselia::
	setflag FLAG_HIDE_DARKRAI
	clearflag FLAG_HIDE_CRESSELIA
	end

IslandOfDreams_EventScript_CresseliaBattle::
	lockall
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_CRESSELIA, 50, ITEM_FAIRY_GEM
	special BattleSetup_StartLegendaryBattle
	waitstate
	goto IslandOfDreams_EventScript_PostCresseliaBattle
	releaseall
	end

IslandOfDreams_EventScript_PostCresseliaBattle::
	fadescreen FADE_TO_BLACK
	removeobject 2
	setflag FLAG_HIDE_CRESSELIA
	setflag FLAG_CAUGHT_CRESSELIA
	fadescreen FADE_FROM_BLACK
	fadescreen FADE_TO_BLACK
	warp MAP_SLATEPORT_CITY_NAME_RATERS_HOUSE, 2
	end

IslandOfDreams_EventScript_PrepareDarkrai::
	setflag FLAG_HIDE_CRESSELIA
	clearflag FLAG_HIDE_DARKRAI
	end

IslandOfDreams_EventScript_DarkraiBattle::
	lockall
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_DARKRAI, 50, ITEM_DARK_GEM
	special BattleSetup_StartLegendaryBattle
	waitstate
	goto IslandOfDreams_EventScript_PostDarkraiBattle
	releaseall
	end

IslandOfDreams_EventScript_PostDarkraiBattle::
	fadescreen FADE_TO_BLACK
	removeobject 1
	setflag FLAG_HIDE_DARKRAI
	setflag FLAG_CAUGHT_DARKRAI
	fadescreen FADE_FROM_BLACK
	fadescreen FADE_TO_BLACK
	warp MAP_SLATEPORT_CITY_NAME_RATERS_HOUSE, 2
	end
