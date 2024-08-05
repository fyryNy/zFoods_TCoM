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

	void DrawLetter(oCItem* renderedItem, zCViewBase* viewBase) {
		zCView* itemView = dynamic_cast<zCView*>(viewBase);
		if (!itemView)
			return;

		if ((renderedItem->HasFlag(ITM_CAT_FOOD))) {
			TCoMDishVars* dish = Dishes::Find(renderedItem->GetObjectName());
			if (!dish)
				return;

			if (dish->jilCanBuy && !GetValueInt(dish->jil)) {
				auto letter = new zCView(6500, 5000, 8000, 7000);
				letter->SetFontColor(zCOLOR(255, 140, 0));
				letter->Print(0, 0, "J");
				itemView->InsertItem(letter);
				letter->Blit();
				delete letter;
			}

			if (!GetValueInt(dish->eaten)) {
				auto letter = new zCView(6500, 900, 8000, 2900);
				letter->SetFontColor(zCOLOR(241, 196, 15));
				letter->Print(0, 0, "B");
				itemView->InsertItem(letter);
				letter->Blit();
				delete letter;
			}
		}
	}

	HOOK Hook_oCItem_RenderItem PATCH(&oCItem::RenderItem, &oCItem::RenderItem_Union);
	void oCItem::RenderItem_Union(zCWorld* wld, zCViewBase* view, float rotate) {
		DrawLetter(this, view);
		THISCALL(Hook_oCItem_RenderItem)(wld, view, rotate);
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

		string sEatenInfo = Z Dishes::GetCurrentEatenDishesCount() + "/" + Z Dishes::GetAllDishesCount();
		string sGivenInfo = Z Dishes::GetCurrentGivenDishesCount() + "/" + Z Dishes::GetAllGivableCount();

		screenFoods->Print(F(xName), F(y), lang == Lang_Pol ? "Nazwa" : "Name");
		screenFoods->Print(F(xJil), F(y), GetValueString("npcname_jil"));
		screenFoods->Print(F(xJil), (F(y)) - 200, sGivenInfo);
		screenFoods->Print(F(xEaten), F(y), lang == Lang_Pol ? "Zjedzone" : "Eaten");
		screenFoods->Print(F(xEaten), (F(y)) - 200, sEatenInfo);
		zSTRING sCode = lang == Lang_Pol ? "Kod" : "Code";
		screenFoods->Print(8192 - screenFoods->FontSize(sCode) - F(xMargin), F(y), sCode);

		zSTRING sYes = lang == Lang_Pol ? "Tak" : "Yes";
		zSTRING sNo = lang == Lang_Pol ? "Nie" : "No";

		for (auto it = Dishes::Data.begin(); it != Dishes::Data.end(); it++) {
			if (i >= start && i < end) {
				y = base + (count * 3);
				zSTRING foodName = "-";
				zSTRING foodGiven = "-";
				zSTRING foodEaten = "-";

				foodName = GetValueString(it->second.name);
				foodEaten = GetValueInt(it->second.eaten) == 1 ? sYes : sNo;
				if (it->second.jilCanBuy)
					foodGiven = GetValueInt(it->second.jil) == 1 ? sYes : sNo;

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
	}

	void Game_Exit() {
	}

	void Game_PreLoop() {
	}

	void Game_Loop() {
		if (zKeyPressed(KEY_P) && !bInMenu) {
			iMenuPage = 0;
			iMenuPageMax = (Dishes::GetAllDishesCount() / iMenuItemsMax);
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