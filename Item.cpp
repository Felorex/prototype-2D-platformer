#include "Item.h"

Item::Item() {
	pos.x = 1010.f;
	pos.y = 800.f;
	size.width = 10.f;
	size.height = 10.f;
	state = NOT_TAKEN;
}

void Item::update(float dt) {
	Entity::update(dt);
	velocityX = 0;


	shape.setPosition(pos.x, pos.y);
	shape.setFillColor(sf::Color::White);
}
void Item::draw(sf::RenderWindow& window) {
	window.draw(shape);
}
float Item::getSpeed() {
	return 0;
}
ItemState Item::getState() {
	return state;
}
void Item::setState(ItemState newState) {
	state = newState;
}
void Item::isTaken() {
	
}