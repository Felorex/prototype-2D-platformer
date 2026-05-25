#ifndef INTRACTIONSYSTEM_H
#define INTRACTIONSYSTEM_H

#include "Player.h"
#include "DynamicObject.h"
#include "Dog.h"

static bool equal(float a, float b, float epsilon = 1.f) {
	return std::abs(a - b) < epsilon;
}

class InteractionSystem {
public:
	bool canInteract(Player& player, DynamicObject& object);
	bool canBiting(Player& player, Dog& dog);
};
#endif // !INTRACTIONSYSTEM_H
