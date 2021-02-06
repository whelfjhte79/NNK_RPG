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
	class Image {
	private:
		std::string imgName;
		sf::Texture img;
		std::vector<sf::Texture> imgVec;

		void load(std::string fileName);
	public:
		Image();
		~Image();
		
		void read(std::string fileName,FileExtension fileEx);
		void drawOne(sf::Texture texture, sf::RenderTarget& target);
		void draw(sf::RenderTarget& target);
	};
}





#endif //IMAGE_H