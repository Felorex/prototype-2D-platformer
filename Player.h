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
	void creep();
	void drRect();
	void setIsCreeping(bool creep);
	bool getIsCreeping();
	bool getIsInteracting();
	void setIsInteracting(bool interact);
	float getNormalSpeed();
	float deltaX;
	float getCreepSize();
private:
	float normalSpeed;
	float normalHeight;
	float creepHeight;
	bool isCreeping;
	bool isInteracting;
	float jumpForce;
	sf::RectangleShape rect; 
	
};
#endif // !PLAYER_H
