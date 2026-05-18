#include "Entity.h"

Entity::Entity() {
	isOnGround = false;
	velocityY = 0;
	gravity = 1000.f;
	previousPos = getPosition();
	futurePos = getPosition();
}
Position Entity::getPosition() {
	return pos;
}
void Entity::setPosition(float x, float y) {
	pos.x = x;
	pos.y = y;
}
void Entity::move(float dx) {
	pos.x += dx;
}
void Entity::setOnGround(bool ground) {
	isOnGround = ground;
}
void Entity::setVelocityY(float v) {
	velocityY = v;
}
float Entity::getVelocityY() {
	return velocityY;
}
Size Entity::getSize() {
	return size;
}
void Entity::setSize(float width, float height) {
	size.width = width;
	size.height = height;
}
void Entity::update(float dt) {
	velocityY += gravity * dt;
	pos.y += velocityY * dt;
}
void Entity::draw(sf::RenderWindow& window) {
	// Base entity does not have a visual representation
}
