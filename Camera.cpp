#include "Camera.h"

Camera::Camera() {
	x = 0;
	y = 0;
}
void Camera::initCamera(sf::RenderWindow& window) {
	view = window.getDefaultView();
}
void Camera::updateCamera(Position playerPosition, TileMap& map) {
	float halfWidth = size.width / 2;
	float halfHeight = size.height / 2;
	x = playerPosition.x;
	y = playerPosition.y;
	if (map.getWorldWidth() < size.width) {
		x = map.getWorldWidth() / 2;
	}
	else {
		if (x < halfWidth)x = halfWidth;
		if (x > map.getWorldWidth() - halfWidth)x = map.getWorldWidth() - halfWidth;
	}
	if (map.getWorldHeight() < size.height) {
		y = map.getWorldHeight() / 2;
	}
	else {
		if (y < halfHeight)y = halfHeight;
		if (y > map.getWorldHeight() - halfHeight)y = map.getWorldHeight() - halfHeight;
	}	
	view.setCenter(x, y);
}
void Camera::apply(sf::RenderWindow& window) {	
	window.setView(view);
}