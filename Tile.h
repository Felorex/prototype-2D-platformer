#ifndef TILE_H
#define TILE_H

enum TileType {
	WALLS,
	CRAWLWAY,
	EMPTY,
	DOGHOUSE
};

class Tile {
public:
	TileType getType();
	void setType(TileType type);
	bool isSolid;
	bool canCreep;
	Tile();

private:
	TileType type;
};
#endif // !TILE
