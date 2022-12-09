// This file added in headers queue
// File: "Sources.h"
#include "resource.h"

namespace GOTHIC_ENGINE {
	int GetValueInt(string s) {
		zCPar_Symbol* sym = parser->GetSymbol(Z s);

		if (!sym)
			return -1;

		int val;
		sym->GetValue(val, 0);

		return val;
	}

	zSTRING GetValueString(string s) {
		zCPar_Symbol* sym = parser->GetSymbol(Z s);

		if (!sym)
			return -1;

		zSTRING val;
		sym->GetValue(val, 0);

		return val;
	}

	void OpenMenu() {
		TSystemLangID lang = Union.GetSystemLanguage();
		bInMenu = true;
		player->movlock = true;
		zCCSCamera::playing = true;

		screen->InsertItem(screenFoods);
		screenFoods->ClrPrintwin();
		screenFoods->SetFont("Font_10_Book.TGA");

		int base = 15;
		int count = 0;
		int i = 0;
		int start = iMenuPage * iMenuItemsMax;
		int end = start + iMenuItemsMax;
		int y = 0;

		y = 10;
		int xMargin = 10;
		int xName = xMargin;
		int xJil = 45;
		int xEaten = 52;

		screenFoods->Print(F(xName), F(y), lang == Lang_Pol ? "Nazwa" : "Name");
		screenFoods->Print(F(xJil), F(y), GetValueString("npcname_jil"));
		screenFoods->Print(F(xEaten), F(y), lang == Lang_Pol ? "Zjedzone" : "Eaten");
		zSTRING sCode = lang == Lang_Pol ? "Kod (dodaj itfo_)" : "Code (add itfo_)";
		screenFoods->Print(8192 - screenFoods->FontSize(sCode) - F(xMargin), F(y), sCode);

		zSTRING sYes = lang == Lang_Pol ? "Tak" : "Yes";
		zSTRING sNo = lang == Lang_Pol ? "Nie" : "No";

		for (std::map<string, bool_t>::iterator it = Foods.begin(); it != Foods.end(); it++) {
			if (i >= start && i < end) {
				y = base + (count * 3);
				zSTRING foodName = "-";
				zSTRING foodGiven = "-";
				zSTRING foodEaten = "-";
				if (it->second) {
					foodName = GetValueString("mealname_" + it->first);
					foodGiven = GetValueInt("nob_checkmeal_" + it->first) == 1 ? sYes : sNo;
					foodEaten = GetValueInt("meal_" + it->first + "_checkbonus") == 1 ? sYes : sNo;
				}
				else {
					if (it->first == "batstew") {
						foodName = GetValueString("foodname_batstew");
						foodEaten = GetValueInt("meal_" + it->first + "_checkbonus") == 1 ? sYes : sNo;
					}
					else if (it->first == "redstew") {
						foodName = GetValueString("foodname_redstew");
						foodEaten = GetValueInt("meal_" + it->first + "_checkbonus") == 1 ? sYes : sNo;
					}
					else if (it->first == "bluestew") {
						foodName = GetValueString("foodname_bluestew");
						foodEaten = GetValueInt("meal_" + it->first + "_checkbonus") == 1 ? sYes : sNo;
					}
					else if (it->first == "slagermeat") {
						foodName = GetValueString("foodname_slagermeat");
						foodEaten = GetValueInt("meal_" + it->first + "_checkbonus") == 1 ? sYes : sNo;
					}
					else if (it->first == "marthsoup") {
						foodName = GetValueString("itemname_itfo_marthsoup");
						foodEaten = GetValueInt("meal_marthsoup1_checkbonus") == 1 ? sYes : sNo;
					}
					else if (it->first == "marthsoup2") {
						foodName = GetValueString("itemname_itfo_marthsoup2");
						foodEaten = GetValueInt("meal_" + it->first + "_checkbonus") == 1 ? sYes : sNo;
					}
					else if (it->first == "marthsoup3") {
						foodName = GetValueString("mealname_marthastew");
						foodGiven = GetValueInt("nob_checkmeal_marthastew") == 1 ? sYes : sNo;
						foodEaten = GetValueInt("meal_" + it->first + "_checkbonus") == 1 ? sYes : sNo;
					}
					else if (it->first == "marthsoup4") {
						foodName = GetValueString("mealname_marthastew_str");
						foodGiven = GetValueInt("nob_checkmeal_marthastew_str") == 1 ? sYes : sNo;
						foodEaten = GetValueInt("meal_" + it->first + "_checkbonus") == 1 ? sYes : sNo;
					}
				}

				int foodNameSize = screenFoods->FontSize(foodName);
				int letterSize = foodNameSize / foodName.Length();

				if (foodNameSize + F(xMargin) >= F(xJil)) {
					int lettersToCut = (foodNameSize + F(xMargin) - F(xJil)) / letterSize + 3;
					foodName = foodName.Cut(foodName.Length() - lettersToCut, foodName.Length()) + "...";
				}

				screenFoods->Print(F(xName), F(y), foodName);
				screenFoods->Print(F(xJil), F(y), foodGiven);
				screenFoods->Print(F(xEaten), F(y), foodEaten);
				screenFoods->Print(8192 - screenFoods->FontSize(Z it->first) - F(xMargin), F(y), Z it->first);

				count++;
			}

			i++;
		}

		zSTRING CurrentBonusCount = lang == Lang_Pol ? "Aktualny licznik bonusu" : "Current bonus counter";
		CurrentBonusCount += +Z ": " + Z GetValueInt("meal_pointsbonus") + Z " / 5";
		screenFoods->Print(8192 / 2 - screenFoods->FontSize(CurrentBonusCount) / 2, F(90), CurrentBonusCount);

		screenFoods->SetFont("Font_20_Book.TGA");
		if (iMenuPage > 0)
			screenFoods->Print(F(5), F(90), "<");
		if (iMenuPage < iMenuPageMax)
			screenFoods->Print(8192 - F(5) - screenFoods->FontSize(Z ">"), F(90), Z ">");
	}

	void CloseMenu() {
		bInMenu = false;
		player->movlock = false;
		zCCSCamera::playing = false;

		screen->RemoveItem(screenFoods);
		zinput->ClearKeyBuffer();
	}

	void ReOpenMenu() {
		screen->RemoveItem(screenFoods);
		OpenMenu();
		zinput->ClearKeyBuffer();
	}

	void Game_Entry() {
	}

	void Game_Init() {
		if (!screenFoods) {
			int SizeX = 60;
			int SizeY = 70;
			screenFoods = zNEW(zCView)(0, 0, F(SizeX), F(SizeY));
			screenFoods->SetPos(F((100 - SizeX) / 2), F((100 - SizeY) / 2));
			screenFoods->InsertBack("SCROLL_ELEGANT_01.tga");
		}

		Foods["pickledbeet"] = true;
		Foods["beerbread"] = true;
		Foods["pumpkincompote"] = true;
		Foods["honeycookies"] = true;
		Foods["friedfishskins"] = true;
		Foods["scavengershashlik"] = true;
		Foods["roastedinsects"] = true;
		Foods["cabbagesoup"] = true;
		Foods["mushroomcotlet"] = true;
		Foods["dryfruitcompote"] = true;
		Foods["fishvinegar"] = true;
		Foods["manapermsoup"] = true;
		Foods["sweetbun"] = true;
		Foods["mushroomsoup"] = true;
		Foods["rivermirtsoup"] = true;
		Foods["speedherboysters"] = true;
		Foods["boarstew"] = true;
		Foods["meatmishmash"] = true;
		Foods["ratstick"] = true;
		Foods["mulledwisp"] = true;
		Foods["fishcotlet"] = true;
		Foods["fishfilletperm"] = true;
		Foods["poorbroth"] = true;
		Foods["herbstew"] = true;
		Foods["meatandcheese"] = true;
		Foods["meatandbread"] = true;
		Foods["mushroomstew"] = true;
		Foods["poorapplepie"] = true;
		Foods["poorpate"] = true;
		Foods["pickledmushrooms"] = true;
		Foods["breadsoup"] = true;
		Foods["shepardroast"] = true;
		Foods["pooreggs"] = true;
		Foods["beerfish"] = true;
		Foods["spicypie"] = true;
		Foods["vegepie"] = true;
		Foods["fatstew"] = true;
		Foods["bearstew"] = true;
		Foods["hunterspecial"] = true;
		Foods["speedstew"] = true;
		Foods["smokedherbfish"] = true;
		Foods["meatpacks"] = true;
		Foods["herbmushroombrewing"] = true;
		Foods["berryjam"] = true;
		Foods["strengthjam"] = true;
		Foods["dexdumplings"] = true;
		Foods["simpleoysters"] = true;
		Foods["berrycompote"] = true;
		Foods["raspberrydrink"] = true;
		Foods["grapejuice"] = true;
		Foods["raspberrytincture"] = true;
		Foods["exoticdessert"] = true;
		Foods["applepie"] = true;
		Foods["spicyfish"] = true;
		Foods["herbfishsoup"] = true;
		Foods["trollsoup"] = true;
		Foods["weedstew"] = true;
		Foods["fishpot"] = true;

		Foods["batstew"] = false;
		Foods["redstew"] = false;
		Foods["bluestew"] = false;
		Foods["slagermeat"] = false;
		Foods["marthsoup"] = false;
		Foods["marthsoup2"] = false;
		Foods["marthsoup3"] = false; //nob_checkmeal_marthastew
		Foods["marthsoup4"] = false; //nob_checkmeal_marthastew_str
	}

	void Game_Exit() {
	}

	void Game_PreLoop() {
	}

	void Game_Loop() {
		if (zKeyPressed(KEY_P) && !bInMenu) {
			iMenuPage = 0;
			iMenuPageMax = (static_cast<int>(Foods.size()) / iMenuItemsMax);
			OpenMenu();
		}

		if (bInMenu) {
			if (zBindPressed(zLOGICKEY_LEFT) || zBindPressed(zLOGICKEY_STRAFELEFT)) {
				if (iMenuPage > 0) {
					iMenuPage--;
					ReOpenMenu();
				}
			}

			if (zBindPressed(zLOGICKEY_RIGHT) || zBindPressed(zLOGICKEY_STRAFERIGHT)) {
				if (iMenuPage < iMenuPageMax) {
					iMenuPage++;
					ReOpenMenu();
				}
			}

			if (zKeyToggled(KEY_ESCAPE) || zMouseKeyToggled(Right)) {
				zinput->ClearKeyBuffer();
				CloseMenu();
			}

			if (zBindPressed(zLOGICKEY_INVENTORY)
				|| zBindPressed(zLOGICKEY_SCREEN_LOG)
				|| zBindPressed(zLOGICKEY_SCREEN_STATUS)
				|| zBindPressed(zLOGICKEY_SCREEN_MAP)
				|| zBindPressed(zLOGICKEY_WEAPON)) {
				zinput->ClearKeyBuffer();
			}
		}
	}

	void Game_PostLoop() {
	}

	void Game_MenuLoop() {
	}

	// Information about current saving or loading world
	TSaveLoadGameInfo& SaveLoadGameInfo = UnionCore::SaveLoadGameInfo;

	void Game_SaveBegin() {
	}

	void Game_SaveEnd() {
	}

	void LoadBegin() {
	}

	void LoadEnd() {
	}

	void Game_LoadBegin_NewGame() {
		LoadBegin();
	}

	void Game_LoadEnd_NewGame() {
		LoadEnd();
	}

	void Game_LoadBegin_SaveGame() {
		LoadBegin();
	}

	void Game_LoadEnd_SaveGame() {
		LoadEnd();
	}

	void Game_LoadBegin_ChangeLevel() {
		LoadBegin();
	}

	void Game_LoadEnd_ChangeLevel() {
		LoadEnd();
	}

	void Game_LoadBegin_Trigger() {
	}

	void Game_LoadEnd_Trigger() {
	}

	void Game_Pause() {
	}

	void Game_Unpause() {
	}

	void Game_DefineExternals() {
	}

	void Game_ApplyOptions() {
	}

	/*
	Functions call order on Game initialization:
	  - Game_Entry           * Gothic entry point
	  - Game_DefineExternals * Define external script functions
	  - Game_Init            * After DAT files init

	Functions call order on Change level:
	  - Game_LoadBegin_Trigger     * Entry in trigger
	  - Game_LoadEnd_Trigger       *
	  - Game_Loop                  * Frame call window
	  - Game_LoadBegin_ChangeLevel * Load begin
	  - Game_SaveBegin             * Save previous level information
	  - Game_SaveEnd               *
	  - Game_LoadEnd_ChangeLevel   *

	Functions call order on Save game:
	  - Game_Pause     * Open menu
	  - Game_Unpause   * Click on save
	  - Game_Loop      * Frame call window
	  - Game_SaveBegin * Save begin
	  - Game_SaveEnd   *

	Functions call order on Load game:
	  - Game_Pause              * Open menu
	  - Game_Unpause            * Click on load
	  - Game_LoadBegin_SaveGame * Load begin
	  - Game_LoadEnd_SaveGame   *
	*/

#define AppDefault True
	CApplication* lpApplication = !CHECK_THIS_ENGINE ? Null : CApplication::CreateRefApplication(
		Enabled(AppDefault) Game_Entry,
		Enabled(AppDefault) Game_Init,
		Enabled(AppDefault) Game_Exit,
		Enabled(AppDefault) Game_PreLoop,
		Enabled(AppDefault) Game_Loop,
		Enabled(AppDefault) Game_PostLoop,
		Enabled(AppDefault) Game_MenuLoop,
		Enabled(AppDefault) Game_SaveBegin,
		Enabled(AppDefault) Game_SaveEnd,
		Enabled(AppDefault) Game_LoadBegin_NewGame,
		Enabled(AppDefault) Game_LoadEnd_NewGame,
		Enabled(AppDefault) Game_LoadBegin_SaveGame,
		Enabled(AppDefault) Game_LoadEnd_SaveGame,
		Enabled(AppDefault) Game_LoadBegin_ChangeLevel,
		Enabled(AppDefault) Game_LoadEnd_ChangeLevel,
		Enabled(AppDefault) Game_LoadBegin_Trigger,
		Enabled(AppDefault) Game_LoadEnd_Trigger,
		Enabled(AppDefault) Game_Pause,
		Enabled(AppDefault) Game_Unpause,
		Enabled(AppDefault) Game_DefineExternals,
		Enabled(AppDefault) Game_ApplyOptions
	);
}