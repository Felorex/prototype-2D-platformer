#ifndef MOVEDOBJECT_H
#define MOVEDOBJECT_H

#include "Entity.h"

class DynamicObject :public Entity {
public:
	DynamicObject();
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;

private:
	sf::RectangleShape shape;
};
#endif // !MOVEDOBJECT_H

