#ifndef CAMERA_H
#define CAMERA_H

#include "Player.h"
#include "TileMap.h"

struct windowSize{
	int width = 800;
	int height = 600;
};


class Camera {
	float x;
	float y;
	sf::View view;

	windowSize size;
public:
	Camera();
	void initCamera(sf::RenderWindow& window);
	void updateCamera(Position playerPosition, TileMap& map);
	void apply(sf::RenderWindow& window);
};

#endif // !1
