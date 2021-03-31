#ifndef EQUIPMENTS_H
#define EQUIPMENTS_H

#include"Items.h"

namespace equipments {
	class Equipments{
	private:
		items::Items* head;
		items::Items* weapon;
		items::Items* gloves;
		items::Items* shirt;
		items::Items* pants;
		items::Items* shoes;
		
		

	public:
		Equipments();
		Equipments(items::Items* head, items::Items* weapon, items::Items* gloves, items::Items* shirt, items::Items* pants, items::Items* shoes);
		~Equipments();

		void update();
		void render(sf::RenderTarget* target);
	};
}


#endif // EQUIPMENTS_H