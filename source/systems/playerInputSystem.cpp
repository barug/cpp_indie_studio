//
// PlayerInputSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/systems
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Wed May 18 16:49:48 2016 Barthelemy Gouby
// Last update Sun Jun 12 12:10:37 2016 Thomas Bogard
//

#include <iostream>
#include "../Engine.hh"
#include "../components/SpeedComponent.hh"
#include "../components/PlayerInputComponent.hh"
#include "../components/ExplosiveComponent.hh"

void				Engine::playerInputSystem()
{
  std::vector<Entity*>		*playerEntities =
    this->_entityManager.getEntitiesWithComponents({Component::PLAYER_INPUT_COMPONENT, Component::SPEED_COMPONENT});
  std::vector<Entity*>		*bombs;
  std::vector<irr::EKEY_CODE>	*keysDown;
  SpeedComponent		*speedComponent;
  PositionComponent		*positionComponent;
  PlayerInputComponent		*playerInputComponent;
  ModelComponent		*modelComponent;
  Entity			*bomb;
  bool				canPlaceBomb;

  for (Entity *player: *playerEntities)
    {
      speedComponent = (SpeedComponent*) player->getComponent(Component::SPEED_COMPONENT);
      playerInputComponent = (PlayerInputComponent*) player->getComponent(Component::PLAYER_INPUT_COMPONENT);
      modelComponent = (ModelComponent*) player->getComponent(Component::MODEL_COMPONENT);
      keysDown = this->_display.getKeysDownForId(player->getId());
      speedComponent->setSpeedX(0);
      speedComponent->setSpeedY(0);
      if (this->_isDropped && this->_timerDrop < this->_display.getTimer())
	{
	  this->_timerDrop = 0;
	  this->_isDropped = false;
	}
      for (irr::EKEY_CODE key: *keysDown)
	{
	  if (key == playerInputComponent->getKeyUp())
	    speedComponent->setSpeedY(playerInputComponent->getSpeed());
	  else if (key == playerInputComponent->getKeyDown())
	    speedComponent->setSpeedY(-playerInputComponent->getSpeed());
	  else if (key == playerInputComponent->getKeyLeft())
	    speedComponent->setSpeedX(playerInputComponent->getSpeed());
	  else if (key == playerInputComponent->getKeyRight())
	    speedComponent->setSpeedX(-playerInputComponent->getSpeed());
	  else if (key == playerInputComponent->getKeyBomb()
		   && playerInputComponent->getActiveBombs() < playerInputComponent->getMaxBombs())
	    {
	      this->_isDropped = true;
	      this->_timerDrop = this->_display.getTimer() + 700;
	      this->_display.updateModel(player, ModelComponent::DROP);
	      bombs = this->_entityManager.getEntitiesWithComponents({Component::EXPLOSIVE_COMPONENT});
	      positionComponent = (PositionComponent*) player->getComponent(Component::POSITION_COMPONENT);
	      canPlaceBomb = true;
	      for (Entity *bomb: *bombs)
	  	{
	  	  if (this->_display.tileIsOccupied((positionComponent->getX() / TILE_SIZE) * TILE_SIZE
	  					    + TILE_SIZE / 2,
	  					    (positionComponent->getY() / TILE_SIZE) * TILE_SIZE
	  					    + TILE_SIZE / 2,
	  					    bomb))
	  	    {
	  	      canPlaceBomb = false;
	  	      break;
	  	    }
	  	}
	      if (canPlaceBomb)
	  	{
	  	  bomb = this->_entityFactory.createBomb((positionComponent->getX() / TILE_SIZE) * TILE_SIZE
	  						 + TILE_SIZE / 2,
	  						 (positionComponent->getY() / TILE_SIZE) * TILE_SIZE
	  						 + TILE_SIZE / 2,
	  						 0,
	  						 player->getId(),
	  						 ExplosiveComponent::PLAYER,
	  						 playerInputComponent->getExplosionSize());
	  	  this->_entityManager.addEntity(bomb);
	  	  this->_display.createModel(bomb);
	  	  playerInputComponent->incrementActiveBombs();
	  	}
	    }
	}
    }
  if (playerEntities->size() < 1)
    {
      this->_gameIsOn = false;
    }
}
