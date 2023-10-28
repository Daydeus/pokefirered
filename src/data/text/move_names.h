const u8 gMoveNames[MOVES_COUNT][MOVE_NAME_LENGTH + 1] = {
    [MOVE_NONE]          = _("-$$$$$$"),
    [MOVE_ABSORB]        = _("ABSORB"),
    [MOVE_ACID]          = _("ACID"),
    [MOVE_ACID_ARMOR]    = _("ACID ARMOR"),
    [MOVE_AERIAL_ACE]    = _("AERIAL ACE"),
    [MOVE_AEROBLAST]     = _("AEROBLAST"),
    [MOVE_AGILITY]       = _("AGILITY"),
    [MOVE_AIR_CUTTER]    = _("AIR CUTTER"),
    [MOVE_AMNESIA]       = _("AMNESIA"),
    [MOVE_ANCIENT_POWER] = _("ANCIENTPOWER"),
    [MOVE_ARM_THRUST]    = _("ARM THRUST"),
    [MOVE_AROMATHERAPY]  = _("AROMATHERAPY"),
    [MOVE_ASSIST]        = _("ASSIST"),
    [MOVE_ASTONISH]      = _("ASTONISH"),
    [MOVE_ATTRACT]       = _("ATTRACT"),
    [MOVE_AURORA_BEAM]   = _("AURORA BEAM"),
    [MOVE_BARRAGE]       = _("BARRAGE"),
    [MOVE_BARRIER]       = _("BARRIER"),
    [MOVE_BATON_PASS]    = _("BATON PASS"),
    [MOVE_BEAT_UP]       = _("BEAT UP"),
    [MOVE_BELLY_DRUM]    = _("BELLY DRUM"),
    [MOVE_BIDE]          = _("BIDE"),
    [MOVE_BIND]          = _("BIND"),
    [MOVE_BITE]          = _("BITE"),
    [MOVE_BLAST_BURN]    = _("BLAST BURN"),
    [MOVE_BLAZE_KICK]    = _("BLAZE KICK"),
    [MOVE_BLIZZARD]      = _("BLIZZARD"),
    [MOVE_BLOCK]         = _("BLOCK"),
    [MOVE_BODY_SLAM]     = _("BODY SLAM"),
    [MOVE_BONEMERANG]    = _("BONEMERANG"),
    [MOVE_BONE_CLUB]     = _("BONE CLUB"),
    [MOVE_BONE_RUSH]     = _("BONE RUSH"),
    [MOVE_BOUNCE]        = _("BOUNCE"),
    [MOVE_BRICK_BREAK]   = _("BRICK BREAK"),
    [MOVE_BUBBLE]        = _("BUBBLE"),
    [MOVE_BUBBLE_BEAM]   = _("BUBBLEBEAM"),
    [MOVE_BULK_UP]       = _("BULK UP"),
    [MOVE_BULLET_SEED]   = _("BULLET SEED"),
    [MOVE_CALM_MIND]     = _("CALM MIND"),
    [MOVE_CAMOUFLAGE]    = _("CAMOUFLAGE"),
    [MOVE_CHARGE]        = _("CHARGE"),
    [MOVE_CHARM]         = _("CHARM"),
    [MOVE_CLAMP]         = _("CLAMP"),
    [MOVE_COMET_PUNCH]   = _("COMET PUNCH"),
    [MOVE_CONFUSE_RAY]   = _("CONFUSE RAY"),
    [MOVE_CONFUSION]     = _("CONFUSION"),
    [MOVE_CONSTRICT]     = _("CONSTRICT"),
    [MOVE_CONVERSION]    = _("CONVERSION"),
    [MOVE_CONVERSION_2]  = _("CONVERSION 2"),
    [MOVE_COSMIC_POWER]  = _("COSMIC POWER"),
    [MOVE_COTTON_SPORE]  = _("COTTON SPORE"),
    [MOVE_COUNTER]       = _("COUNTER"),
    [MOVE_COVET]         = _("COVET"),
    [MOVE_CRABHAMMER]    = _("CRABHAMMER"),
    [MOVE_CROSS_CHOP]    = _("CROSS CHOP"),
    [MOVE_CRUNCH]        = _("CRUNCH"),
    [MOVE_CRUSH_CLAW]    = _("CRUSH CLAW"),
    [MOVE_CURSE]         = _("CURSE"),
    [MOVE_CUT]           = _("CUT"),
    [MOVE_DEFENSE_CURL]  = _("DEFENSE CURL"),
    [MOVE_DESTINY_BOND]  = _("DESTINY BOND"),
    [MOVE_DETECT]        = _("DETECT"),
    [MOVE_DIG]           = _("DIG"),
    [MOVE_DISABLE]       = _("DISABLE"),
    [MOVE_DIVE]          = _("DIVE"),
    [MOVE_DIZZY_PUNCH]   = _("DIZZY PUNCH"),
    [MOVE_DOOM_DESIRE]   = _("DOOM DESIRE"),
    [MOVE_DOUBLE_EDGE]   = _("DOUBLE-EDGE"),
    [MOVE_DOUBLE_KICK]   = _("DOUBLE KICK"),
    [MOVE_DOUBLE_SLAP]   = _("DOUBLESLAP"),
    [MOVE_DOUBLE_TEAM]   = _("DOUBLE TEAM"),
    [MOVE_DRAGON_BREATH] = _("DRAGONBREATH"),
    [MOVE_DRAGON_CLAW]   = _("DRAGON CLAW"),
    [MOVE_DRAGON_DANCE]  = _("DRAGON DANCE"),
    [MOVE_DRAGON_RAGE]   = _("DRAGON RAGE"),
    [MOVE_DREAM_EATER]   = _("DREAM EATER"),
    [MOVE_DRILL_PECK]    = _("DRILL PECK"),
    [MOVE_DRILL_RUN]     = _("DRILL RUN"),
    [MOVE_DYNAMIC_PUNCH] = _("DYNAMICPUNCH"),
    [MOVE_EARTHQUAKE]    = _("EARTHQUAKE"),
    [MOVE_EARTH_AURA]    = _("EARTH AURA"),
    [MOVE_EGG_BOMB]      = _("EGG BOMB"),
    [MOVE_EMBER]         = _("EMBER"),
    [MOVE_ENCORE]        = _("ENCORE"),
    [MOVE_ENDEAVOR]      = _("ENDEAVOR"),
    [MOVE_ENDURE]        = _("ENDURE"),
    [MOVE_ERUPTION]      = _("ERUPTION"),
    [MOVE_EXPLOSION]     = _("EXPLOSION"),
    [MOVE_EXTRASENSORY]  = _("EXTRASENSORY"),
    [MOVE_EXTREME_SPEED] = _("EXTREMESPEED"),
    [MOVE_FACADE]        = _("FACADE"),
    [MOVE_FAINT_ATTACK]  = _("FAINT ATTACK"),
    [MOVE_FAKE_OUT]      = _("FAKE OUT"),
    [MOVE_FAKE_TEARS]    = _("FAKE TEARS"),
    [MOVE_FALSE_SWIPE]   = _("FALSE SWIPE"),
    [MOVE_FEATHER_DANCE] = _("FEATHERDANCE"),
    [MOVE_FIRE_BLAST]    = _("FIRE BLAST"),
    [MOVE_FIRE_PUNCH]    = _("FIRE PUNCH"),
    [MOVE_FIRE_SPIN]     = _("FIRE SPIN"),
    [MOVE_FISSURE]       = _("FISSURE"),
    [MOVE_FLAIL]         = _("FLAIL"),
    [MOVE_FLAMETHROWER]  = _("FLAMETHROWER"),
    [MOVE_FLAME_WHEEL]   = _("FLAME WHEEL"),
    [MOVE_FLASH]         = _("FLASH"),
    [MOVE_FLATTER]       = _("FLATTER"),
    [MOVE_FLY]           = _("FLY"),
    [MOVE_FOCUS_ENERGY]  = _("FOCUS ENERGY"),
    [MOVE_FOCUS_PUNCH]   = _("FOCUS PUNCH"),
    [MOVE_FOLLOW_ME]     = _("FOLLOW ME"),
    [MOVE_FORESIGHT]     = _("FORESIGHT"),
    [MOVE_FRENZY_PLANT]  = _("FRENZY PLANT"),
    [MOVE_FRUSTRATION]   = _("FRUSTRATION"),
    [MOVE_FURY_ATTACK]   = _("FURY ATTACK"),
    [MOVE_FURY_CUTTER]   = _("FURY CUTTER"),
    [MOVE_FURY_SWIPES]   = _("FURY SWIPES"),
    [MOVE_FUTURE_SIGHT]  = _("FUTURE SIGHT"),
    [MOVE_GIGA_DRAIN]    = _("GIGA DRAIN"),
    [MOVE_GLARE]         = _("GLARE"),
    [MOVE_GRASS_WHISTLE] = _("GRASSWHISTLE"),
    [MOVE_GROWL]         = _("GROWL"),
    [MOVE_GROWTH]        = _("GROWTH"),
    [MOVE_GRUDGE]        = _("GRUDGE"),
    [MOVE_GUILLOTINE]    = _("GUILLOTINE"),
    [MOVE_GUST]          = _("GUST"),
    [MOVE_HAIL]          = _("HAIL"),
    [MOVE_HARDEN]        = _("HARDEN"),
    [MOVE_HAZE]          = _("HAZE"),
    [MOVE_HEADBUTT]      = _("HEADBUTT"),
    [MOVE_HEAL_BELL]     = _("HEAL BELL"),
    [MOVE_HEAT_WAVE]     = _("HEAT WAVE"),
    [MOVE_HELPING_HAND]  = _("HELPING HAND"),
    [MOVE_HIDDEN_POWER]  = _("HIDDEN POWER"),
    [MOVE_HI_JUMP_KICK]  = _("HI JUMP KICK"),
    [MOVE_HORN_ATTACK]   = _("HORN ATTACK"),
    [MOVE_HORN_DRILL]    = _("HORN DRILL"),
    [MOVE_HOWL]          = _("HOWL"),
    [MOVE_HYDRO_CANNON]  = _("HYDRO CANNON"),
    [MOVE_HYDRO_PUMP]    = _("HYDRO PUMP"),
    [MOVE_HYPER_BEAM]    = _("HYPER BEAM"),
    [MOVE_HYPER_FANG]    = _("HYPER FANG"),
    [MOVE_HYPER_VOICE]   = _("HYPER VOICE"),
    [MOVE_HYPNOSIS]      = _("HYPNOSIS"),
    [MOVE_ICE_BALL]      = _("ICE BALL"),
    [MOVE_ICE_BEAM]      = _("ICE BEAM"),
    [MOVE_ICE_PUNCH]     = _("ICE PUNCH"),
    [MOVE_ICICLE_SPEAR]  = _("ICICLE SPEAR"),
    [MOVE_ICY_WIND]      = _("ICY WIND"),
    [MOVE_IMPRISON]      = _("IMPRISON"),
    [MOVE_INFESTATION]   = _("INFESTATION"),
    [MOVE_INGRAIN]       = _("INGRAIN"),
    [MOVE_IRON_DEFENSE]  = _("IRON DEFENSE"),
    [MOVE_IRON_TAIL]     = _("IRON TAIL"),
    [MOVE_JUMP_KICK]     = _("JUMP KICK"),
    [MOVE_KARATE_CHOP]   = _("KARATE CHOP"),
    [MOVE_KINESIS]       = _("KINESIS"),
    [MOVE_KNOCK_OFF]     = _("KNOCK OFF"),
    [MOVE_LEAF_BLADE]    = _("LEAF BLADE"),
    [MOVE_LEECH_LIFE]    = _("LEECH LIFE"),
    [MOVE_LEECH_SEED]    = _("LEECH SEED"),
    [MOVE_LEER]          = _("LEER"),
    [MOVE_LICK]          = _("LICK"),
    [MOVE_LIGHT_SCREEN]  = _("LIGHT SCREEN"),
    [MOVE_LOCK_ON]       = _("LOCK-ON"),
    [MOVE_LOVELY_KISS]   = _("LOVELY KISS"),
    [MOVE_LOW_KICK]      = _("LOW KICK"),
    [MOVE_LUSTER_PURGE]  = _("LUSTER PURGE"),
    [MOVE_MACH_PUNCH]    = _("MACH PUNCH"),
    [MOVE_MAGICAL_LEAF]  = _("MAGICAL LEAF"),
    [MOVE_MAGIC_COAT]    = _("MAGIC COAT"),
    [MOVE_MAGNITUDE]     = _("MAGNITUDE"),
    [MOVE_MEAN_LOOK]     = _("MEAN LOOK"),
    [MOVE_MEDITATE]      = _("MEDITATE"),
    [MOVE_MEGAHORN]      = _("MEGAHORN"),
    [MOVE_MEGA_DRAIN]    = _("MEGA DRAIN"),
    [MOVE_MEGA_KICK]     = _("MEGA KICK"),
    [MOVE_MEGA_PUNCH]    = _("MEGA PUNCH"),
    [MOVE_MEMENTO]       = _("MEMENTO"),
    [MOVE_METAL_CLAW]    = _("METAL CLAW"),
    [MOVE_METAL_SOUND]   = _("METAL SOUND"),
    [MOVE_METEOR_MASH]   = _("METEOR MASH"),
    [MOVE_METRONOME]     = _("METRONOME"),
    [MOVE_MILK_DRINK]    = _("MILK DRINK"),
    [MOVE_MIMIC]         = _("MIMIC"),
    [MOVE_MIND_READER]   = _("MIND READER"),
    [MOVE_MINIMIZE]      = _("MINIMIZE"),
    [MOVE_MIRROR_COAT]   = _("MIRROR COAT"),
    [MOVE_MIRROR_MOVE]   = _("MIRROR MOVE"),
    [MOVE_MIST]          = _("MIST"),
    [MOVE_MIST_BALL]     = _("MIST BALL"),
    [MOVE_MOONLIGHT]     = _("MOONLIGHT"),
    [MOVE_MORNING_SUN]   = _("MORNING SUN"),
    [MOVE_MUDDY_WATER]   = _("MUDDY WATER"),
    [MOVE_MUD_BOMB]      = _("MUD BOMB"),
    [MOVE_MUD_SHOT]      = _("MUD SHOT"),
    [MOVE_MUD_SLAP]      = _("MUD-SLAP"),
    [MOVE_MUD_SPORT]     = _("MUD SPORT"),
    [MOVE_NATURE_POWER]  = _("NATURE POWER"),
    [MOVE_NEEDLE_ARM]    = _("NEEDLE ARM"),
    [MOVE_NIGHTMARE]     = _("NIGHTMARE"),
    [MOVE_NIGHT_SHADE]   = _("NIGHT SHADE"),
    [MOVE_OCTAZOOKA]     = _("OCTAZOOKA"),
    [MOVE_ODOR_SLEUTH]   = _("ODOR SLEUTH"),
    [MOVE_OUTRAGE]       = _("OUTRAGE"),
    [MOVE_OVERHEAT]      = _("OVERHEAT"),
    [MOVE_PAIN_SPLIT]    = _("PAIN SPLIT"),
    [MOVE_PAY_DAY]       = _("PAY DAY"),
    [MOVE_PECK]          = _("PECK"),
    [MOVE_PERISH_SONG]   = _("PERISH SONG"),
    [MOVE_PETAL_DANCE]   = _("PETAL DANCE"),
    [MOVE_PIN_MISSILE]   = _("PIN MISSILE"),
    [MOVE_POISON_FANG]   = _("POISON FANG"),
    [MOVE_POISON_GAS]    = _("POISON GAS"),
    [MOVE_POISON_POWDER] = _("POISONPOWDER"),
    [MOVE_POISON_STING]  = _("POISON STING"),
    [MOVE_POISON_TAIL]   = _("POISON TAIL"),
    [MOVE_POUND]         = _("POUND"),
    [MOVE_POWDER_SNOW]   = _("POWDER SNOW"),
    [MOVE_PRESENT]       = _("PRESENT"),
    [MOVE_PROTECT]       = _("PROTECT"),
    [MOVE_PSYBEAM]       = _("PSYBEAM"),
    [MOVE_PSYCHIC]       = _("PSYCHIC"),
    [MOVE_PSYCHO_BOOST]  = _("PSYCHO BOOST"),
    [MOVE_PSYCH_UP]      = _("PSYCH UP"),
    [MOVE_PSYWAVE]       = _("PSYWAVE"),
    [MOVE_PURSUIT]       = _("PURSUIT"),
    [MOVE_QUICK_ATTACK]  = _("QUICK ATTACK"),
    [MOVE_RAGE]          = _("RAGE"),
    [MOVE_RAGE_POWDER]   = _("RAGE POWDER"),
    [MOVE_RAIN_DANCE]    = _("RAIN DANCE"),
    [MOVE_RAPID_SPIN]    = _("RAPID SPIN"),
    [MOVE_RAZOR_LEAF]    = _("RAZOR LEAF"),
    [MOVE_RAZOR_WIND]    = _("RAZOR WIND"),
    [MOVE_RECOVER]       = _("RECOVER"),
    [MOVE_RECYCLE]       = _("RECYCLE"),
    [MOVE_REFLECT]       = _("REFLECT"),
    [MOVE_REFRESH]       = _("REFRESH"),
    [MOVE_REST]          = _("REST"),
    [MOVE_RETURN]        = _("RETURN"),
    [MOVE_REVENGE]       = _("REVENGE"),
    [MOVE_REVERSAL]      = _("REVERSAL"),
    [MOVE_ROAR]          = _("ROAR"),
    [MOVE_ROCK_BLAST]    = _("ROCK BLAST"),
    [MOVE_ROCK_SLIDE]    = _("ROCK SLIDE"),
    [MOVE_ROCK_SMASH]    = _("ROCK SMASH"),
    [MOVE_ROCK_THROW]    = _("ROCK THROW"),
    [MOVE_ROCK_TOMB]     = _("ROCK TOMB"),
    [MOVE_ROLE_PLAY]     = _("ROLE PLAY"),
    [MOVE_ROLLING_KICK]  = _("ROLLING KICK"),
    [MOVE_ROLLOUT]       = _("ROLLOUT"),
    [MOVE_SACRED_FIRE]   = _("SACRED FIRE"),
    [MOVE_SAFEGUARD]     = _("SAFEGUARD"),
    [MOVE_SANDSTORM]     = _("SANDSTORM"),
    [MOVE_SAND_ATTACK]   = _("SAND-ATTACK"),
    [MOVE_SAND_TOMB]     = _("SAND TOMB"),
    [MOVE_SCARY_FACE]    = _("SCARY FACE"),
    [MOVE_SCRATCH]       = _("SCRATCH"),
    [MOVE_SCREECH]       = _("SCREECH"),
    [MOVE_SECRET_POWER]  = _("SECRET POWER"),
    [MOVE_SEISMIC_TOSS]  = _("SEISMIC TOSS"),
    [MOVE_SELF_DESTRUCT] = _("SELFDESTRUCT"),
    [MOVE_SHADOW_BALL]   = _("SHADOW BALL"),
    [MOVE_SHADOW_PUNCH]  = _("SHADOW PUNCH"),
    [MOVE_SHARPEN]       = _("SHARPEN"),
    [MOVE_SHEER_COLD]    = _("SHEER COLD"),
    [MOVE_SHOCK_WAVE]    = _("SHOCK WAVE"),
    [MOVE_SIGNAL_BEAM]   = _("SIGNAL BEAM"),
    [MOVE_SILVER_WIND]   = _("SILVER WIND"),
    [MOVE_SING]          = _("SING"),
    [MOVE_SKETCH]        = _("SKETCH"),
    [MOVE_SKILL_SWAP]    = _("SKILL SWAP"),
    [MOVE_SKULL_BASH]    = _("SKULL BASH"),
    [MOVE_SKY_ATTACK]    = _("SKY ATTACK"),
    [MOVE_SKY_UPPERCUT]  = _("SKY UPPERCUT"),
    [MOVE_SLACK_OFF]     = _("SLACK OFF"),
    [MOVE_SLAM]          = _("SLAM"),
    [MOVE_SLASH]         = _("SLASH"),
    [MOVE_SLEEP_POWDER]  = _("SLEEP POWDER"),
    [MOVE_SLEEP_TALK]    = _("SLEEP TALK"),
    [MOVE_SLUDGE]        = _("SLUDGE"),
    [MOVE_SLUDGE_BOMB]   = _("SLUDGE BOMB"),
    [MOVE_SMELLING_SALT] = _("SMELLINGSALT"),
    [MOVE_SMOG]          = _("SMOG"),
    [MOVE_SMOKESCREEN]   = _("SMOKESCREEN"),
    [MOVE_SNATCH]        = _("SNATCH"),
    [MOVE_SNORE]         = _("SNORE"),
    [MOVE_SOFT_BOILED]   = _("SOFTBOILED"),
    [MOVE_SOLAR_BEAM]    = _("SOLARBEAM"),
    [MOVE_SONIC_BOOM]    = _("SONICBOOM"),
    [MOVE_SPARK]         = _("SPARK"),
    [MOVE_SPIDER_WEB]    = _("SPIDER WEB"),
    [MOVE_SPIKES]        = _("SPIKES"),
    [MOVE_SPIKE_CANNON]  = _("SPIKE CANNON"),
    [MOVE_SPITE]         = _("SPITE"),
    [MOVE_SPIT_UP]       = _("SPIT UP"),
    [MOVE_SPLASH]        = _("SPLASH"),
    [MOVE_SPORE]         = _("SPORE"),
    [MOVE_STEEL_WING]    = _("STEEL WING"),
    [MOVE_STOCKPILE]     = _("STOCKPILE"),
    [MOVE_STOMP]         = _("STOMP"),
    [MOVE_STRENGTH]      = _("STRENGTH"),
    [MOVE_STRING_SHOT]   = _("STRING SHOT"),
    [MOVE_STRUGGLE]      = _("STRUGGLE"),
    [MOVE_STRUGGLE_BUG]  = _("STRUGGLE BUG"),
    [MOVE_STUN_SPORE]    = _("STUN SPORE"),
    [MOVE_SUBMISSION]    = _("SUBMISSION"),
    [MOVE_SUBSTITUTE]    = _("SUBSTITUTE"),
    [MOVE_SUNNY_DAY]     = _("SUNNY DAY"),
    [MOVE_SUPERPOWER]    = _("SUPERPOWER"),
    [MOVE_SUPERSONIC]    = _("SUPERSONIC"),
    [MOVE_SUPER_FANG]    = _("SUPER FANG"),
    [MOVE_SURF]          = _("SURF"),
    [MOVE_SWAGGER]       = _("SWAGGER"),
    [MOVE_SWALLOW]       = _("SWALLOW"),
    [MOVE_SWEET_KISS]    = _("SWEET KISS"),
    [MOVE_SWEET_SCENT]   = _("SWEET SCENT"),
    [MOVE_SWIFT]         = _("SWIFT"),
    [MOVE_SWORDS_DANCE]  = _("SWORDS DANCE"),
    [MOVE_SYNTHESIS]     = _("SYNTHESIS"),
    [MOVE_TACKLE]        = _("TACKLE"),
    [MOVE_TAIL_GLOW]     = _("TAIL GLOW"),
    [MOVE_TAIL_WHIP]     = _("TAIL WHIP"),
    [MOVE_TAKE_DOWN]     = _("TAKE DOWN"),
    [MOVE_TAUNT]         = _("TAUNT"),
    [MOVE_TEETER_DANCE]  = _("TEETER DANCE"),
    [MOVE_TELEPORT]      = _("TELEPORT"),
    [MOVE_THIEF]         = _("THIEF"),
    [MOVE_THRASH]        = _("THRASH"),
    [MOVE_THUNDERBOLT]   = _("THUNDERBOLT"),
    [MOVE_THUNDER]       = _("THUNDER"),
    [MOVE_THUNDER_PUNCH] = _("THUNDERPUNCH"),
    [MOVE_THUNDER_SHOCK] = _("THUNDERSHOCK"),
    [MOVE_THUNDER_WAVE]  = _("THUNDER WAVE"),
    [MOVE_TICKLE]        = _("TICKLE"),
    [MOVE_TORMENT]       = _("TORMENT"),
    [MOVE_TOXIC]         = _("TOXIC"),
    [MOVE_TRANSFORM]     = _("TRANSFORM"),
    [MOVE_TRICK]         = _("TRICK"),
    [MOVE_TRIPLE_KICK]   = _("TRIPLE KICK"),
    [MOVE_TRI_ATTACK]    = _("TRI ATTACK"),
    [MOVE_TWINEEDLE]     = _("TWINEEDLE"),
    [MOVE_TWISTER]       = _("TWISTER"),
    [MOVE_UPROAR]        = _("UPROAR"),
    [MOVE_U_TURN]        = _("U-TURN"),
    [MOVE_VICE_GRIP]     = _("VICEGRIP"),
    [MOVE_VINE_WHIP]     = _("VINE WHIP"),
    [MOVE_VITAL_THROW]   = _("VITAL THROW"),
    [MOVE_VOLT_TACKLE]   = _("VOLT TACKLE"),
    [MOVE_WATERFALL]     = _("WATERFALL"),
    [MOVE_WATER_GUN]     = _("WATER GUN"),
    [MOVE_WATER_PULSE]   = _("WATER PULSE"),
    [MOVE_WATER_SPORT]   = _("WATER SPORT"),
    [MOVE_WATER_SPOUT]   = _("WATER SPOUT"),
    [MOVE_WEATHER_BALL]  = _("WEATHER BALL"),
    [MOVE_WHIRLPOOL]     = _("WHIRLPOOL"),
    [MOVE_WHIRLWIND]     = _("WHIRLWIND"),
    [MOVE_WILL_O_WISP]   = _("WILL-O-WISP"),
    [MOVE_WING_ATTACK]   = _("WING ATTACK"),
    [MOVE_WISH]          = _("WISH"),
    [MOVE_WITHDRAW]      = _("WITHDRAW"),
    [MOVE_WRAP]          = _("WRAP"),
    [MOVE_X_SCISSOR]     = _("X-SCISSOR"),
    [MOVE_YAWN]          = _("YAWN"),
    [MOVE_ZAP_CANNON]    = _("ZAP CANNON")
};
