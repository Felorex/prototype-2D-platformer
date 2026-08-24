#include "Carrier.h"

Carrier::Carrier() {
	targetItem = nullptr;
	takenItemSpeed = -150.f;
	distanceItem = 0.f;
}

void Carrier::takingItem() {
	if (targetItem != nullptr && targetItem->getState() == TAKING) {
		Position targetPos = targetItem->getPosition();
		targetItem->isTaking(takenItemSpeed);
		float entityLeft = pos.x;
		float entityRight = pos.x + size.width;
		float entityTop = pos.y;
		float itemLeft = targetPos.x;
		float itemRight = targetPos.x + targetItem->getSize().width;
		float itemTop = targetPos.y;

		distanceItem = itemLeft - entityLeft;

		if (targetPos.y <= entityTop + 10.f) {
			targetItem->isTaking(0.f);
			targetItem->setState(TAKEN);
		}
	}
}
void Carrier::moveWithItem() {
	if (takenItem()) {
		Position targetPos = targetItem->getPosition();
		float entityLeft = pos.x;
		float entityRight = pos.x + size.width;
		float itemLeft = targetPos.x;
		float itemRight = targetPos.x + targetItem->getSize().width;
		targetItem->setPosition(pos.x + distanceItem, pos.y + 10.f);
	}
}
bool Carrier::takenItem() {
	if (targetItem != nullptr && targetItem->getState() == TAKEN) {
		return true;
	}
	return false;
}
void Carrier::setTargetItem(Item* item) {
	if (item != nullptr) {
		targetItem = item;
	}
	else {
		targetItem = nullptr;
	}
}
Item* Carrier::getTargetItem() {
	if (targetItem != nullptr) {
		return targetItem;
	}
	return nullptr;
}
