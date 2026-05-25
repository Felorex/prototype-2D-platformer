#include "Enemy.h"


Enemy::Enemy() {
	pos.x = 50.f;
	pos.y = 600.f;
	size.width = 25.f;
	size.height = 40.f;
	rushSpeedValue = 0.002f;
	horizontalSpeed = 0.82f;
	rect.setSize(sf::Vector2f(size.width, size.height));
}

void Enemy::update(float dt) {
	rushSpeed();
	//pos.x += horizontalSpeed;
	//horizontalSpeed -= rushSpeedValue;
	velocityY += gravity * dt;
	pos.y += velocityY * dt;

	rect.setPosition(pos.x, pos.y);
	rect.setFillColor(sf::Color::Yellow);
}
void Enemy::draw(sf::RenderWindow& window) {		
	window.draw(rect);
}
void Enemy::rushSpeed() {
	pos.x += horizontalSpeed;
	horizontalSpeed -= rushSpeedValue;
	if (horizontalSpeed <= 0) {
		horizontalSpeed = 0;
	}
}
float Enemy::getSpeed() {
	return horizontalSpeed -= rushSpeedValue;
	if (horizontalSpeed <= 0) {
		return 0;
	}
}
