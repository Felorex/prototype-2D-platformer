#include "TileMap.h"

#include <SFML/Graphics.hpp>

TileMap::TileMap(int x, int y) {
	width = x;
	height = y;

	type = EMPTY;

	tiles.resize(height, std::vector<Tile>(width));
}
int TileMap::getWorldWidth() {
	return width * TILE_SIZE;
}
int TileMap::getWorldHeight() {
	return height * TILE_SIZE;
}
bool TileMap::inside(int x, int y) const{
	return x >= 0 && x < width && y >= 0 && y < height;
}

Tile& TileMap::getTile(int x, int y) {
	if (!inside(x,y)) {
		static Tile solidTile;
		solidTile.setType(WALLS);
		return solidTile;
	}
	return tiles[y][x];
}
TileType TileMap::getType(int x, int y) {
	if (!inside(x, y)) {
		return WALLS;
	}
	return tiles[y][x].getType();
}
void TileMap::floor() {
	for (int x = 0; x < width; x++) {
		tiles[height - 1][x].setType(WALLS);
	}
}
void TileMap::walls() {
	for (int y = 0; y < height; y++) {
		tiles[y][width - 1].setType(WALLS);
		tiles[y][0].setType(WALLS);
	}
}
void TileMap::platform(int x, int y, float width, float height) {
	int startX = x;
	int startY = y;
	int endX = static_cast<int>(x + width);
	int endY = static_cast<int>(y + height);
	for (int i = startY; i < endY; i++) {
		for (int j = startX; j < endX; j++) {
			if (inside(j,i)) {
				tiles[i][j].setType(WALLS);
			}
		}
	}
}
void TileMap::setCreepZone(int x, int y, float width, float height) {
	int startX = x;
	int startY = y;
	int endX = static_cast<int>(x + width);
	int endY = static_cast<int>(y + height);
	for (int i = startY; i < endY; i++) {
		for (int j = startX; j < endX; j++) {
			if (inside(j, i)) {
				tiles[i][j].setType(CRAWLWAY);
			}
		}
	}
}
void TileMap::Doghouse(int x, int y, float width, float height) {
	int startX = x;
	int startY = y;
	int endX = static_cast<int>(x + width);
	int endY = static_cast<int>(y + height);
	for (int i = startY; i < endY; i++) {
		for (int j = startX; j < endX; j++) {
			if (inside(j, i)) {
				tiles[i][j].setType(DOGHOUSE);
			}
		}
	}
}
void TileMap::drawMap(sf::RenderWindow& window){
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (tiles[y][x].getType() == WALLS) {
				rect.setFillColor(sf::Color::Green);
			}
			else if (tiles[y][x].getType() == CRAWLWAY) {
				rect.setFillColor(sf::Color::White);
			}
			else if (tiles[y][x].getType() == DOGHOUSE) {
				rect.setFillColor(sf::Color::Cyan);
			}
			else {
				rect.setFillColor(sf::Color::Blue);
			}
			rect.setPosition(x * TILE_SIZE, y * TILE_SIZE);
			window.draw(rect);
		}
	}
}

