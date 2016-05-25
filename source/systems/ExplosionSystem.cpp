//
// ExplosionSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May 23 14:52:30 2016 Barthelemy Gouby
// Last update Wed May 25 16:05:18 2016 Barthelemy Gouby
//

#include "Engine.hh"

void			Engine::ExplosionSystem()
{
  std::vector<Entity*>	*explosions =
    this->_entityManager.getEntitiesWithComponents({Component::EXPLOSION_COMPONENT});
  std::vector<Entity*>	*destructibles;
  ExplosionComponent	*explosionComponent;
  HealthComponent	*healthComponent;

  for (Entity *explosion: *explosions)
    {
      explosionComponent = (ExplosionComponent*) explosion->getComponent(Component::EXPLOSION_COMPONENT);
      destructibles = this->_entityManager.getEntitiesWithComponents({Component::HEALTH_COMPONENT});
      for (Entity *destructible: *destructibles)
	{
	  if (this->_display.collision(destructible->getId(), explosion->getId()))
	    {
	      healthComponent = (HealthComponent*) destructible->getComponent(Component::HEALTH_COMPONENT);
	      healthComponent->setLives(healthComponent->getLives() - 1);
	    }
	}
      if (explosionComponent->getExplosionDuration() <= 0)
	{
	  this->_display.removeModel(explosion);
	  this->_entityManager.destroyEntity(explosion->getId());
	}
      else
	explosionComponent->setExplosionDuration(explosionComponent->getExplosionDuration() - 1);
    }
}
