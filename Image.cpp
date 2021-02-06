#include"Image.h"

namespace img {
	Image::Image() {

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
		sf::Texture texture;
		texture.loadFromFile(fileName);
		this->imgVec.push_back(texture);
	}
	void Image::drawOne(sf::Texture texture, sf::RenderTarget& target) {
		sf::Sprite sprite(texture);
		target.draw(sprite);
	}
	void Image::draw(sf::RenderTarget& target) {
		for (auto i : imgVec) {
			sf::Sprite sprite(i);
			target.draw(sprite);
		}
		
	}
}