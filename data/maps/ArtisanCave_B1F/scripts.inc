ArtisanCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ArtisanCave_B1F_OnTransition
	.byte 0

ArtisanCave_B1F_OnTransition:
	setflag FLAG_LANDMARK_ARTISAN_CAVE
	end

ArtisanCave_B1F_EventScript_GiveJawFossil::
	giveitem ITEM_JAW_FOSSIL
	removeobject 2
	setflag FLAG_HIDE_JAW
	release
	end
