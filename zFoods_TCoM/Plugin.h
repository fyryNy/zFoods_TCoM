// This file added in headers queue
// File: "Headers.h"

#include <map>
#include <vector>

namespace GOTHIC_ENGINE {
#define FACTOR 81.919998
#define F(a) static_cast<int>(a * FACTOR)

	zCView* screenFoods;
	bool_t bInMenu;

	int iMenuPage;
	int iMenuPageMax;
	int iMenuItemsMax = 25;

	std::map<string, bool_t, std::less<string>> Foods;
}