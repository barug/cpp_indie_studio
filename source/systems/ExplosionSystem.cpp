//
// ExplosionSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May 23 14:52:30 2016 Barthelemy Gouby
// Last update Wed May 25 12:28:15 2016 Barthelemy Gouby
//

#include "Engine.hh"

void			Engine::ExplosionSystem()
{
  std::vector<Entity*>	*explosions =
    this->_entityManager.getEntitiesWithComponents({Component::EXPLOSION_COMPONENT});
  ExplosionComponent	*explosionComponent;

  for (Entity *explosion: *explosions)
    {
      explosionComponent = (ExplosionComponent*) explosion->getComponent(Component::EXPLOSION_COMPONENT);
      if (explosionComponent->getExplosionDuration() <= 0)
	{
	  this->_display.removeModel(explosion);
	  this->_entityManager.destroyEntity(explosion->getId());
	}
      else
	explosionComponent->setExplosionDuration(explosionComponent->getExplosionDuration() - 1);
    }
}
