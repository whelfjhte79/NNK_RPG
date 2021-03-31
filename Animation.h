#ifndef ANIMATION_H
#define ANIMATION_H

#include"stdafx.h"
#include"Image.h"
namespace animation {
	class Animation {
	private:
		img::ImageFile dynamicImg;
		sf::Clock clock;
		sf::IntRect intRect;
		
		sf::SoundBuffer soundBuffer;
		sf::Sound sound;
		
		/*
		if(!soundBuffer.loadFromFile("walk.wav"))
		    std::cout<< "can't find wav file" << std::endl;
		sound.setBuffer(soundBuffer);
		sound.setVolume(50);
		sound.setLoop(true); // 무한 반복

		if(event.key.code == sf::keyboard::p)
			sound.play();
		*/
		sf::Music music;
		/*
		if(!music.openFromFile("hero.ogg"))
			std::cout<<"can't find ogg file " << std::endl;
		if(event.key.code == sf::keyboard::p)
			music.play();

		*/

		float deltaTime;
		float totalTime;
		float switchTime;
		float row;

	public:
		Animation(float deltaTime, float totalTime, float switchTime);
		~Animation();

		void setImg(img::ImageFile img);

		void update(float deltaTime);
	};


}






#endif // ANIMATION_H