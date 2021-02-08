#include"Image.h"

namespace img {
	Image::Image() {
		this->setPoint(sf::Vector2f(10.0f, 10.0f));
	}
	Image::Image(sf::Vector2f point) {
		this->point = point;
	}
	Image::~Image(){}
	void Image::read(std::string fileName,FileExtension fileEx) {

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

		this->load(fileName);
	}
	void Image::load(std::string fileName) {
		img::Data data;
		sf::Texture texture;
		texture.loadFromFile(fileName);
		data.name = fileName;
		data.img = texture;

		this->imgVec.push_back(data);
	}
	void Image::drawOne(std::string fileName, sf::RenderTarget& target) {
		
		sf::Texture texture;
		for (auto& i : this->imgVec) {
			if (i.name == fileName) {
				texture = i.img;
			}
		}
		sf::Sprite sprite(texture);
		target.draw(sprite);
	}
	void Image::draw(sf::RenderTarget& target) {
		for (auto i : this->imgVec) {
			this->sprite = sf::Sprite(i.img);
			this->sprite.setPosition(point);
			target.draw(sprite);
		}
		
	}
	void Image::setPoint(sf::Vector2f point) {
		this->point = point;
	}
	std::string Image::getImgName() {
		return this->data.name;
	}
	Data Image::getData() {
		return this->data;
	}
	std::vector<Data> Image::getImgVec() {
		return this->imgVec;
	}
}