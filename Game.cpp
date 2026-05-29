#include "Game.h"

#include <iostream>

Game::Game(): player(), map(64,30) {
	state = INTRO;
	intro = true;
	map.floor();
	map.walls();
	map.platform(20, 15, 2, 13);
	map.setCreepZone(20, 28, 3, 1);
	map.Doghouse(59, 25, 4, 4);
	//deltaX = 0;
	//map.platform(0, 15, 15, 7);
	//map.platform(15, 19, 1, 3);
	//map.platform(16, 19, 3, 1);
	//map.platform(14, 18, 2, 1);
}
void Game::autoMovePlayer(float dt) {
	if (intro) {
		if (canMoveRight(player)) {
			player.move(player.getSpeed()); 
			Position p = player.getPosition();
			if (p.x >= 500) {
				player.move(0.f);
				intro = false;
				state = PLAY;
			}
		}
	}	
}
void Game::input() {
	player.move(0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {		
		if (canInteraction(player, object) && canMoveRightObject(object) && canMoveRight(player)) {
			player.move(player.getSpeed());
			object.move(player.getSpeed());
		}
		else {
			if (canInteraction(player, object) && !canMoveRightObject(object)) {
				player.move(0.f);
			}
			else {
				if (canMoveRight(player)) {
					player.move(player.getSpeed());
				}				
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		
		if (canInteraction(player, object) && canMoveLeftObject(object) && canMoveLeft(player)) {
			player.move(-player.getSpeed());
			object.move(-player.getSpeed());
		}
		else {
			if (canInteraction(player, object) && !canMoveLeftObject(object)) {
				player.move(0.f);
			}
			else {
				if (canMoveLeft(player)) {
					player.move(-player.getSpeed());
				}	
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump()) {
		player.jump();
	}	
}
void Game::creepLogic() {
	if (canCreep() || !canStandUp(player)) {
		player.setIsCreeping(true);
	}
	else {
		player.setIsCreeping(false);
	}
}
void Game::CreepLogicDog() {
	if (InsideDoghouse(dog)) {
		dog.setIsCreeping(true);
	}
	else {
		dog.setIsCreeping(false);
	}	
}
void Game::drawGame(sf::RenderWindow& window) {
	window.clear();
	camera.apply(window);
	map.drawMap(window);
	object.draw(window);
	player.draw(window);
	enemy.draw(window);	
	dog.draw(window);

	window.display();
}
void Game::update(float dt) {
	player.update(dt);
	enemy.update(dt);
	object.update(dt);
	dog.update(dt);
	checkCollision(player);
	checkCollision(enemy);
	checkCollision(object);
	checkCollision(dog);
	canMoveLeft(enemy);
	canMoveRight(enemy);
	canMoveLeft(object);
	canMoveRight(object);
	canMoveLeft(dog);
	canMoveRight(dog);


	creepLogic();
	CreepLogicDog();
	checkDogEvent();
	canBit();

	checkCollisionForObjects(player, object);
	camera.updateCamera(player.getPosition(), map);
}
void Game::checkCollision(Entity& entity) {
	Position p = entity.getPosition();
	Size s = entity.getSize();
	int leftTileX = p.x / map.TILE_SIZE;
	int rightTileX = (p.x + s.width - 1) / map.TILE_SIZE;
	int tileY = (p.y + s.height - 1) / map.TILE_SIZE;	
	float top = tileY * map.TILE_SIZE;
	bool insideLeft = map.inside(leftTileX, tileY);
	bool insideRight = map.inside(rightTileX, tileY);
	TileType Left = map.getType(leftTileX, tileY);
	TileType Right = map.getType(rightTileX, tileY);

	bool floor = (insideLeft || insideRight) && (Left == WALLS || Right == WALLS) || (Left == DOGHOUSE_ROOF || Right == DOGHOUSE_ROOF);

	if (floor) {
		entity.setPosition(p.x, top - s.height);
		entity.setVelocityY(0);
		entity.setOnGround(true);
	}
	else{
	//else if(player.getVelocityY() > 0 && ((!map.inside(leftTileX, tileY)||!map.inside(rightTileX,tileY)) || 
	//	(!map.getTile(leftTileX, tileY).isSolid)||!map.getTile(rightTileX, tileY).isSolid)) {
		entity.setOnGround(false);
	}
}
void Game::checkCollisionForObjects(Entity& e1, Entity& e2) {
	Position p1 = e1.getPosition();
	Position p2 = e2.getPosition();
	Size s1 = e1.getSize();
	Size s2 = e2.getSize();
	float top1 = p1.y;
	float top2 = p2.y; 
	float bottom1 = p1.y + s1.height;
	float bottom2 = p2.y + s2.height;
	float left1 = p1.x;
	float left2 = p2.x;
	float right1 = p1.x + s1.width;
	float right2 = p2.x + s2.width;

	float prv1 = e1.previousPos.y + s1.height;

	float falling = bottom1 - top2;
	bool overlapX = right1 > left2 && left1 < right2;

	bool landedFromTop = e1.getVelocityY() > 0 && prv1 <= top2 && bottom1 >= top2 && overlapX && falling < 10.f;

	if (landedFromTop){
		e1.setPosition(p1.x, top2 - s1.height);
		e1.setVelocityY(0);
		e1.setOnGround(true);
	}
}
bool Game::canMoveLeft(Entity& entity) {
	Position p = entity.getPosition();
	Size s = entity.getSize();
	float dx = - 2;
	int tileX = (p.x + dx - 1) / map.TILE_SIZE;
	int tileTop = (p.y - 1) / map.TILE_SIZE;
	int tileBottom = (p.y + s.height - 2) / map.TILE_SIZE;

	bool insideTop = map.inside(tileX, tileTop);
	bool insideBottom = map.inside(tileX, tileBottom);

	TileType top = map.getType(tileX, tileTop);
	TileType bottom = map.getType(tileX, tileBottom);

	bool wall = (insideTop || insideBottom) && (top == WALLS || bottom == WALLS);
	bool crawlway = (insideTop || insideBottom) && (top == CRAWLWAY || bottom == CRAWLWAY);
	bool doghouse = (insideTop || insideBottom) && (top == DOGHOUSE || bottom == DOGHOUSE || top == DOGHOUSE_ROOF || bottom == DOGHOUSE_ROOF);
	bool doghouseInside = (insideTop && insideBottom) && (top == DOGHOUSE_INSIDE || bottom == DOGHOUSE_INSIDE);


	if (wall || doghouse) {
		return false;
	}
	if ((crawlway || doghouseInside) && !entity.getIsCreeping()) {
		return false;
	}
	return true;
}
bool Game::canMoveRight(Entity& entity) {
	Position p = entity.getPosition();
	Size s = entity.getSize();
	float dx = 2;
	int tileX = (p.x + s.width + dx) / map.TILE_SIZE;
	int tileTop = (p.y - 1) / map.TILE_SIZE;
	int tileBottom = (p.y + s.height - 2) / map.TILE_SIZE;
	bool insideTop = map.inside(tileX, tileTop);
	bool insideBottom = map.inside(tileX, tileBottom);

	TileType top = map.getType(tileX, tileTop);
	TileType bottom = map.getType(tileX, tileBottom);

	bool wall = (insideTop || insideBottom) && (top == WALLS || bottom == WALLS);
	bool crawlway = (insideTop || insideBottom) && (top == CRAWLWAY || bottom == CRAWLWAY);
	bool doghouse = (insideTop || insideBottom) && (top == DOGHOUSE || bottom == DOGHOUSE || top == DOGHOUSE_ROOF || bottom == DOGHOUSE_ROOF);
	bool doghouseInside = (insideTop && insideBottom) && (top == DOGHOUSE_INSIDE || bottom == DOGHOUSE_INSIDE);

	if (wall || doghouse) {
		return false;
	}
	if ((crawlway || doghouseInside) && !entity.getIsCreeping()) {
		return false;
	}
	return true;
}
 
bool Game::canMoveRightObject(DynamicObject& object) {
	Position o = object.getPosition();
	Size os = object.getSize();
	float futObjX = o.x + os.width + object.getFrameMoveX();
	
	int tileX = futObjX / map.TILE_SIZE;
	int tileTop = (o.y - 1) / map.TILE_SIZE;
	int tileBottom = (o.y + os.height - 1) / map.TILE_SIZE;
	bool insideTop = map.inside(tileX, tileTop);
	bool insideBottom = map.inside(tileX, tileBottom);

	TileType top = map.getType(tileX, tileTop);
	TileType bottom = map.getType(tileX, tileBottom);

	bool wall = (insideTop && insideBottom) && (top == WALLS || bottom == WALLS);
	bool doghouse = (insideTop && insideBottom) && (top == DOGHOUSE || bottom == DOGHOUSE);
	

	if (wall || doghouse) {
		return false;
	}
	return true;
} 
bool Game::canMoveLeftObject(DynamicObject& object) {
	Position o = object.getPosition();
	Size os = object.getSize();
	float futObjX = o.x - object.getFrameMoveX();

	int tileX = futObjX / map.TILE_SIZE;
	int tileTop = (o.y - 1) / map.TILE_SIZE;
	int tileBottom = (o.y + os.height - 1) / map.TILE_SIZE;
	bool insideTop = map.inside(tileX, tileTop);
	bool insideBottom = map.inside(tileX, tileBottom);

	TileType top = map.getType(tileX, tileTop);
	TileType bottom = map.getType(tileX, tileBottom);

	bool wall = (insideTop && insideBottom) && (top == WALLS || bottom == WALLS);

	if (wall) {
		return false;
	}
	return true;
}


bool Game::canJump() {
	Position p = player.getPosition();
	Size s = player.getSize();
	int leftTileX = (p.x - 1) / map.TILE_SIZE;
	int rightTileX = (p.x + s.width - 1) / map.TILE_SIZE;
	int tileY = (p.y - 1) / map.TILE_SIZE;
	bool insideLeft = map.inside(leftTileX, tileY);
	bool insideRight = map.inside(rightTileX, tileY);
	bool solidLeft = insideLeft && map.getType(leftTileX, tileY) == WALLS;
	bool solidRight = insideRight && map.getType(rightTileX, tileY) == WALLS;
	if (solidLeft || solidRight) {
		player.setVelocityY(0);
		return false;
	}
	else {
		return true;
	}
}
void Game::creep() {
	Position p = player.getPosition();
	Size s = player.getSize();
	player.creep();
	float legs = p.y + s.height;
	player.setPosition(p.x, legs - player.getSize().height);
}
bool Game::canCreep() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
		return true;
	}
	return false;
}

bool Game::canStandUp(Entity& entity) {
	Position p = entity.getPosition();
	Size s = entity.getSize();
	int leftTileX = (p.x - 1) / map.TILE_SIZE;
	int rightTileX = (p.x + s.width - 1) / map.TILE_SIZE;
	int tileY = (p.y - 1) / map.TILE_SIZE;

	if ((!map.inside(leftTileX, tileY - 1) || (map.getType(leftTileX, tileY - 1) != EMPTY)) || 
		(!map.inside(rightTileX, tileY - 1) || (map.getType(rightTileX, tileY - 1) != EMPTY))) {
		return false;
	}
	else {
		return true;
	}
}
bool Game::canInteraction(Player& player, DynamicObject& object) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && interact.canInteract(player, object)) {
		player.setIsInteracting(true);
		return true;
	}
	player.setIsInteracting(false);
	return false;
}

void Game::checkDogEvent() {
	dog.setTarget(&player);
	if (interact.playerInsideTerritory(player, dog)) {
		if (dog.getDogState() != RUNNING) {
			dog.setDogState(RUNNING);
		}
	}
}
void Game::autoDogEvent() {
	if ((player.getIsScared() == true) && (player.getPosition().x <= player.getDogsTerritory())) {
		player.setIsScared(false);
		state = PLAY;
	}	
}
void Game::canBit() {
	dog.setTarget(&player);
	if (interact.canBiting(player, dog)) {
		player.setIsScared(true);
		state = INTRO;
	}
}

bool Game::InsideDoghouse(Entity& entity) {
	Position p = entity.getPosition();
	Size s = entity.getSize();

	int leftSide = (p.x - 1) / map.TILE_SIZE;
	int rightSide = (p.x + s.width - 1) / map.TILE_SIZE;
	int sideY = (p.y + s.height - 1) / map.TILE_SIZE;

	bool insideLeft = map.inside(leftSide, sideY);
	bool insideRight = map.inside(rightSide, sideY);

	bool doghouse = (insideLeft || insideRight) && (map.getType(leftSide, sideY) == DOGHOUSE_INSIDE || map.getType(rightSide, sideY) == DOGHOUSE_INSIDE);

	if (doghouse) {
		return true;
	}
	return false;
}

void Game::play() {
	windowSize size;
	sf::RenderWindow window(sf::VideoMode(size.width, size.height), "Test");

	camera.initCamera(window);

	while (window.isOpen()) {
		sf::Event event;
		float dt = deltaClock.restart().asSeconds();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		if (state == INTRO) {
			//rushEnemy();
			autoMovePlayer(dt);
			autoDogEvent();
		}
		if (state == PLAY) {
			input();
			
			//player.deltaX = player.getPosition().x - player.previousPos.x;
		}
		//player.drRect();
		update(dt);
		drawGame(window);
	}
}
