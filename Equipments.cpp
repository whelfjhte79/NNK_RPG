#include"Equipments.h"
#include"Items.h"
namespace equipments {
	Equipments::Equipments() {
		//아이템 장착 render 그리기
		std::string itemLink = "images/items/";
		// 각 종류별로 폴더 만들어서 파일 저장하기
		// name = item real name, img.name = item file name
		this->head = new items::Items("야구 모자", items::Authority::Lv1, 1, ability::Ability(), img::ImageFile(itemLink + "NormalHat", img::FileExtension::PNG, 0.0f, 0.0f));
		this->weapon = new items::Items("없음", items::Authority::Lv1, 1, ability::Ability(), img::ImageFile(itemLink + "NoWeapon", img::FileExtension::PNG, 0.0f, 0.0f));
		this->gloves = new items::Items("손", items::Authority::Lv1, 1, ability::Ability(), img::ImageFile(itemLink + "Hands", img::FileExtension::PNG, 0.0f, 0.0f));
		this->shirt = new items::Items("티셔츠", items::Authority::Lv1, 1, ability::Ability(), img::ImageFile(itemLink + "T_Shirt", img::FileExtension::PNG, 0.0f, 0.0f));
		this->pants = new items::Items("청바지", items::Authority::Lv1, 1, ability::Ability(), img::ImageFile(itemLink + "Jeans", img::FileExtension::PNG, 0.0f, 0.0f));
		this->shoes = new items::Items("장화", items::Authority::Lv1, 1, ability::Ability(), img::ImageFile(itemLink + "Rainboots", img::FileExtension::PNG, 0.0f, 0.0f));
	}
	Equipments::~Equipments() {
		delete this->head;
		delete this->weapon;
		delete this->gloves;
		delete this->shirt;
		delete this->pants;
		delete this->shoes;
	}
	void Equipments::update() {

	}
	void Equipments::render(sf::RenderTarget* target) {

		target->draw(this->head->getImg().getSprite());
		target->draw(this->weapon->getImg().getSprite());
		target->draw(this->gloves->getImg().getSprite());
		target->draw(this->shirt->getImg().getSprite());
		target->draw(this->pants->getImg().getSprite());
		target->draw(this->shoes->getImg().getSprite());
	}
}