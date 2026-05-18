#include "InteractionSystem.h"

/* 
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
	if (equal(bottomP,bottomO)&&((leftSideP<=rightSideO)&&(rightSideP>=leftSideO))) {
		return true;
	}
	else {
		return false;
	}		
}
*/
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
