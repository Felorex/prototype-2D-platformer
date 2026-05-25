#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

#include <SFML/Graphics.hpp>



class Player: public Entity {
public:
	Player();
	void update(float dt) override;
	void jump();
	void draw(sf::RenderWindow& window) override;
	void creep() override;
	void setIsCreeping(bool creeping) override;
	void drRect();
	bool getIsInteracting();
	void setIsInteracting(bool interact);
	float getSpeed() override;
	float getCreepSize();
	float getDogsTerritory();
private:
	float dogsTerritory;
	float normalSpeed;
	bool isInteracting;
	float jumpForce;
	sf::RectangleShape rect; 
	
};
#endif // !PLAYER_H
