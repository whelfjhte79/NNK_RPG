#ifndef IMAGE_H
#define IMAGE_H

#include"NNK_RPG.h"

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
	
	}Data;
	class Image : public Data {
	private:
		Data data;
		sf::Sprite sprite;
		sf::Vector2f point;
		std::vector<Data> imgVec;
		void load(std::string fileName);
	public:
		Image();
		Image(sf::Vector2f point);
		~Image();
		
		void setPoint(sf::Vector2f point);

		std::string getImgName();
		Data getData();
		std::vector<Data> getImgVec();
		void read(std::string fileName,FileExtension fileEx);
		void drawOne(std::string fileName, sf::RenderTarget& target);
		void draw(sf::RenderTarget& target);
	};
}





#endif //IMAGE_H