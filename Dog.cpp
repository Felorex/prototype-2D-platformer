#include "Dog.h"


Dog::Dog() {
	state = SITTING;
	isCreeping = true;
	size.width = 60;
	size.height = 60;
	normalHeight = size.height;
	creepHeight = size.height / 2;
	pos.x = 1940;
	pos.y = 800;
	creepSpeed = 160.f;
	runningSpeed = 195.f;
	distance = 500.f;
	limitTerritory = 1440.f;
	startX = pos.x;
	rotation = 0.f;
	animationTimer = 0.f;
	visualOffsetY = 0.f;
	rect.setOrigin(size.width / 2.f, size.height / 2.f);
	target = nullptr;
}

float Dog::getSpeed() {
	if (isCreeping) {
		return creepSpeed;
	}
	return runningSpeed;
}

void Dog::update(float dt) { 
	Entity::update(dt);

	switch (state) {
	case SITTING:
		creep();
		break;
	case BARKING:
		barking(dt);
		startAlert(dt);
		break;
	case RUNNING:
		following();
		cameLimitTerritory();
		break;
	case ALERT:
		alert();
	}
	
	rect.setPosition(pos.x + size.width / 2.f, pos.y + size.height / 2.f + visualOffsetY);
	rect.setFillColor(sf::Color::Magenta);
	rect.setRotation(rotation);

}
void Dog::draw(sf::RenderWindow& window) {
	window.draw(rect);
}
void Dog::barking(float dt) {
	if (std::abs(getLimitTerritory() - pos.x) < 3) {
		animationTimer += dt;
		rotation = 20 + std::sin(animationTimer * 20.f) * 5.f;

		visualOffsetY = -10.f;
	}	
}
void Dog::setTarget(Entity* entity) {
	if (entity != nullptr) {
		target = entity;
	}
}
void Dog::cameLimitTerritory() {
  Position targetPos = target->getPosition();
  if ((std::abs(getLimitTerritory() - pos.x) < 3) && targetPos.x < getLimitTerritory()) {
    move(0.f);
    state = BARKING;
  }
}
void Dog::following() {
  rotation = 0;
  visualOffsetY = 0;
  Position entityPos = target->getPosition();
  float distance = entityPos.x - pos.x;
  if (std::abs(distance) < 20) {
    move(0.f);
  }
  else if (distance < 0) {
    move(-getSpeed());
  }
  else {
    move(getSpeed());
  }
}
void Dog::startAlert(float dt) {
  Position targetPos = target->getPosition();
  if (state == BARKING && targetPos.x <= alertLimit) {
    visualOffsetY = 0.f;
    rotation = 0;
    alertTimer += dt;
    if (alertTimer > 3 ) {
      state = ALERT;
      alertTimer = 0.f;
    }    
  }
  else {
    alertTimer = 0.f;
  }
}
void Dog::alert() {
  move(getSpeed());
  if (std::abs(startX - pos.x) < 3) {
    state = SITTING;
    move(0.f);
  }
}
void Dog::setIsCreeping(bool creeping) {
	isCreeping = creeping;
	creep();
}
void Dog::creep() {
	if (isCreeping) {
		visualOffsetY = 15.f;
		setSize(size.width, creepHeight);
		rect.setSize(sf::Vector2(size.width, creepHeight));
	}
	else {
		visualOffsetY = 0.f;
		setSize(size.width, normalHeight);
		rect.setSize(sf::Vector2(size.width, normalHeight));
	}
}
void Dog::setDogState(DogState state) {
	this->state = state;
}
DogState Dog::getDogState() {
	return state;
}
float Dog::getDistance() {
	return distance;
}
float Dog::getStartX() {
	return startX;
}
float Dog::getLimitTerritory() {
	return limitTerritory;
}
