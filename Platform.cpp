#include "Platform.h"

Platform::Platform(float x, float y, float width, float height) {
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(width, height));
	shape.setFillColor(sf::Color::Yellow);
}

void Platform::draw(sf::RenderWindow& window) {
	window.draw(shape);
}