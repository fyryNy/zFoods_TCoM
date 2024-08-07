// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	Dishes::Dishes() {
	}

	Dishes::MyMap Dishes::Data = {
	{"ITFO_PICKLEDBEET", {"meal_pickledbeet_checkbonus", "nob_checkmeal_pickledbeet", "mealname_pickledbeet", true}},
	{"ITFO_BEERBREAD", {"meal_beerbread_checkbonus", "nob_checkmeal_beerbread", "mealname_beerbread", true}},
	{"ITFO_PUMPKINCOMPOTE", {"meal_pumpkincompote_checkbonus", "nob_checkmeal_pumpkincompote", "mealname_pumpkincompote", true}},
	{"ITFO_HONEYCOOKIES", {"meal_honeycookies_checkbonus", "nob_checkmeal_honeycookies", "mealname_honeycookies", true}},
	{"ITFO_FRIEDFISHSKINS", {"meal_friedfishskins_checkbonus", "nob_checkmeal_friedfishskins", "mealname_friedfishskins", true}},
	{"ITFO_SCAVENGERSHASHLIK", {"meal_scavengershashlik_checkbonus", "nob_checkmeal_scavengershashlik", "mealname_scavengershashlik", true}},
	{"ITFO_ROASTEDINSECTS", {"meal_roastedinsects_checkbonus", "nob_checkmeal_roastedinsects", "mealname_roastedinsects", true}},
	{"ITFO_CABBAGESOUP", {"meal_cabbagesoup_checkbonus", "nob_checkmeal_cabbagesoup", "mealname_cabbagesoup", true}},
	{"ITFO_MUSHROOMCOTLET", {"meal_mushroomcotlet_checkbonus", "nob_checkmeal_mushroomcotlet", "mealname_mushroomcotlet", true}},
	{"ITFO_DRYFRUITCOMPOTE", {"meal_dryfruitcompote_checkbonus", "nob_checkmeal_dryfruitcompote", "mealname_dryfruitcompote", true}},
	{"ITFO_FISHVINEGAR", {"meal_fishvinegar_checkbonus", "nob_checkmeal_fishvinegar", "mealname_fishvinegar", true}},
	{"ITFO_MANAPERMSOUP", {"meal_manapermsoup_checkbonus", "nob_checkmeal_manapermsoup", "mealname_manapermsoup", false}},
	{"ITFO_SWEETBUN", {"meal_sweetbun_checkbonus", "nob_checkmeal_sweetbun", "mealname_sweetbun", true}},
	{"ITFO_MUSHROOMSOUP", {"meal_mushroomsoup_checkbonus", "nob_checkmeal_mushroomsoup", "mealname_mushroomsoup", true}},
	{"ITFO_RIVERMIRTSOUP", {"meal_rivermirtsoup_checkbonus", "nob_checkmeal_rivermirtsoup", "mealname_rivermirtsoup", true}},
	{"ITFO_SPEEDHERBOYSTERS", {"meal_speedherboysters_checkbonus", "nob_checkmeal_speedherboysters", "mealname_speedherboysters", true}},
	{"ITFO_BOARSTEW", {"meal_boarstew_checkbonus", "nob_checkmeal_boarstew", "mealname_boarstew", true}},
	{"ITFO_MEATMISHMASH", {"meal_meatmishmash_checkbonus", "nob_checkmeal_meatmishmash", "mealname_meatmishmash", true}},
	{"ITFO_RATSTICK", {"meal_ratstick_checkbonus", "nob_checkmeal_ratstick", "mealname_ratstick", true}},
	{"ITFO_MULLEDWISP", {"meal_mulledwisp_checkbonus", "nob_checkmeal_mulledwisp", "mealname_mulledwisp", true}},
	{"ITFO_FISHCOTLET", {"meal_fishcotlet_checkbonus", "nob_checkmeal_fishcotlet", "mealname_fishcotlet", true}},
	{"ITFO_FISHFILLETPERM", {"meal_fishfilletperm_checkbonus", "nob_checkmeal_fishfilletperm", "mealname_fishfilletperm", false}},
	{"ITFO_POORBROTH", {"meal_poorbroth_checkbonus", "nob_checkmeal_poorbroth", "mealname_poorbroth", true}},
	{"ITFO_HERBSTEW", {"meal_herbstew_checkbonus", "nob_checkmeal_herbstew", "mealname_herbstew", true}},
	{"ITFO_MEATANDCHEESE", {"meal_meatandcheese_checkbonus", "nob_checkmeal_meatandcheese", "mealname_meatandcheese", true}},
	{"ITFO_MEATANDBREAD", {"meal_meatandbread_checkbonus", "nob_checkmeal_meatandbread", "mealname_meatandbread", true}},
	{"ITFO_MUSHROOMSTEW", {"meal_mushroomstew_checkbonus", "nob_checkmeal_mushroomstew", "mealname_mushroomstew", true}},
	{"ITFO_POORAPPLEPIE", {"meal_poorapplepie_checkbonus", "nob_checkmeal_poorapplepie", "mealname_poorapplepie", true}},
	{"ITFO_POORPATE", {"meal_poorpate_checkbonus", "nob_checkmeal_poorpate", "mealname_poorpate", true}},
	{"ITFO_PICKLEDMUSHROOMS", {"meal_pickledmushrooms_checkbonus", "nob_checkmeal_pickledmushrooms", "mealname_pickledmushrooms", true}},
	{"ITFO_BREADSOUP", {"meal_breadsoup_checkbonus", "nob_checkmeal_breadsoup", "mealname_breadsoup", true}},
	{"ITFO_SHEPARDROAST", {"meal_shepardroast_checkbonus", "nob_checkmeal_shepardroast", "mealname_shepardroast", true}},
	{"ITFO_POOREGGS", {"meal_pooreggs_checkbonus", "nob_checkmeal_pooreggs", "mealname_pooreggs", true}},
	{"ITFO_BEERFISH", {"meal_beerfish_checkbonus", "nob_checkmeal_beerfish", "mealname_beerfish", true}},
	{"ITFO_SPICYPIE", {"meal_spicypie_checkbonus", "nob_checkmeal_spicypie", "mealname_spicypie", true}},
	{"ITFO_VEGEPIE", {"meal_vegepie_checkbonus", "nob_checkmeal_vegepie", "mealname_vegepie", true}},
	{"ITFO_FATSTEW", {"meal_fatstew_checkbonus", "nob_checkmeal_fatstew", "mealname_fatstew", true}},
	{"ITFO_BEARSTEW", {"meal_bearstew_checkbonus", "nob_checkmeal_bearstew", "mealname_bearstew", true}},
	{"ITFO_HUNTERSPECIAL", {"meal_hunterspecial_checkbonus", "nob_checkmeal_hunterspecial", "mealname_hunterspecial", true}},
	{"ITFO_SPEEDSTEW", {"meal_speedstew_checkbonus", "nob_checkmeal_speedstew", "mealname_speedstew", true}},
	{"ITFO_SMOKEDHERBFISH", {"meal_smokedherbfish_checkbonus", "nob_checkmeal_smokedherbfish", "mealname_smokedherbfish", true}},
	{"ITFO_MEATPACKS", {"meal_meatpacks_checkbonus", "nob_checkmeal_meatpacks", "mealname_meatpacks", true}},
	{"ITFO_HERBMUSHROOMBREWING", {"meal_herbmushroombrewing_checkbonus", "nob_checkmeal_herbmushroombrewing", "mealname_herbmushroombrewing", true}},
	{"ITFO_BERRYJAM", {"meal_berryjam_checkbonus", "nob_checkmeal_berryjam", "mealname_berryjam", true}},
	{"ITFO_STRENGTHJAM", {"meal_strengthjam_checkbonus", "nob_checkmeal_strengthjam", "mealname_strengthjam", false}},
	{"ITFO_DEXDUMPLINGS", {"meal_dexdumplings_checkbonus", "nob_checkmeal_dexdumplings", "mealname_dexdumplings", false}},
	{"ITFO_SIMPLEOYSTERS", {"meal_simpleoysters_checkbonus", "nob_checkmeal_simpleoysters", "mealname_simpleoysters", true}},
	{"ITFO_BERRYCOMPOTE", {"meal_berrycompote_checkbonus", "nob_checkmeal_berrycompote", "mealname_berrycompote", true}},
	{"ITFO_RASPBERRYDRINK", {"meal_raspberrydrink_checkbonus", "nob_checkmeal_raspberrydrink", "mealname_raspberrydrink", true}},
	{"ITFO_GRAPEJUICE", {"meal_grapejuice_checkbonus", "nob_checkmeal_grapejuice", "mealname_grapejuice", true}},
	{"ITFO_RASPBERRYTINCTURE", {"meal_raspberrytincture_checkbonus", "nob_checkmeal_raspberrytincture", "mealname_raspberrytincture", true}},
	{"ITFO_EXOTICDESSERT", {"meal_exoticdessert_checkbonus", "nob_checkmeal_exoticdessert", "mealname_exoticdessert", true}},
	{"ITFO_APPLEPIE", {"meal_applepie_checkbonus", "nob_checkmeal_applepie", "mealname_applepie", true}},
	{"ITFO_SPICYFISH", {"meal_spicyfish_checkbonus", "nob_checkmeal_spicyfish", "mealname_spicyfish", true}},
	{"ITFO_HERBFISHSOUP", {"meal_herbfishsoup_checkbonus", "nob_checkmeal_herbfishsoup", "mealname_herbfishsoup", true}},
	{"ITFO_TROLLSOUP", {"meal_trollsoup_checkbonus", "nob_checkmeal_trollsoup", "mealname_trollsoup", false}},
	{"ITFO_WEEDSTEW", {"meal_weedstew_checkbonus", "nob_checkmeal_weedstew", "mealname_weedstew", true}},
	{"ITFO_FISHPOT", {"meal_fishpot_checkbonus", "nob_checkmeal_fishpot", "mealname_fishpot", true}},
	{"ITFO_BATSTEW", {"meal_batstew_checkbonus", "-", "foodname_batstew", false}},
	{"ITFO_REDSTEW", {"meal_redstew_checkbonus", "-", "foodname_redstew", false}},
	{"ITFO_BLUESTEW", {"meal_bluestew_checkbonus", "-", "foodname_bluestew", false}},
	{"ITFO_SLAGERMEAT", {"meal_slagermeat_checkbonus", "-", "foodname_slagermeat", false}},
	{"ITFO_MARTHSOUP", {"meal_marthsoup1_checkbonus", "-", "itemname_itfo_marthsoup", false}},
	{"ITFO_MARTHSOUP2", {"meal_marthsoup2_checkbonus", "-", "itemname_itfo_marthsoup2", false}},
	{"ITFO_MARTHSOUP3", {"meal_marthsoup3_checkbonus", "nob_checkmeal_marthastew", "mealname_marthastew", true}},
	{"ITFO_MARTHSOUP4", {"meal_marthsoup4_checkbonus", "nob_checkmeal_marthastew_str", "mealname_marthastew_str", true}}
	};

	Dishes::MyList Dishes::Foods = {
		{"foodname_apple", "apple_bonus", false, 25},
		{"foodname_berry_herb", "forestberry_bonus", false, 25},
		{"throphyname_crawlermandibles", "mandibles_bonus", true, 10},
		{"throphyname_sting", "bloodfly_bonus", true, 10}
	};

	int Dishes::allDishesCount = static_cast<int>(Dishes::Data.size());
	int Dishes::allGivableDishesCount = Dishes::CountGivableDishes();

	int Dishes::CountGivableDishes() {
		int count = 0;
		for (auto it = Dishes::Data.begin(); it != Dishes::Data.end(); it++)
		{
			if (it->second.jilCanBuy)
				count++;
		}

		return count;
	}

	int Dishes::GetAllDishesCount() {
		return Dishes::allDishesCount;
	}

	int Dishes::GetAllGivableCount() {
		return Dishes::allGivableDishesCount;
	}

	int Dishes::GetCurrentEatenDishesCount() {
		int count = 0;
		for (auto it = Dishes::Data.begin(); it != Dishes::Data.end(); it++)
		{
			if (GetValueInt(it->second.eaten) > 0)
				count++;
		}

		return count;
	}

	int Dishes::GetCurrentGivenDishesCount() {
		int count = 0;
		for (auto it = Dishes::Data.begin(); it != Dishes::Data.end(); it++)
		{
			if (it->second.jilCanBuy && GetValueInt(it->second.jil) > 0)
				count++;
		}

		return count;
	}

	TCoMDishVars* Dishes::Find(const string& key) {
		auto it = Dishes::Data.find(key);
		if (it != Dishes::Data.end()) {
			return &it->second;
		}

		return nullptr;
	}
}