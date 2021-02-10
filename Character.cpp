#include"Character.h"

#include<iostream>

//#define IMG_NAME(img) #img ## ".png"
namespace character {

	Character::Character() {
		this->isDead = false;
		this->job.setKindOfFields(job::KindOfFields::WhiteCollar);
		this->job.setKindOfJobs(job::KindOfJobs::OfficeWorker);
		this->point = sf::Vector2f(100.0f, 100.0f);

		this->moveState = MoveState::Front;
		// ...
	}
	Character::Character(const Character& character) {
		//복사 생성자
		this->point = character.point;
		this->isDead = false;

	}
	Character::~Character(){}

	std::string Character::findFileName() {
		std::string fileName = "images/Character/";
		switch (this->job.getKindOfJobs()) {
		case job::KindOfJobs::OfficeWorker:
			fileName += "OfficeWorker";
			break;
		case job::KindOfJobs::StockTrader:
			fileName += "StockTrader";
			break;
		case job::KindOfJobs::Enterpriser:
			fileName += "Enterpriser";
			break;
		case job::KindOfJobs::Farmer:
			fileName += "Farmer";
			break;
		case job::KindOfJobs::Auctioneer:
			fileName += "Auctioneer";
			break;
		case job::KindOfJobs::Wholesaler:
			fileName += "Wholesaler";
			break;
		case job::KindOfJobs::Hitman:
			fileName += "Hitman";
			break;
		case job::KindOfJobs::Gambler:
			fileName += "Gambler";
			break;
		case job::KindOfJobs::DrugsDealer:
			fileName += "DrugsDealer";
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

	std::string Character::getName() {
		return this->name;
	}
	job::Job Character::getJob() {
		return this->job;
	}
	int Character::getHP() {
		return this->hp;
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

	void Character::move(float x, float y){
		this->point.x += x;
		this->point.y += y;
		
	}
	void Character::attack() {

	}
	void Character::beAttacked() {

	}

	void Character::render(sf::RenderTarget* target) {
		std::string characterName = this->findFileName();

		this->img.read(characterName, img::FileExtension::PNG);
		this->img.setPoint(this->point);
		this->img.drawOne(target);
		
		target->draw(this->img.getSprite());
	}
	void Character::update() {
	
		
		
	}



}