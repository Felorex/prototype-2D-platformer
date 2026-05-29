#include "DynamicObject.h"

DynamicObject::DynamicObject() {
	pos.x = 1000.f;
	pos.y = 400.f;
	size.width = 70.f;
	size.height = 70.f;
	shape.setSize(sf::Vector2f(size.width, size.height));
}

void DynamicObject::update(float dt) {
	Entity::update(dt);

	velocityX = 0;

	shape.setPosition(pos.x, pos.y);
	shape.setFillColor(sf::Color::Black);
}

void DynamicObject::draw(sf::RenderWindow& window) {
	window.draw(shape);
}
float DynamicObject::getSpeed() {
	return 0;
}
