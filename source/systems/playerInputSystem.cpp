//
// PlayerInputSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/systems
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 18 16:49:48 2016 Barthelemy Gouby
// Last update Wed May 25 10:31:12 2016 Barthelemy Gouby
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
	    speedComponent->setSpeedY(playerInputComponent->getSpeed());
	  else if (key == playerInputComponent->getKeyDown())
	    speedComponent->setSpeedY(-playerInputComponent->getSpeed());
	  else
	    speedComponent->setSpeedY(0);
	  if (key == playerInputComponent->getKeyLeft())
	    speedComponent->setSpeedX(playerInputComponent->getSpeed());
	  else if (key == playerInputComponent->getKeyRight())
	    speedComponent->setSpeedX(-playerInputComponent->getSpeed());
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
      if (keysDown->size() == 0)
	{
	  speedComponent->setSpeedX(0);
	  speedComponent->setSpeedY(0);
	}
    }
}
