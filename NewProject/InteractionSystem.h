#ifndef INTRACTIONSYSTEM_H
#define INTRACTIONSYSTEM_H

#include "Player.h"
#include "DynamicObject.h"
#include "Dog.h"
#include "Item.h"


static bool equal(float a, float b, float epsilon = 2.f) {
	return std::abs(a - b) < epsilon;
}

class InteractionSystem {
public:
	bool canInteract(Player& player, DynamicObject& object);
	bool playerInsideTerritory(Player& player, Dog& dog);
	bool canBiting(Player& player, Dog& dog);

	bool canTakeItem(Entity& player, Item& item);

	bool itemInsideDogTerritory(Dog& dog, Item& item);
};
#endif // !INTRACTIONSYSTEM_H
