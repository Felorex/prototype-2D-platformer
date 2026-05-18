#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"

#include <vector>
#include <SFML/Graphics.hpp>


enum {

};

class TileMap {
	std::vector<std::vector<Tile>> tiles;
	int width;
	int height;
	TileType type;

public:
	int getWorldWidth();
	int getWorldHeight();
	const int TILE_SIZE = 32;
	TileMap(int x, int y);
	bool inside(int x, int y) const;
	Tile& getTile(int x, int y);
	void floor();
	void walls();
	void platform(int x, int y, float width, float height);
	void setCreepZone(int x, int y, float width, float height);
	void Doghouse(int x, int y, float width, float height);
	void drawMap(sf::RenderWindow& window);
	TileType getType(int x,int y);
};
#endif // !TILEMAP_H
