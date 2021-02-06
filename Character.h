#ifndef CHARACTER_H
#define CHARACTER_H

#include"NNK_RPG.h"
#include"Job.h"
#include"Equipments.h"
#include"Items.h"
#include"Quest.h"
#include"Image.h"

namespace character {

	class Point {
	private:
		int x;
		int y;
	public:
		Point();
		Point(int x, int y);
		void setPoint(int x, int y);
		int getX();
		int getY();
	};
	class Character {
	private:
		Point point;
		job::Job job;
		equipments::Equipments equipment;
		items::Items item;
		quest::MainQuest quest;
		ability::Ability ability;

		//property
		float money = 0.0f;
		unsigned int stockQuantity = 0;

		//state
		bool isDead;
		unsigned int hp = 10;
		unsigned int level = 1;
		float exp = 0.0f;
		unsigned int damage = 0;
		unsigned int armor = 0;

	public:
		Character();
		//Character(...);
		Character(const Character& character);
		~Character();

		//info
		void setJob(job::Job job);
		void setHP(int hp);
		void setLevel(int level);
		void setMoney(float money);
		void setDeadFlags(bool isDead);

		bool getDeadFlags();
		job::Job getJob();
		int getHP();
		int getLevel();
		float getMoney();
		
		//acts
		void move(Point p);
		void attack();
		void beAttacked();


		// update & render
		void update();
		void render(sf::RenderTarget* target);
	};


}





#endif //CHARACTER_H