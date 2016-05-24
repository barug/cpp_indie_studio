//
// PlayerInputSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/systems
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 18 16:49:48 2016 Barthelemy Gouby
// Last update Tue May 24 16:53:49 2016 Barthelemy Gouby
//

#include <iostream>
#include "Engine.hh"
#include "../components/SpeedComponent.hh"
#include "../components/PlayerInputComponent.hh"
#include "../components/ExplosiveComponent.hh"

// bool				Engine::_canPlaceBomb(PositionComponent *positionComponent,
// 						      Entity *bomb)
// {
  
// }

void				Engine::playerInputSystem()
{
  std::vector<Entity*>		*playerEntities =
    this->_entityManager.getEntitiesWithComponents({"PlayerInputComponent", "SpeedComponent"});
  std::vector<Entity*>		*bombs;
  std::vector<irr::EKEY_CODE>	*keysDown;
  SpeedComponent		*speedComponent;
  PositionComponent		*positionComponent;
  PlayerInputComponent		*playerInputComponent;
  Entity			*bomb;
  bool				canPlaceBomb;

  for (Entity *player: *playerEntities)
    {
      speedComponent = (SpeedComponent*) player->getComponent("SpeedComponent");
      playerInputComponent = (PlayerInputComponent*) player->getComponent("PlayerInputComponent");
      keysDown = this->_display.getKeysDownForId(player->getId());
      for (irr::EKEY_CODE key: *keysDown)
	{
	  if (key == playerInputComponent->getKeyUp())
	    speedComponent->setSpeedY(PLAYER_MOVEMENT_SPEED);
	  else if (key == playerInputComponent->getKeyDown())
	    speedComponent->setSpeedY(-PLAYER_MOVEMENT_SPEED);
	  else
	    speedComponent->setSpeedY(0);
	  if (key == playerInputComponent->getKeyLeft())
	    speedComponent->setSpeedX(PLAYER_MOVEMENT_SPEED);
	  else if (key == playerInputComponent->getKeyRight())
	    speedComponent->setSpeedX(-PLAYER_MOVEMENT_SPEED);
	  else
	    speedComponent->setSpeedX(0);
	  if (key == playerInputComponent->getKeyBomb()
	      && playerInputComponent->getActiveBombs() < playerInputComponent->getMaxBombs())
	    {
	      bombs = this->_entityManager.getEntitiesWithComponents({"ExplosiveComponent"});
	      positionComponent = (PositionComponent*) player->getComponent("PositionComponent");	  
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
		  bomb = this->_entityFactory.createNormalBomb((positionComponent->getX() / TILE_SIZE) * TILE_SIZE
							       + TILE_SIZE / 2,
							       (positionComponent->getY() / TILE_SIZE) * TILE_SIZE
							       + TILE_SIZE / 2,
							       0,
							       player->getId(),
							       ExplosiveComponent::PLAYER);
		  this->_entityManager.addEntity(bomb);
		  this->_display.createModel(bomb);
		  playerInputComponent->incrementActiveBombs();
		}
	    }
	}
      if (keysDown->size() == 0)
	{
	  speedComponent->setSpeedX(0);
	  speedComponent->setSpeedY(0);
	}
    }
}
