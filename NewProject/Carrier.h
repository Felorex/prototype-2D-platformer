#ifndef CARRIER_H
#define CARRIER_H

#include "Item.h"
#include "Entity.h"

class Carrier : public Entity {
public:
	Carrier();

	void takingItem();
	bool takenItem();
	Item* getTargetItem();

	void moveWithItem();

	void setTargetItem(Item* item);

protected:
	Item* targetItem;
	float takenItemSpeed;
	float distanceItem;
};

#endif // !CARRIER_H
