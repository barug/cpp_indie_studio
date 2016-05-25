//
// powerUpSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Tue May 24 18:16:05 2016 Barthelemy Gouby
// Last update Wed May 25 12:29:57 2016 Barthelemy Gouby
//

#include "Engine.hh"

void			Engine::powerUpSystem()
{
  std::vector<Entity*>	*powerUps =
    this->_entityManager.getEntitiesWithComponents({Component::POWER_UP_COMPONENT});
  std::vector<Entity*>	*players =
    this->_entityManager.getEntitiesWithComponents({Component::PLAYER_INPUT_COMPONENT});
  PlayerInputComponent	*playerInputComponent;
  PowerUpComponent	*powerUpComponent;

  for (Entity *powerUp: *powerUps)
    {
      for (Entity *player: *players)
	{
	  if (this->_display.collision(powerUp->getId(), player->getId()))
	    {
	      playerInputComponent =
		(PlayerInputComponent*) player->getComponent(Component::PLAYER_INPUT_COMPONENT);
	      powerUpComponent =
		(PowerUpComponent*) powerUp->getComponent(Component::POWER_UP_COMPONENT);
	      switch (powerUpComponent->getType())
		{
		case PowerUpComponent::BOMB_UP:
		  playerInputComponent->setMaxBombs(playerInputComponent->getMaxBombs() + 1);
		  break;
		case PowerUpComponent::FIRE_UP:
		  playerInputComponent->setExplosionSize(playerInputComponent->getExplosionSize() + 1);
		  break;
		case PowerUpComponent::SPEED_UP:
		  playerInputComponent->setSpeed(playerInputComponent->getSpeed() + 10);
		  break;
		default:
		  break;
		}
	      this->_display.removeModel(powerUp);
	      this->_entityManager.destroyEntity(powerUp->getId());
	      break;
	    }
	}
    }
}
