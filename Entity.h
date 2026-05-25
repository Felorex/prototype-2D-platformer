#ifndef ENFITY_H
#define ENFITY_H

#include <SFML/Graphics.hpp>
//sf::Clock clock;
//float deltaTime = clock.restart().asSeconds();


struct Position{
	float x = 0;
	float y = 0;
};
struct Size{
	float width = 0;
	float height = 0;
};


class Entity {
	public:
		Entity();
		Position getPosition();		
		void setPosition(float x, float y);
		Size getSize();
		void setSize(float width, float height);
		void move(float dx);
		virtual void update(float dt);
		virtual void draw(sf::RenderWindow& window);
		void setOnGround(bool ground);
		void setVelocityY(float v);
		float getVelocityY();
		Position previousPos;
		Position futurePos;
		virtual void creep();
		virtual void setIsCreeping(bool creeping);
		bool getIsCreeping();
		virtual float getSpeed() = 0;
protected:
	    Size size;
	    Position pos;
		float velocityY;
		float gravity;
		bool isOnGround;
		float normalHeight;
		float creepHeight;
		bool isCreeping;
};
#endif // !ENFITY_H
