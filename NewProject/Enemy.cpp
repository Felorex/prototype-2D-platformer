#include "Enemy.h"


Enemy::Enemy() {
	pos.x = 50.f;
	pos.y = 800.f;
	size.width = 35.f;
	size.height = 120.f;
	speed = 300.f;
	rect.setSize(sf::Vector2f(size.width, size.height));
	IsVisible = false;
}

void Enemy::update(float dt) {
	velocityY += gravity * dt;
	pos.y += velocityY * dt;

	pos.x += velocityX * dt;

	rect.setPosition(pos.x, pos.y);
	rect.setFillColor(sf::Color::Yellow);
}
void Enemy::setVisible(bool visible) {
	IsVisible = visible;
}
bool Enemy::getIsVisible() const {
	return IsVisible;
}
void Enemy::draw(sf::RenderWindow& window) {		
	if (IsVisible) {
		window.draw(rect);
	}
}

float Enemy::getSpeed() {
	return speed;
}