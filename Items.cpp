#include"Items.h"

namespace items {
	Items::Items() {
		this->name = "test";
		this->authority = Authority::Error;
		this->quantity = 1;
	}
	Items::Items(std::string name, int authority, int quantity, ability::Ability ability, img::ImageFile img) {
		this->name = name;
		this->authority = authority;
		this->quantity = quantity;
		this->ability = ability;
		this->img = img;
	}
	void Items::setName(std::string name) {
		this->name = name;
	}
	void Items::setAuthority(int authority) {
		this->authority = authority;
	}

	void Items::setQuantity(int quantity) {
		this->quantity = quantity;
	}
	std::string Items::getName() {
		return this->name;
	}
	int Items::getAuthority() {
		return this->authority;
	}
	int Items::getQuantity() {
		return this->quantity;
	}
	img::ImageFile Items::getImg() {
		return this->img;
	}

	void Items::update() {

	}
	void Items::render(sf::RenderTarget* target) {
		target->draw(this->img.getSprite());
	}
	ItemList::ItemList() {
	}
	ItemList::ItemList(Items* item) {
		this->item = item;
	}
	ItemList::~ItemList() {
		delete this->item;
	}
	Items* ItemList::getItem(){
		return this->item;
	}
	
}
