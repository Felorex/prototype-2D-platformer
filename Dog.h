#ifndef DOG_H
#define DOG_H

#include "Entity.h"

enum DogState {
	SITTING,
	BARKING,
	RUNNING,
	BITING,
	DISTRACTED,
	ALERT
};

class Dog :public Entity {
public:
	Dog();
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
	void barking(float dt);
	void following();
	void cameLimitTerritory();
	void alert();
	void setIsCreeping(bool creeping) override;
	void creep() override;
	DogState getDogState();
	void setDogState(DogState state);
	float getSpeed() override;
	float getDistance();
	float getStartX();
	float getLimitTerritory();

	void setTarget(Entity* entity);

private:
	Entity* target;

	float startX;
	float distance;
	float limitTerritory;
	float creepSpeed;
	float runningSpeed;
	float rotation;
	float animationTimer;
	float visualOffsetY;
	DogState state;
	sf::RectangleShape rect;
};
#endif // !DOG_H
