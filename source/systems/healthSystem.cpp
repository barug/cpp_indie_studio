//
// healthSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 25 15:47:43 2016 Barthelemy Gouby
// Last update Mon May 30 12:57:57 2016 Erwan Dupard
//

#include "../Engine.hh"

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
	  // if (healthComponent->getInvincibleTimer() % 20 > 10)
	  //   this->_display.changeModelAlpha(destructible, 0);
	  // else
	  //   this->_display.changeModelAlpha(destructible, 100);
	  this->_display.changeModelAlpha(destructible, 0);
	  healthComponent->setInviciblesTimer(healthComponent->getInvincibleTimer() - 1);
	}
      else
	this->_display.changeModelAlpha(destructible, 0);
      if (healthComponent->getLives() <= 0)
	{
	  this->_display.removeModel(destructible);
	  this->_entityManager.destroyEntity(destructible->getId());
	}
    }
}
