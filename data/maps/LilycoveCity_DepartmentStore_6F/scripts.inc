LilycoveCity_DepartmentStore_6F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_6F_EventScript_ClerkTopLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_6F_Pokemart1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_6F_Pokemart1:
	.2byte ITEM_HEALTH_FEATHER
	.2byte ITEM_MUSCLE_FEATHER
	.2byte ITEM_RESIST_FEATHER
	.2byte ITEM_GENIUS_FEATHER
	.2byte ITEM_CLEVER_FEATHER
	.2byte ITEM_SWIFT_FEATHER
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_HEALTH_BOTTLE_CAP
	.2byte ITEM_MUSCLE_BOTTLE_CAP
	.2byte ITEM_RESIST_BOTTLE_CAP
	.2byte ITEM_GENIUS_BOTTLE_CAP
	.2byte ITEM_CLEVER_BOTTLE_CAP
	.2byte ITEM_SWIFT_BOTTLE_CAP
	.2byte ITEM_GOLD_BOTTLE_CAP
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_6F_EventScript_ClerkTopRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_6F_Pokemart2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_6F_Pokemart2:
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_LINKING_CORD
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_UPGRADE
	.2byte ITEM_PROTECTOR
	.2byte ITEM_ELECTIRIZER
	.2byte ITEM_MAGMARIZER
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_REAPER_CLOTH
	.2byte ITEM_RAZOR_FANG
	.2byte ITEM_RAZOR_CLAW
	.2byte ITEM_PRISM_SCALE
	.2byte ITEM_WHIPPED_DREAM
	.2byte ITEM_SACHET
	.2byte ITEM_OVAL_STONE
	.2byte ITEM_RED_NECTAR
	.2byte ITEM_YELLOW_NECTAR
	.2byte ITEM_PINK_NECTAR
	.2byte ITEM_PURPLE_NECTAR
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_6F_EventScript_ClerkBottomLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_6F_Pokemart3
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_6F_Pokemart3:
	.2byte ITEM_VENUSAURITE
	.2byte ITEM_CHARIZARDITE_X
	.2byte ITEM_CHARIZARDITE_Y
	.2byte ITEM_BLASTOISINITE
	.2byte ITEM_BEEDRILLITE
	.2byte ITEM_PIDGEOTITE
	.2byte ITEM_ALAKAZITE
	.2byte ITEM_SLOWBRONITE
	.2byte ITEM_GENGARITE
	.2byte ITEM_KANGASKHANITE
	.2byte ITEM_PINSIRITE
	.2byte ITEM_GYARADOSITE
	.2byte ITEM_AERODACTYLITE
	.2byte ITEM_MEWTWONITE_X
	.2byte ITEM_MEWTWONITE_Y
	.2byte ITEM_AMPHAROSITE
	.2byte ITEM_STEELIXITE
	.2byte ITEM_SCIZORITE
	.2byte ITEM_HERACRONITE
	.2byte ITEM_HOUNDOOMINITE
	.2byte ITEM_TYRANITARITE
	.2byte ITEM_SCEPTILITE
	.2byte ITEM_BLAZIKENITE
	.2byte ITEM_SWAMPERTITE
	.2byte ITEM_GARDEVOIRITE
	.2byte ITEM_SABLENITE
	.2byte ITEM_MAWILITE
	.2byte ITEM_AGGRONITE
	.2byte ITEM_MEDICHAMITE
	.2byte ITEM_MANECTITE
	.2byte ITEM_SHARPEDONITE
	.2byte ITEM_CAMERUPTITE
	.2byte ITEM_ALTARIANITE
	.2byte ITEM_BANETTITE
	.2byte ITEM_ABSOLITE
	.2byte ITEM_GLALITITE
	.2byte ITEM_SALAMENCITE
	.2byte ITEM_METAGROSSITE
	.2byte ITEM_LATIASITE
	.2byte ITEM_LATIOSITE
	.2byte ITEM_LOPUNNITE
	.2byte ITEM_GARCHOMPITE
	.2byte ITEM_LUCARIONITE
	.2byte ITEM_ABOMASITE
	.2byte ITEM_GALLADITE
	.2byte ITEM_AUDINITE
	.2byte ITEM_DIANCITE
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_6F_EventScript_ClerkBottomRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_6F_Pokemart4
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_6F_Pokemart4:
	.2byte ITEM_NORMALIUM_Z
	.2byte ITEM_FIRIUM_Z
	.2byte ITEM_WATERIUM_Z
	.2byte ITEM_ELECTRIUM_Z
	.2byte ITEM_GRASSIUM_Z
	.2byte ITEM_ICIUM_Z
	.2byte ITEM_FIGHTINIUM_Z
	.2byte ITEM_POISONIUM_Z
	.2byte ITEM_GROUNDIUM_Z
	.2byte ITEM_FLYINIUM_Z
	.2byte ITEM_PSYCHIUM_Z
	.2byte ITEM_BUGINIUM_Z
	.2byte ITEM_ROCKIUM_Z
	.2byte ITEM_GHOSTIUM_Z
	.2byte ITEM_DRAGONIUM_Z
	.2byte ITEM_DARKINIUM_Z
	.2byte ITEM_STEELIUM_Z
	.2byte ITEM_FAIRIUM_Z
	.2byte ITEM_PIKANIUM_Z
	.2byte ITEM_EEVIUM_Z
	.2byte ITEM_SNORLIUM_Z
	.2byte ITEM_MEWNIUM_Z
	.2byte ITEM_DECIDIUM_Z
	.2byte ITEM_INCINIUM_Z
	.2byte ITEM_PRIMARIUM_Z
	.2byte ITEM_LYCANIUM_Z
	.2byte ITEM_MIMIKIUM_Z
	.2byte ITEM_KOMMONIUM_Z
	.2byte ITEM_TAPUNIUM_Z
	.2byte ITEM_SOLGANIUM_Z
	.2byte ITEM_LUNALIUM_Z
	.2byte ITEM_MARSHADIUM_Z
	.2byte ITEM_ALORAICHIUM_Z
	.2byte ITEM_PIKASHUNIUM_Z
	.2byte ITEM_ULTRANECROZIUM_Z
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_6F_EventScript_ClerkMint::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_6F_Pokemart5
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_6F_Pokemart5:
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_MILD_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_QUIET_MINT
	.2byte ITEM_CALM_MINT
	.2byte ITEM_GENTLE_MINT
	.2byte ITEM_CAREFUL_MINT
	.2byte ITEM_SASSY_MINT
	.2byte ITEM_TIMID_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_NAIVE_MINT
	.2byte ITEM_SERIOUS_MINT
	.2byte ITEM_NONE
	release
	end
