#include "Player.h"


Player::Player() {
	isCreeping = false;
	jumpForce = -500.f;
	size.width = 60.f;
	size.height = 60.f;
	normalHeight = size.height;
	creepHeight = size.height / 2;
	rect.setSize(sf::Vector2f(size.width, size.height));
	pos.x = 50.f;
	pos.y = 800.f;

	isInteracting = false;
	normalSpeed = 200.f;
	dogsTerritory = 1380.f;
}
float Player::getDogsTerritory() {
	return dogsTerritory;
}
float Player::getSpeed() {
	return normalSpeed;
}
void Player::jump() {
	if (isOnGround) {
		velocityY = jumpForce;
		isOnGround = false;
	}
}
void Player::update(float dt) {
	velocityY += gravity * dt;

	pos.y += velocityY * dt;

	rect.setPosition(pos.x,pos.y);
	rect.setFillColor(sf::Color::Red);
}
void Player::drRect() {
	rect.setPosition(pos.x, pos.y);
	rect.setFillColor(sf::Color::Red);
}
void Player::setIsCreeping(bool creeping) {
	isCreeping = creeping;
	creep();
}
void Player::creep() {
	if (isCreeping) {
		setSize(size.width, creepHeight);
		rect.setSize(sf::Vector2(size.width, creepHeight));
	}
	else {
		setSize(size.width, normalHeight);
		rect.setSize(sf::Vector2(size.width, normalHeight));
	}
}
void Player::setIsInteracting(bool interact) {
	isInteracting = interact;
}
bool Player::getIsInteracting() {
	return isInteracting;
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(rect);
}
float Player::getCreepSize() {
	return creepHeight;
}
