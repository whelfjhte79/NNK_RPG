#include"Character.h"



//#define IMG_NAME(img) #img ## ".png"
namespace character {
	Character::Character() {
		this->point = Point(0, 0);
		// ...
	}
	Character::Character(const Character& character) {
		//복사 생성자
	}
	Character::~Character(){}

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

	void Character::move(Point p){
		this->point.setPoint(p.getX(),p.getY());
	}
	void Character::attack() {

	}
	void Character::beAttacked() {

	}

	void Character::update() {

	}
	void Character::render(sf::RenderTarget* target) {
		constexpr int IMG_SIZE = 0;
		img::Image img;
		sf::Texture texture;
		sf::Sprite sprite;
		img.read("OfficeWorker", img::FileExtension::PNG);
		img.read("StockTrader", img::FileExtension::PNG);
		img.read("Enterpriser", img::FileExtension::PNG);
		img.read("Farmer", img::FileExtension::PNG);

		//변수에 이미지 이름 읽어오기

		switch (this->job.getKindOfJobs()) {
		case job::KindOfJobs::OfficeWorker:
			sprite = sf::Sprite(/*이미지 이름 변수*/);
			break;
		case job::KindOfJobs::StockTrader:
			break;
		case job::KindOfJobs::Enterpriser:
			break;
		case job::KindOfJobs::Farmer:
			break;
		case job::KindOfJobs::Auctioneer:
			break;
		case job::KindOfJobs::Wholesaler:
			break;
		case job::KindOfJobs::Hitman:
			break;
		case job::KindOfJobs::Gambler:
			break;
		case job::KindOfJobs::DrugsDealer:
			break;
		default:
			except(ErrorType::IndexOutOfBounds);
			break;

		}


		img.draw(*target);

	}

	Point::Point() {
		this->x = 0;
		this->y = 0;
	}
	Point::Point(int x, int y) : x(x), y(y) {}
	void Point::setPoint(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int Point::getX() {
		return this->x;
	}
	int Point::getY() {
		return this->y;
	}



}