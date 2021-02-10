#include"Image.h"

namespace img {
	Image::Image() {
		this->setPoint(sf::Vector2f(0.0f, 0.0f));
	}
	Image::Image(sf::Vector2f point) {
		this->point = point;
	}
	Image::~Image(){}
	void Image::read(std::string fileName,FileExtension fileEx) {
		sf::Texture texture;
		switch (fileEx) {
		case FileExtension::PNG:
			fileName = fileName + ".png";
			break;
		case FileExtension::JPG:
			fileName = fileName + ".jpg";
			break;
		case FileExtension::JPEG:
			fileName = fileName + ".jpeg";
			break;
		case FileExtension::BMP:
			fileName = fileName + ".bmp";
			break;
		default:
			except(ErrorType::FileNotFound);
			break;
		}
		texture.loadFromFile(fileName);
		this->data.name = fileName;
		this->data.img = texture;
		
	}
	void Image::saveImg(Data data) {
		this->imgVec.push_back(data);
	}
	void Image::drawOne(sf::RenderTarget* target) {
		this->sprite = sf::Sprite(this->data.img);
		this->sprite.setPosition(this->point);
	}
	void Image::draw(sf::RenderTarget* target) {
		for (auto i : this->imgVec) {
			this->sprite = sf::Sprite(i.img);
			this->sprite.setPosition(point);
			target->draw(sprite);
		}
		
	}
	
	void Image::setPoint(sf::Vector2f point) {
		this->point = point;
	}
	std::string Image::getImgName() {
		return this->data.name;
	}
	sf::Sprite Image::getSprite() {
		return this->sprite;
	}
	Data Image::getData() {
		return this->data;
	}
	std::vector<Data> Image::getImgVec() {
		return this->imgVec;
	}
	sf::Vector2f Image::getPoint() {
		return this->point;
	}
}