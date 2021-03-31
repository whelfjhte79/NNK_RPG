#ifndef ITEMS_H
#define ITEMS_H

#include"stdafx.h"
#include"Ability.h"
#include"Image.h"
namespace items {


	enum class ItemTypes {
		Empty,
		Head,
		Weapon,
		Gloves,
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
		int quantity;
		ability::Ability ability;
		img::ImageFile img;
	public:
		Items();
		Items(std::string name, int authority, int quantity, ability::Ability ability, img::ImageFile img);

		void setName(std::string name);
		void setAuthority(int authority);
		void setQuantity(int quantity);

		std::string getName();
		int getAuthority();
		int getQuantity();
		img::ImageFile getImg();
		//draw
		void update();
		void render(sf::RenderTarget* target);
		
	};

	class ItemList {
	private:
		std::vector<Items*> itemList;
		Items* item;
	public:
		ItemList();
		ItemList(Items* item);
		~ItemList();

		Items* getItem();

	};
}




#endif// ITEMS_H