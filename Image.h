#ifndef IMAGE_H
#define IMAGE_H

#include"stdafx.h"
#include<iostream>
namespace img {
	enum class FileExtension{
		PNG,
		JPG,
		JPEG,
		BMP
	};
	typedef struct Data {
		std::string name;
		sf::Texture img;
		sf::Vector2u imgSize;
	}Data;
	class ImageFile : public Data {
	private:
		Data data;
		sf::Sprite sprite;
		sf::Vector2f point;
		std::vector<Data> imgVec;
	public:
		ImageFile();
		ImageFile(sf::Vector2f point);
		ImageFile(std::string fileName, FileExtension fileEx, float x, float y);
		ImageFile(std::string fileName, FileExtension fileEx, float x, float y, sf::RenderTarget* target);
		~ImageFile();
	
		void addImage(std::string fileName, FileExtension fileEx);
		void clearImgVec();
		void setSprite();
		void setPoint(sf::Vector2f point);
		sf::Vector2f getPoint();
		std::string getImgName();
		Data getData();
		std::vector<Data> getImgVec();
		sf::Sprite getSprite();
		sf::Vector2u getImgSize();
		void read(std::string fileName,FileExtension fileEx);
		void draw(sf::RenderTarget* target);
		void drawAll(sf::RenderTarget* target);
	};
}





#endif //IMAGE_H