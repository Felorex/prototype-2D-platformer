#include "Item.h"

Item::Item() {
	pos.x = 1300.f;
	pos.y = 800.f;
	size.width = 20.f;
	size.height = 10.f;
	state = NOT_TAKEN;
	shape.setSize(sf::Vector2f(size.width, size.height));
}

void Item::update(float dt) {
	Entity::update(dt);
	velocityX = 0;

	isTaken();

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
void Item::isTaking(float dy) {
	velocityY = dy;
}
void Item::isTaken() {
	if (state == TAKEN) {
		velocityY = 0;
	}
}
