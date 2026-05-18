#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

#include <SFML/Graphics.hpp>

class Enemy: public Entity {
public:
	Enemy();
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
	void rushSpeed();

private:
	float horizontalSpeed;
	float rushSpeedValue;
	sf::RectangleShape rect;
};
#endif