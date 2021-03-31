#ifndef DB_H
#define DB_H
#include"sqlite3/sqlite3.h"
#include"nlohmann/json.hpp"
#include<fstream>
#include"Character.h"
#include"stdafx.h"
#include<iomanip> 
#include<list>
using json = nlohmann::json;

namespace db {

	typedef struct User {
		std::string name;
		float pointX;
		float pointY;
		
		float money = 0.0f;
		
		std::vector<screen::Stock> stock;


		unsigned int hp;
		unsigned int level;
		float exp;
		unsigned int damage;
		unsigned int armor;
		float step;

		std::string jobName;
		std::string kindOfField;
		int rate;
		int jobLevel;
		float jobExp;

		std::vector<items::Items> items;
		std::vector<equipments::Equipments> equipments;

	}User;

	class DB {
	private:
		json data;
		
		void load();
		/*
		* 벡터구조체 가져올때
		auto parsed = json.get<std::vector<Test>>();
		
		*/
		void fromJsonStock(std::string structName, screen::Stock& stock);
		void fromJsonItem(std::string structName, items::Items& item);
		void fromJsonEquipments(std::string structName, equipments::Equipments& equipment);
	public:
		User user;
		character::Character character;

		void setCharacter(character::Character& character);

		void read(std::string fileName);
		void serialization();
		void deserialization();
		void write();		

	};
}










#endif //DB_H