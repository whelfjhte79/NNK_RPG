#ifndef EQUIPMENTS_H
#define EQUIPMENTS_H

#include"Items.h"

namespace equipments {
	class Equipments{
	private:
		items::Items head;
		items::Items weapon;
		items::Items hands;
		items::Items shirt;
		items::Items pants;
		items::Items shoes;
		

	public:
		Equipments(){}
		~Equipments(){}
	};
}


#endif // EQUIPMENTS_H