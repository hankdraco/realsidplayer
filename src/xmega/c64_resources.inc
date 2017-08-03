/*
* c64_resources.inc
*
*  Created: 2017-03-27 20:06:00
*   Author: Łukasz 'Hank' Drzewiecki
*/ 
 
	//#define _silence_

/* 1 time per frame */
	#define mitch_and_dane_dazzler
	//#define pri_show_must_go_on
	//#define blues_muz_nothing_else_matters
	//#define orcan_tchernobyls_tears
	//#define orcan_schizofrenia
	//#define dane_unisexual
	//#define shogoon_muminki
	//#define jeff_experiment
	//#define vincenzo_compozak
	//#define shogoon_altered_states
	//#define mhd_destruction
	//#define daf_opium1
	//#define daf_opium2
	//#define drax_boneless
	//#define kb_2nd_reality_part_4
	//#define dane_orbital

	//#define hank_hotstyle
	//#define hank_crystaldream
	//#define hank_nomore
	//#define hank_my8580
	//#define hank_ziolo
	//#define hank_activezone
	//#define hank_blueflower
	//#define hank_shorttrack
 
/* 2 times per frame */
	//#define red_devil_for_avantgarde
	//#define amj_blasphemy
	//#define wayne_power_of_magic

/* 4 times per frame */
	//#define shogoon_inflexion

/* 8 times per frame */
	//#define grg_grg_in_cyberspace
	
	/* Edit and uncomment this block
		#define your_new_zak_define			// <- define an in-code label for your new zak
	*/

	c64_code:
	#ifdef TEST
		.include "debug\c64_tests.c64bin.inc"
	#else

		#if defined(_silence_) || defined(mitch_and_dane_dazzler) || defined(orcan_schizofrenia) || defined(dane_unisexual) || defined(shogoon_muminki) || defined(jeff_experiment) || defined(vincenzo_compozak) || defined(shogoon_altered_states) || defined(pri_show_must_go_on) || defined(mhd_destruction) || defined(daf_opium1) || defined(daf_opium2) || defined(hank_hotstyle) || defined(hank_crystaldream) || defined(hank_nomore) || defined(hank_my8580) || defined(hank_ziolo) || defined(hank_activezone) || defined(hank_blueflower) || defined(hank_shorttrack) || defined(drax_boneless) || defined(kb_2nd_reality_part_4) || defined(blues_muz_nothing_else_matters) || defined(dane_orbital) || defined(orcan_tchernobyls_tears)
			.include "debug\c64_plr_1000_1.c64bin.inc"		// 1x 

		#elif defined(red_devil_for_avantgarde) || defined (wayne_power_of_magic) || defined(amj_blasphemy)
			.include "debug\c64_plr_1000_2.c64bin.inc"		// 2x

		#elif defined(shogoon_inflexion)
			.include "debug\c64_plr_1000_4.c64bin.inc"		// 4x


		#elif defined(grg_grg_in_cyberspace)
			.include "debug\c64_plr_1000_grgincyberspace.c64bin.inc"	// special case of player

		/* Edit and uncomment this block
			#elif defined(your_new_zak_define)
				.include "debug\c64_plr_1000_[speed].c64bin.inc"		// <- where [speed] is 1, 2 or 4, depending on how many times per frame is your newly added zak
		*/
			
		#endif
 
	#endif
c64_code_end:

zak_code:
	#ifndef TEST

		#if defined(_silence_)
			.db 0x60, 0, 0, 0x60							// silence

		#elif defined(mitch_and_dane_dazzler)
			.include "zaks/mitch_and_dane_dazzler.sid.inc"
		#elif defined(orcan_schizofrenia)
			.include "zaks/orcan_schizofrenia.sid.inc"
		#elif defined(orcan_tchernobyls_tears)
			.include "zaks/orcan_tchernobyls_tears.sid.inc"
		#elif defined(dane_unisexual)
			.include "zaks/dane_unisexual.sid.inc"
		#elif defined(shogoon_muminki)
			.include "zaks/shogoon_muminki.sid.inc"
		#elif defined(jeff_experiment)
			.include "zaks/jeff_experiment.sid.inc"
		#elif defined(vincenzo_compozak)
			.include "zaks/vincenzo_compozak.sid.inc"
		#elif defined(shogoon_altered_states)
			.include "zaks/shogoon_altered_states.sid.inc"
		#elif defined(pri_show_must_go_on)
			.include "zaks/pri_show_must_go_on.sid.inc"
		#elif defined(mhd_destruction)
			.include "zaks/mhd_destruction.sid.inc"
		#elif defined(daf_opium1)
			.include "zaks/daf_opium1.sid.inc"
		#elif defined(daf_opium2)
			.include "zaks/daf_opium2.sid.inc"
		#elif defined(amj_blasphemy)
			.include "zaks/amj_blasphemy.sid.inc"
		#elif defined(drax_boneless)
			.include "zaks/drax_boneless.sid.inc"
		#elif defined(kb_2nd_reality_part_4)
			.include "zaks/kb_2nd_reality_part_4.sid.inc"
		#elif defined(blues_muz_nothing_else_matters)
			.include "zaks/blues_muz_nothing_else_matters.sid.inc"
		#elif defined(dane_orbital)
			.include "zaks/dane_orbital.sid.inc"

		#elif defined(red_devil_for_avantgarde)
			.include "zaks/red_devil_for_avantgarde.sid.inc"
		#elif defined(wayne_power_of_magic)
			.include "zaks/wayne_power_of_magic.sid.inc"
		#elif defined(shogoon_inflexion)
			.include "zaks/shogoon_inflexion.prg.inc"
		#elif defined(grg_grg_in_cyberspace)
			.include "zaks/grg_grg_in_cyberspace.sid.inc"

		#elif defined(hank_hotstyle)
			.include "zaks/hank_hotstyle.sid.inc"
		#elif defined(hank_crystaldream)
			.include "zaks/hank_crystaldream.sid.inc"
		#elif defined(hank_nomore)
			.include "zaks/hank_nomore.sid.inc"
		#elif defined(hank_my8580)
			.include "zaks/hank_my8580.sid.inc"
		#elif defined(hank_ziolo)
			.include "zaks/hank_ziolo.sid.inc"
		#elif defined(hank_activezone)
			.include "zaks/hank_activezone.sid.inc"
		#elif defined(hank_blueflower)
			.include "zaks/hank_blueflower.sid.inc"
		#elif defined(hank_shorttrack)
			.include "zaks/hank_shorttrack.sid.inc"
			
		/* Edit and uncomment this block
			#elif defined(your_new_zak_define)
				.include "zaks/your_new_zak.sid.inc"
		*/

		#endif
		
	#endif
zak_code_end: