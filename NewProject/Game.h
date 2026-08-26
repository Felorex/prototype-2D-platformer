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
#include "Dog.h"
#include "Item.h"


enum GameState {
	MAINMENU,
	INTRO,
	PLAY,
	GAMEOVER,
	WIN
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

	void EnemyStartRush();
	void CanCatch();

	void checkDogEvent();
	bool InsideDoghouse(Entity& entity);
	void autoDogEvent();
	void canBit();
	void distractDog();

	bool pressedF();
	bool canUsingItem();

	void creepLogic();
	void CreepLogicDog();

	void PrintMenu(sf::RenderWindow& window);
	void HandleInputMenu();
	
	void CheckOpenExit();
	void PrintExit();
	void LevelEscape();
	void GameOver(sf::RenderWindow& window);

	void WinGame(sf::RenderWindow& window);

private:
	GameState state;
	Player player;
	Enemy enemy;
	DynamicObject object;
	TileMap map;
	Camera camera;
	InteractionSystem interact;
	Dog dog;
	Item item;

	sf::Clock deltaClock;
	sf::Clock GameOverClock;

	sf::Font font;

	bool intro;
	bool IsExitOpen;
	bool isPressF;

	

	int selectBut;
};


#endif // !GAME_H
