//
// healthSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 25 15:47:43 2016 Barthelemy Gouby
// Last update Fri May 27 17:20:15 2016 Barthelemy Gouby
//

#include "Engine.hh"

void			Engine::healthSystem()
{
  std::vector<Entity*>	*destructibles = 
    this->_entityManager.getEntitiesWithComponents({Component::HEALTH_COMPONENT});
  HealthComponent	*healthComponent;

  for (Entity *destructible: *destructibles)
    {
      healthComponent = (HealthComponent*) destructible->getComponent(Component::HEALTH_COMPONENT);
      if (healthComponent->getInvincibleTimer() > 0)
	{
	  if (healthComponent->getInvincibleTimer() % 10 > 5)
	    this->_display.changeMaterialType(destructible, irr::video::EMT_TRANSPARENT_ADD_COLOR);
	  else
	    this->_display.changeMaterialType(destructible, irr::video::EMT_SOLID);
	  healthComponent->setInviciblesTimer(healthComponent->getInvincibleTimer() - 1);
	}
      else
	this->_display.changeMaterialType(destructible, irr::video::EMT_SOLID);
      if (healthComponent->getLives() <= 0)
	{
	  this->_display.removeModel(destructible);
	  this->_entityManager.destroyEntity(destructible->getId());
	}
    }
}
