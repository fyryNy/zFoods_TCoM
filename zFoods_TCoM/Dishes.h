// Supported with union (c) 2020 Union team
// Union HEADER file

#include <map>
#include <list>

namespace GOTHIC_ENGINE {
	struct TCoMDishVars {
		string eaten;
		string jil;
		string name;
		bool jilCanBuy;
	};

	struct TCoMFoodVars {
		string name;
		string bonus;
		bool onlyOnce;
		int required;
	};

	static class Dishes {
		Dishes();
		typedef std::map<string, TCoMDishVars, std::less<string>> MyMap;
		typedef std::list<TCoMFoodVars> MyList;
		static int allDishesCount;
		static int allGivableDishesCount;
		static int allFoodsCount;
		static int CountGivableDishes();

	public:
		static int GetAllDishesCount();
		static int GetAllGivableCount();
		static int GetCurrentEatenDishesCount();
		static int GetCurrentGivenDishesCount();
		static TCoMDishVars* Find(const string& key);
		static MyMap Data;
		static MyList Foods;
	};
}