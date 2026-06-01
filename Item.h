#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

enum ItemState {
	NOT_TAKEN,
	TAKEN
};

class Item :public Entity {
public:
	Item();
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
	float getSpeed() override;
	ItemState getState();
	void setState(ItemState newState);
	void isTaken();

private:
	sf::RectangleShape shape;
	ItemState state;
};

#endif // !ITEM_H


