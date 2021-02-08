#include"Items.h"

namespace items {
	Items::Items() {
		this->name = "test";
		this->authority = Authority::Error;
		this->itemType = ItemTypes::Empty;
	}
	Items::Items(ItemTypes itemType, Authority authority, std::string name) {
		this->itemType = itemType;
		this->authority = authority;
		this->name = name;
	}
}