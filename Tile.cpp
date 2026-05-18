#include "Tile.h"

Tile::Tile() {
	isSolid = false;
	canCreep = false;
	type = EMPTY;
}

TileType Tile::getType() {
	return type;
}
void Tile::setType(TileType type) {
	this->type = type;
}