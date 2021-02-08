#ifndef CHARACTER_H
#define CHARACTER_H

#include"NNK_RPG.h"
#include"Job.h"
#include"Equipments.h"
#include"Items.h"
#include"Quest.h"
#include"Image.h"

namespace character {
	class Character {
	private:
		//image
		img::Image img;
		sf::Texture texture;
		sf::Sprite sprite;

		//info
		std::string name;
		sf::Vector2f point;
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
		float step = 1.0f;
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
		std::string getName();
		bool getDeadFlags();
		job::Job getJob();
		int getHP();
		int getLevel();
		float getMoney();
		sf::Vector2f getPoint();	
		float getStep();
		//acts
		void move(float x, float y);
		void attack();
		void beAttacked();


		// update & render
		void update();
		void render(sf::RenderTarget* target);
	};


}





#endif //CHARACTER_H