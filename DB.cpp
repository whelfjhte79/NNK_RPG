#include"DB.h"

namespace db {
	void DB::setCharacter(character::Character& character) {
		this->character = character;
	}
	void DB::load() {

		//info
		this->user.name = character.getName();
		this->user.pointX = character.getPoint().x;
		this->user.pointY = character.getPoint().y;

		//property
		this->user.money = character.getMoney();

		/*
		*  vector struct 어떻게 json에 담을지
		*/
		this->user.stock = character.getStock();

		

		//state
		this->user.hp = character.getHP();
		this->user.level = character.getLevel();
		this->user.exp = this->character.getExp();
		this->user.damage = this->character.getDamage();
		this->user.armor = this->character.getArmor();
		this->user.step = this->character.getStep();
	
	
	
	}
	void DB::fromJsonStock(std::string structName, screen::Stock& stock) {
		static int i = 0;
		this->data[structName]["Name"][std::to_string(i++)] = stock.getName();
		this->data[structName]["CurrentPrice"][std::to_string(i++)] = stock.getCurrentPrice();
	}
	void DB::fromJsonItem(std::string structName, items::Items& items) {
		static int i = 0;
		this->data[structName]["Name"][std::to_string(i++)] = items.getName();
		this->data[structName]["Authority"][std::to_string(i++)] = items.getAuthority();
	}
	void DB::fromJsonEquipments(std::string structName, equipments::Equipments& equipments) {
		static int i = 0;
		//this->data[structName]["Name"][std::to_string(i++)] = equipments.getName();
	}
	void DB::read(std::string fileName) {
		fileName += ".json";
		std::ifstream ifs(fileName);
		ifs >> this->data;
	}
	void DB::serialization() {
		load();

		// [User]
		std::string text = "User";
		//info
		data[text + "Name"] = this->user.name;
		data[text + "PointX"] = this->user.pointX;
		data[text + "PointY"] = this->user.pointY;

		//property
		data[text + "Money"] = this->user.money;
		
		for (auto itr=this->user.stock.begin(); itr!=this->user.stock.end(); ++ itr){
			this->fromJsonStock(text + "Stock", *itr);
		}
		//state
		data[text + "HP"] = this->user.hp;
		data[text + "Level"] = this->user.level;
		data[text + "Exp"] = this->user.exp;
		data[text + "Damage"] = this->user.damage;
		data[text + "Armor"] = this->user.armor;
		data[text + "Step"] = this->user.step;

		//the others
		data[text + "Job"]["Name"] = this->user.jobName;
		data[text + "Job"]["Field"] = this->user.kindOfField;
		data[text + "Job"]["Rate"] = this->user.rate;
		data[text + "Job"]["Level"] = this->user.jobLevel;
		data[text + "Job"]["Exp"] = this->user.jobExp;

		for (auto itr = this->user.items.begin(); itr != this->user.items.end(); ++itr) {
			this->fromJsonItem(text + "Item", *itr);
		}
		for (auto itr = this->user.equipments.begin(); itr != this->user.equipments.end(); ++itr) {
			this->fromJsonEquipments(text + "Equipments", *itr);
		}



		std::ofstream o("TEST.json");
		o << std::setw(4) << data << std::endl;

	}
	void DB::deserialization() {

	}
	void DB::write() {

	}
}