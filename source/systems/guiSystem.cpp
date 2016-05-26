//
// guiSystem.cpp for indie studio
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Tue May 24 20:12:10 2016 Thomas Bogard
// Last update Thu May 26 12:19:10 2016 Thomas Bogard
//

# include "../Engine.hh"

void		Engine::guiSystem()
{
  PlayerInputComponent  *playerInputComponent;
  std::vector<Entity*>  *playerEntities =
    this->_entityManager.getEntitiesWithComponents({Component::PLAYER_INPUT_COMPONENT});
  int			speed_index;
  int			mbomb_index;
  int			fire_index;
  int			x;


  for (Entity *player : *playerEntities)
    {
      playerInputComponent = (PlayerInputComponent*) player->getComponent(Component::PLAYER_INPUT_COMPONENT);
      speed_index = ((playerInputComponent->getSpeed() % 50) / 10) - 1;
      mbomb_index = playerInputComponent->getMaxBombs() - 1;
      fire_index = playerInputComponent->getExplosionSize() - 2;
      if (playerInputComponent->getMaxBombs() >= 1)
      	{
      	  if (player->getId() == 1)
      	    x = 400 * mbomb_index;
      	  else if (player->getId() == 2)
      	    x = (mbomb_index ? (8000 - (400 * mbomb_index)) : (8000));
      	  this->_display.guiCreateModel("./models/cube.obj", "./textures/powerup/bombup.png",
					x, 300, irr::core::vector3df(90, 0, 90), 200);
      	}
      if (playerInputComponent->getSpeed() >= 60)
      	{
      	  if (player->getId() == 1)
      	    x = 400 * speed_index;
      	  else if (player->getId() == 2)
      	    x = (speed_index ? (8000 - (400 * speed_index)) : (8000));
      	  this->_display.guiCreateModel("./models/cube.obj", "./textures/powerup/speedup.png",
					x, 650, irr::core::vector3df(90, 0, 90), 200);
      	}
      if (playerInputComponent->getExplosionSize() > 1)
      	{
      	  if (player->getId() == 1)
      	    x = 400 * fire_index;
      	  else if (player->getId() == 2)
      	    x = (fire_index ? (8000 - (400 * fire_index)) : (8000));
       	  this->_display.guiCreateModel("./models/cube.obj", "./textures/powerup/fireup.png",
					x, 1000, irr::core::vector3df(90, 0, 90), 200);
      	}
    }
}
