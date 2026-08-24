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
	scared = false;
	isInteracting = false;
	normalSpeed = 200.f;
	scaredSpeed = 260.f;
	dogsTerritory = 1300.f;

	
}
float Player::getDogsTerritory() {
	return dogsTerritory;
}
float Player::getSpeed() {
	if (scared) {
		return scaredSpeed;
	}
	return normalSpeed;
}
void Player::jump() {
	if (isOnGround) {
		velocityY = jumpForce;
		isOnGround = false;
	}
}
void Player::update(float dt) {
	Entity::update(dt);

	autoMoveToSafePlace();
	takingItem();
	moveWithItem();

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
bool Player::getIsScared() {
	return scared;
}
void Player::setIsScared(bool scared) {
	this->scared = scared;
}
void Player::autoMoveToSafePlace() {
	if (scared) {
		move(-getSpeed());
		if (pos.x <= dogsTerritory) {
			move(0.f);
		}
	}	
}

/*
Item* Player::getTargetItem() {
	if (targetItem != nullptr) {
		return targetItem;
	}
	return nullptr;
}

void Player::takingItem() {
	if (targetItem != nullptr && targetItem->getState() == TAKING) {
		Position targetPos = targetItem->getPosition();
		targetItem->isTaking(takenItemSpeed);
		float playerLeft = pos.x;
		float playerRight = pos.x + size.width;
		float playerTop = pos.y;
		float itemLeft = targetPos.x;
		float itemRight = targetPos.x + targetItem->getSize().width;
		float itemTop = targetPos.y;

		distanceItem = itemLeft - playerLeft;

		if (targetPos.y <= playerTop + 10.f) {
			targetItem->isTaking(0.f);
			targetItem->setState(TAKEN);
		}
	}
}
void Player::moveWithItem() {
	if (takenItem()) {
		Position targetPos = targetItem->getPosition();
		float playerLeft = pos.x;
		float playerRight = pos.x + size.width;
		float itemLeft = targetPos.x;
		float itemRight = targetPos.x + targetItem->getSize().width;
		targetItem->setPosition(pos.x + distanceItem, pos.y + 10.f);
	}
}
bool Player::takenItem() {
	if (targetItem != nullptr && targetItem->getState() == TAKEN) {
		return true;
	}
	return false;
}
void Player::setTargetItem(Item* item) {
	if (item != nullptr) {
		targetItem = item;
	}
	else {
		targetItem = nullptr;
	}
}
*/
