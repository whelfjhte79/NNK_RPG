#ifndef ITEMS_H
#define ITEMS_H

#include"NNK_RPG.h"
#include"Ability.h"
namespace items {

	enum class ItemType {
		Empty,
		Head,
		Weapon,
		Hands,
		Shirt,
	    Pants,
	    Shoes
	};
	enum Authority {
		Error = 0,
		Lv1 = 1,
		Lv2 = 2,
		Lv3 = 3,
		Lv4 = 4,
		Lv5 = 5 
	};
	class Items {
	private:
		std::string name;
		int authority;
		ItemType itemType;

		ability::Ability ability;

	public:
		Items(){}
		Items(ItemType itemtype, int authority, std::string name){}

		void setName(std::string name){}
		void setAuthority(int authority){}
		void setItemType(ItemType itemType){}

		std::string getName(){}
		int getAuthority(){}
		ItemType getItemType(){}

	};
}




#endif// ITEMS_H