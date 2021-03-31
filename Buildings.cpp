#include"Buildings.h"



namespace buildings {
	void Buildings::enter(){
		this->entryFlags = true;
	}
	bool Buildings::getEntryFlags() {
		return this->entryFlags;
	}
	void Buildings::setBuilding(IBuildings* building) {
		this->building = building;
	}
	IBuildings* Buildings::getBuilding() {
		return this->building;
	}
	// ///////////////////////////////////////
	// Company
	// ///////////////////////////////////////
	Company::Company() {
		
	}
	void Company::update() {

	}
	void Company::render(sf::RenderTarget* target) {

	}
	StockCenter::StockCenter() {

	}
	void StockCenter::update() {

	}
	void StockCenter::render(sf::RenderTarget* target) {

	}


}