#include "InteractionSystem.h"

bool InteractionSystem::canInteract(Player& player, DynamicObject& object) {
	Position p = player.getPosition();
	Size ps = player.getSize();
	Position o = object.getPosition();
	Size os = object.getSize();
	float rightSideP = p.x + ps.width;
	float leftSideP = p.x;
	float rightSideO = o.x + os.width;
	float leftSideO = o.x;
	float bottomP = p.y + ps.height;
	float bottomO = o.y + os.height;
	if (equal(bottomP, bottomO) && (equal(leftSideP, rightSideO) || equal(rightSideP, leftSideO))) {
		return true;
	}
	else {
		return false;
	}
}

bool InteractionSystem::playerInsideTerritory(Player& player, Dog& dog) {
	Position p = player.getPosition();
	Size sp = player.getSize();

	float rightP = p.x + sp.width;
	float leftP = p.x;

	if (rightP > dog.getLimitTerritory() || leftP > dog.getLimitTerritory()) {
		return true;
	}
	return false;
}
bool InteractionSystem::canBiting(Player& player, Dog& dog) {
	Position p = player.getPosition();
	Position d = dog.getPosition();
	Size sp = player.getSize();
	Size sd = dog.getSize();

	float dogLeft = d.x;
	float dogRight = d.x + sd.width;
	float dogBottom = d.y + sd.height;

	float playerLeft = p.x;
	float playerRight = p.x + sp.width;
	float playerBottom = p.y + sp.height;

	float distance = std::abs(playerLeft - dogLeft);

	if (playerInsideTerritory(player, dog) && equal(playerBottom, dogBottom) && distance < 30) {
		return true;
	}
	return false;
}
