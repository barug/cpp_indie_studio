//
// guiSystem.cpp for indie studio
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Tue May 24 20:12:10 2016 Thomas Bogard
// Last update Thu May 26 15:51:51 2016 Thomas Bogard
//

# include "../Engine.hh"

# define	P1(index) 200 * index
# define	P2(index) (index ? (8000 - (200 * index)) : 8000)

void		Engine::guiSystem()
{
  PlayerInputComponent  *playerInputComponent;
  HealthComponent	*healthComponent;
  std::vector<Entity*>  *playerEntities =
    this->_entityManager.getEntitiesWithComponents({Component::PLAYER_INPUT_COMPONENT});

  int			speedIndex;
  int			bombIndex;
  int			fireIndex;
  int			lifeIndex;
  int			playerIndex = 1;
  int			x;

  for (Entity *player : *playerEntities)
    {
      playerInputComponent = (PlayerInputComponent*) player->getComponent(Component::PLAYER_INPUT_COMPONENT);
      healthComponent = (HealthComponent*) player->getComponent(Component::HEALTH_COMPONENT);
      speedIndex = ((playerInputComponent->getSpeed() % 50) / 10) - 1;
      bombIndex = playerInputComponent->getMaxBombs() - 1;
      fireIndex = playerInputComponent->getExplosionSize() - 2;
      lifeIndex = healthComponent->getLives() - 1;
      if (healthComponent->getLives() > 0)
      	{
      	  if (playerIndex == 1)
      	    x = 200 * lifeIndex;
      	  else if (playerIndex == 2)
      	    x = (lifeIndex ? (8000 - (200 * lifeIndex)) : (8000));
       	  this->_display.guiCreateModel("./models/cube.obj", "./textures/powerup/heart.png",
      					x, 300, irr::core::vector3df(90, 0, 90), 150);
      	}
      if (playerInputComponent->getMaxBombs() >= 1)
      	{
      	  if (playerIndex == 1)
      	    x = 200 * bombIndex;
      	  else if (playerIndex == 2)
      	    x = (bombIndex ? (8000 - (200 * bombIndex)) : (8000));
      	  this->_display.guiCreateModel("./models/cube.obj", "./textures/powerup/bombup.png",
					x, 500, irr::core::vector3df(90, 0, 90), 150);
      	}
      if (playerInputComponent->getSpeed() >= 60)
      	{
      	  if (playerIndex == 1)
      	    x = 200 * speedIndex;
      	  else if (playerIndex == 2)
      	    x = (speedIndex ? (8000 - (200 * speedIndex)) : (8000));
      	  this->_display.guiCreateModel("./models/cube.obj", "./textures/powerup/speedup.png",
					x, 700, irr::core::vector3df(90, 0, 90), 150);
      	}
      if (playerInputComponent->getExplosionSize() > 1)
      	{
      	  if (playerIndex == 1)
      	    x = 200 * fireIndex;
      	  else if (playerIndex == 2)
      	    x = (fireIndex ? (8000 - (200 * fireIndex)) : (8000));
       	  this->_display.guiCreateModel("./models/cube.obj", "./textures/powerup/fireup.png",
					x, 900, irr::core::vector3df(90, 0, 90), 150);
      	}
      ++playerIndex;
    }
}
