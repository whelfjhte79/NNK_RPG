#include"Character.h"

#include<iostream>

//#define IMG_NAME(img) #img ## ".png"
namespace character {

	Character::Character() {
		this->isDead = false;
		this->job.setKindOfFields(job::KindOfFields::WhiteCollar);
		this->job.setKindOfJobs(job::KindOfJobs::OfficeWorker);
		this->point = sf::Vector2f(100.0f, 100.0f);
		this->target = NULL;
		this->moveState = MoveState::Front;
		// ...
	}
	Character::Character(const Character& character) {
		
		this->target = character.target;
		this->point = character.point;
		this->isDead = false;
		this->moveState = character.moveState;


	}
	Character::~Character(){}

	std::string Character::findFileName() {
		std::string fileName = "images/Character/";
		switch (this->job.getKindOfFields()) {
		case job::KindOfFields::WhiteCollar:
			fileName += "WhiteCollar";
			break;
		case job::KindOfFields::Merchant:
			fileName += "Merchant";
			break;
		case job::KindOfFields::BlackGuard:
			fileName += "BlackGuard";
			break;
		default:
			except(ErrorType::FileNotFound);
			break;
		}

		fileName += "_";

		switch (this->moveState) {
		case MoveState::Front:
			fileName += "Front";
			break;
		case MoveState::Back:
			fileName += "Back";
			break;
		case MoveState::Left:
			fileName += "Left";
			break;
		case MoveState::Right:
			fileName += "Right";
			break;
		default:
			except(ErrorType::FileNotFound);
		}

		return fileName;
	}

	void Character::setName(std::string name) {
		this->name = name;
	}
	void Character::setJob(job::Job job) {
		this->job = job;
	}
	void Character::setHP(int hp) {
		this->hp = hp;
	}
	void Character::setLevel(int level) {
		if (level < 1) level = 1;
		this->level = level;
	}
	void Character::setMoney(float money) {
		if (money < 0.0f) money = 0.0f;
		this->money = money;
	}
	void Character::setDeadFlags(bool isDead) {
		this->isDead = isDead;
	}
	void Character::setStep(float step) {
		this->step = step;
	}
	void Character::setPoint(sf::Vector2f point) {
		this->point = point;
	}

	void Character::addItem(items::Items item) {
		this->items.push_back(item);
	}
	void Character::deleteItem(items::Items item) {
		for (std::vector<items::Items>::iterator itr = this->items.begin(); itr != this->items.end(); itr++) {
			if (itr->getName() == item.getName()) {
				itr = this->items.erase(itr);
			}
		}
	}

	std::string Character::getName() {
		return this->name;
	}
	job::Job Character::getJob() {
		return this->job;
	}
	int Character::getHP() {
		return this->hp;
	}
	unsigned int Character::getDamage() {
		return this->damage;
	}
	unsigned int Character::getArmor() {
		return this->armor;
	}
	float Character::getExp() {
		return this->exp;
	}
	int Character::getLevel() {
		return this->level;
	}
	float Character::getMoney() {
		return this->money;
	}
	bool Character::getDeadFlags() {
		return this->isDead;
	}
	sf::Vector2f Character::getPoint() {
		return this->point;
	}
	float Character::getStep() {
		return this->step;
	}
	std::vector<screen::Stock> Character::getStock() {
		return this->stock;
	}

	void Character::move(float x, float y){
		this->point.x += x;
		this->point.y += y;
		
	}
	int Character::attack() {
		return this->damage;
	}
	void Character::beAttacked(int damage) {
		this->hp -= damage;
		if (this->hp <= 0) this->isDead = true;
	}

	void Character::render(sf::RenderTarget* target) {
		std::string characterName = this->findFileName();
		this->img = img::ImageFile(characterName, img::FileExtension::PNG, this->point.x, this->point.y, target);
		
	}
	void Character::update() {
	
	
	}



}