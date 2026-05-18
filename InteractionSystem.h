#ifndef INTRACTIONSYSTEM_H
#define INTRACTIONSYSTEM_H

#include "Player.h"
#include "DynamicObject.h"

static bool equal(float a, float b, float epsilon = 1.f) {
	return std::abs(a - b) < epsilon;
}

class InteractionSystem {
public:
	bool canInteract(Player& player, DynamicObject& object);
	bool canRightInteract(Player& player, DynamicObject& object);
};
#endif // !INTRACTIONSYSTEM_H
