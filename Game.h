#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Player.h"
#include "TileMap.h"
#include "Camera.h"
#include "Enemy.h"
#include "DynamicObject.h"
#include "InteractionSystem.h"



enum GameState {
	INTRO,
	PLAY
};

class Game {
public:
	Game();	
	void input(float dt);
	void drawGame(sf::RenderWindow& window);
	void play();
	void update(float dt);
	bool canMoveLeft(Entity& entity);
	bool canMoveRight(Entity& entity, float dt);
	bool canMoveRightObject(DynamicObject& object, float dt);
	bool canMoveLeftObject(DynamicObject& object);
	bool canJump();
	void creep();
	bool canCreep();
	void autoMovePlayer(float dt);
	void checkCollision(Entity& entity);
	void checkCollisionForObjects(Entity& e1, Entity& e2);
	bool canInteraction(Player& player,DynamicObject& object);
	bool canCrawlThrough();
	bool canStandUp(Player& player);

private:
	GameState state;
	Entity entity;
	Player player;
	Enemy enemy;
	DynamicObject object;
	TileMap map;
	Camera camera;
	InteractionSystem interact;
	sf::Clock deltaClock;

};
#endif // !GAME_H
