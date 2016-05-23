//
// PlayerInputSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/systems
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 18 16:49:48 2016 Barthelemy Gouby
// Last update Mon May 23 18:29:33 2016 Barthelemy Gouby
//

#include <iostream>
#include "Engine.hh"
#include "../components/SpeedComponent.hh"
#include "../components/PlayerInputComponent.hh"

void				Engine::playerInputSystem()
{
  std::vector<Entity*>		*playerEntities =
    this->_entityManager.getEntitiesWithComponents({"PlayerInputComponent", "SpeedComponent"});
  std::vector<irr::EKEY_CODE>	*keysDown;
  SpeedComponent		*speedComponent;
  PositionComponent		*positionComponent;
  PlayerInputComponent		*playerInputComponent;
  Entity			*bomb;

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
	  if (key == playerInputComponent->getKeyBomb())
	    {
	      positionComponent = (PositionComponent*) player->getComponent("PositionComponent");
	      bomb = this->_entityFactory.createNormalBomb(positionComponent->getX(),
							   positionComponent->getY(),
							   0);
	      this->_entityManager.addEntity(bomb);
	      this->_display.createModel(bomb);
	    }
	}
      if (keysDown->size() == 0)
	{
	  speedComponent->setSpeedX(0);
	  speedComponent->setSpeedY(0);
	}
    }
}
