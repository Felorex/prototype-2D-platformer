#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Player.h"
#include "TileMap.h"
#include "Camera.h"
#include "Enemy.h"
#include "Dog.h"
#include "DynamicObject.h"
#include "InteractionSystem.h"



enum GameState {
	INTRO,
	PLAY
};

class Game {
public:
	Game();	
	void input();
	void drawGame(sf::RenderWindow& window);
	void play();
	void update(float dt);
	bool canMoveLeft(Entity& entity);
	bool canMoveRight(Entity& entity);
	bool canMoveRightObject(DynamicObject& object);
	bool canMoveLeftObject(DynamicObject& object);
	bool canJump();
	void creep();
	bool canCreep();
	void autoMovePlayer(float dt);
	void checkCollision(Entity& entity);
	void checkCollisionForObjects(Entity& e1, Entity& e2);
	bool canInteraction(Player& player,DynamicObject& object);
	bool canStandUp(Entity& entity);

	void checkDogEvent();
	bool InsideDoghouse(Entity& entity);
	void autoDogEvent();
	void canBit();

	void creepLogic();
	void CreepLogicDog();
private:
	GameState state;
	Player player;
	Enemy enemy;
	DynamicObject object;
	TileMap map;
	Camera camera;
	InteractionSystem interact;
	Dog dog;
	sf::Clock deltaClock;

	bool intro;
};

#endif // !GAME_H
