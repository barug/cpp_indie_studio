//
// powerUpSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Tue May 24 18:16:05 2016 Barthelemy Gouby
// Last update Wed May 25 10:32:17 2016 Barthelemy Gouby
//

#include "Engine.hh"

void			Engine::powerUpSystem()
{
  std::vector<Entity*>	*powerUps = this->_entityManager.getEntitiesWithComponents({"PowerUpComponent"});
  std::vector<Entity*>	*players = this->_entityManager.getEntitiesWithComponents({"PlayerInputComponent"});
  PlayerInputComponent	*playerInputComponent;
  PowerUpComponent	*powerUpComponent;

  for (Entity *powerUp: *powerUps)
    {
      for (Entity *player: *players)
	{
	  if (this->_display.collision(powerUp->getId(), player->getId()))
	    {
	      playerInputComponent = (PlayerInputComponent*) player->getComponent("PlayerInputComponent");
	      powerUpComponent = (PowerUpComponent*) powerUp->getComponent("PowerUpComponent");
	      if (powerUpComponent->getType() == PowerUpComponent::BOMB_UP)
		playerInputComponent->setMaxBombs(playerInputComponent->getMaxBombs() + 1);
	      if (powerUpComponent->getType() == PowerUpComponent::FIRE_UP)
		playerInputComponent->setExplosionSize(playerInputComponent->getExplosionSize() + 1);
	      if (powerUpComponent->getType() == PowerUpComponent::SPEED_UP)
		playerInputComponent->setSpeed(playerInputComponent->getSpeed() + 10);
	      this->_display.removeModel(powerUp);
	      this->_entityManager.destroyEntity(powerUp->getId());
	      break;
	    }
	}
    }
}
