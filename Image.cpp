#include"Image.h"

namespace img {
	ImageFile::ImageFile() {
		this->setPoint(sf::Vector2f(0.0f, 0.0f));
	}
	ImageFile::ImageFile(std::string fileName, FileExtension fileEx, float x, float y) {
		this->read(fileName, fileEx);
		this->setPoint(sf::Vector2f(x, y));
		this->setSprite();
	}
	ImageFile::ImageFile(std::string fileName, FileExtension fileEx, float x, float y, sf::RenderTarget* target) {
		this->read(fileName, fileEx);
		this->setPoint(sf::Vector2f(x, y));
		this->setSprite();
		this->draw(target);
	}
	ImageFile::ImageFile(sf::Vector2f point) {
		this->point = point;
	}
	ImageFile::~ImageFile(){}

	void ImageFile::read(std::string fileName,FileExtension fileEx) {
		sf::Texture texture;
		if (fileName == "") {
			std::cout << "file name does not exist";
			except(ErrorType::FileNotFound);
		}
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
		if (!texture.loadFromFile(fileName)) {
			except(ErrorType::FileNotFound);
		}
		this->data.name = fileName;
		this->data.img = texture;
		this->data.imgSize = texture.getSize();

	}
	void ImageFile::addImage(std::string fileName, FileExtension fileEx) {
		this->read(fileName, fileEx);
		this->imgVec.push_back(this->data);
	}
	void ImageFile::clearImgVec() {
		this->imgVec.clear();
	}
	void ImageFile::setSprite() {
		this->sprite = sf::Sprite(this->data.img);
		this->sprite.setPosition(this->point);
	}
	void ImageFile::draw(sf::RenderTarget* target) {
		if (target == NULL) { return; }
		target->draw(this->sprite);
	}
	void ImageFile::drawAll(sf::RenderTarget* target) {
		for (auto i : this->imgVec) {
			this->sprite = sf::Sprite(i.img);
			this->sprite.setPosition(point);
			target->draw(sprite);
		}
	}
	void ImageFile::setPoint(sf::Vector2f point) {
		this->point = point;
	}
	std::string ImageFile::getImgName() {
		return this->data.name;
	}
	Data ImageFile::getData() {
		return this->data;
	}
	sf::Sprite ImageFile::getSprite() {
		return this->sprite;
	}
	std::vector<Data> ImageFile::getImgVec() {
		return this->imgVec;
	}
	sf::Vector2f ImageFile::getPoint() {
		return this->point;
	}
	sf::Vector2u ImageFile::getImgSize() {
		return this->data.img.getSize();
	}
}