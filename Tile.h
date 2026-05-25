#ifndef TILE_H
#define TILE_H

enum TileType {
	WALLS,
	CRAWLWAY,
	EMPTY,
	DOGHOUSE,
	DOGHOUSE_INSIDE,
	DOGHOUSE_ROOF
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
