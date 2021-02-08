#include"Character.h"

#include<iostream>

//#define IMG_NAME(img) #img ## ".png"
namespace character {
	Character::Character() {
		this->isDead = false;
		this->job.setKindOfFields(job::KindOfFields::WhiteCollar);
		this->job.setKindOfJobs(job::KindOfJobs::OfficeWorker);
		this->point = sf::Vector2f(10.0f, 10.0f);

		// ...
	}
	Character::Character(const Character& character) {
		//복사 생성자
		this->point = character.point;
		this->isDead = false;

	}
	Character::~Character(){}


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
		this->point.x = x;
		this->point.y = y;
		
	}
	void Character::attack() {

	}
	void Character::beAttacked() {

	}

	void Character::update() {

	}
	void Character::render(sf::RenderTarget* target) {
		switch (this->job.getKindOfJobs()) {
		case job::KindOfJobs::OfficeWorker:
			this->img.read("images/OfficeWorker", img::FileExtension::PNG);
			break;
		case job::KindOfJobs::StockTrader:
			this->img.read("images/StockTrader", img::FileExtension::PNG);
			break;
		case job::KindOfJobs::Enterpriser:
			this->img.read("images/Enterpriser", img::FileExtension::PNG);
			break;
		case job::KindOfJobs::Farmer:
			this->img.read("images/Farmer", img::FileExtension::PNG);
			break;
		case job::KindOfJobs::Auctioneer:
			this->img.read("images/Auctioneer", img::FileExtension::PNG);
			break;
		case job::KindOfJobs::Wholesaler:
			this->img.read("images/Wholesaler", img::FileExtension::PNG);
			break;
		case job::KindOfJobs::Hitman:
			this->img.read("images/Hitman", img::FileExtension::PNG);
			break;
		case job::KindOfJobs::Gambler:
			this->img.read("images/Gambler", img::FileExtension::PNG);
			break;
		case job::KindOfJobs::DrugsDealer:
			this->img.read("images/DrugsDealer", img::FileExtension::PNG);
			break;
		default:
			except(ErrorType::IndexOutOfBounds);
			break;

		}

		
		this->img.draw(*target);
		
		this->img.getImgVec().clear();
	}




}