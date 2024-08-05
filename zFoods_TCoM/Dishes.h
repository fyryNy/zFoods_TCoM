// Supported with union (c) 2020 Union team
// Union HEADER file

#include <map>

namespace GOTHIC_ENGINE {
	struct TCoMDishVars {
		string eaten;
		string jil;
		string name;
		bool jilCanBuy;
	};

	static class Dishes {
		Dishes();
		typedef std::map<string, TCoMDishVars, std::less<string>> MyMap;
		static int allDishesCount;
		static int allGivableDishesCount;
		static int CountGivableDishes();


	public:
		static int GetAllDishesCount();
		static int GetAllGivableCount();
		static int GetCurrentEatenDishesCount();
		static int GetCurrentGivenDishesCount();
		static TCoMDishVars* Find(const string& key);
		static MyMap Data;
	};
}