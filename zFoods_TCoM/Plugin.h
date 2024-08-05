// This file added in headers queue
// File: "Headers.h"

namespace GOTHIC_ENGINE {
#define FACTOR 81.919998
#define F(a) static_cast<int>(a * FACTOR)

	zCView* screenFoods;
	bool_t bInMenu;

	int iMenuPage;
	int iMenuPageMax;
	int iMenuItemsMax = 25;
}