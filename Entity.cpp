#include "Entity.h"

Entity::Entity() {
	isOnGround = false;
	velocityY = 0;
	velocityX = 0;
	gravity = 1000.f;
	previousPos = getPosition();
	futurePos = getPosition();
	framMoveX = 0;
}
Position Entity::getPosition() {
	return pos;
}
void Entity::setPosition(float x, float y) {
	pos.x = x;
	pos.y = y;
}
void Entity::move(float dx) {
	velocityX = dx;
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
	previousPos = getPosition();
	futurePos.x = pos.x + velocityX * dt;
	framMoveX = velocityX * dt;
	velocityY += gravity * dt;
	pos.y += velocityY * dt;
	pos.x += framMoveX;
}
void Entity::draw(sf::RenderWindow& window) {
	// Base entity does not have a visual representation
}
void Entity::creep() {
	if (isCreeping) {
		setSize(size.width, creepHeight);
	}
	else {
		setSize(size.width, normalHeight);
	}
}
void Entity::setIsCreeping(bool creep) {
	isCreeping = creep;
}
bool Entity::getIsCreeping() {
	return isCreeping;
}
float Entity::getFrameMoveX() {
	return framMoveX;
}
