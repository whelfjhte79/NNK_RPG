#ifndef CHARACTER_H
#define CHARACTER_H

#include"stdafx.h"
#include"Job.h"
#include"Equipments.h"
#include"Items.h"
#include"Quest.h"
#include"Image.h"
#include"Buildings.h"
#include"Screen.h"

namespace character {
	enum class MoveState {
		Left,
		Right,
		Front,
		Back
	};
	class Character {
	private:
		sf::RenderTarget* target;
		//image
		img::ImageFile img;
		sf::Texture texture;
		sf::Sprite sprite;

		//info
		std::string name;
		MoveState moveState;
		sf::Vector2f point;
		job::Job job;
		equipments::Equipments equipment; // put on
		std::vector<items::Items> items;
		quest::MainQuest quest;
		ability::Ability ability;

		//property
		float money = 0.0f;
		std::vector<screen::Stock> stock;
		
		//state
		bool isDead = false;
		unsigned int hp = 10;
		unsigned int level = 1;
		float exp = 0.0f;
		unsigned int damage = 0;
		unsigned int armor = 0;
		float step = 8.0f;

		//func
		std::string findFileName();


	public:
		Character();
		//Character(...);
		Character(const Character& character);
		~Character();

		//info
		void setName(std::string name);
		void setJob(job::Job job);
		void setHP(int hp);
		void setLevel(int level);
		void setMoney(float money);
		void setDeadFlags(bool isDead);
		void setStep(float step);
		void setPoint(sf::Vector2f point);

		void addItem(items::Items item);
		void deleteItem(items::Items item);
		std::string getName();
		bool getDeadFlags();
		job::Job getJob();
		int getHP();
		unsigned int getDamage();
		unsigned int getArmor();
		float getExp();
		
		int getLevel();
		float getMoney();
		sf::Vector2f getPoint();	
		float getStep();
		std::vector<screen::Stock> getStock();
		//acts
		void move(float x, float y);
		int attack();
		void beAttacked(int damage);


		// update & render
		void update();
		void render(sf::RenderTarget* target);
	};


}





#endif //CHARACTER_H