#ifndef CAMERA_H
#define CAMERA_H

#include"stdafx.h"

namespace camera {
	class Camera {
	private:
	    sf::Vector2f focusPosition;
		float zoom;
		float speed;
	public:
		Camera();
	};
}





#endif// CAMERA_H