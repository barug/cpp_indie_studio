//
// ExplosiveSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May 23 12:15:59 2016 Barthelemy Gouby
// Last update Mon May 23 14:33:55 2016 Barthelemy Gouby
//

#include "Engine.hh"

void				Engine::ExplosiveSystem()
{
  std::vector<Entity*>		*explosives = this->_entityManager.getEntitiesWithComponents({"ExplosiveComponent"});
  PositionComponent		*bombPosition;
  ExplosiveComponent		*explosiveComponent;
  Entity			*newExplosionLeft;
  Entity			*newExplosionRight;
  Entity			*newExplosionDown;
  Entity			*newExplosionUp;

  for (Entity *explosive: *explosives)
    {
      explosiveComponent = (ExplosiveComponent*) explosive->getComponent("ExplosiveComponent");
      if (explosiveComponent->getTimerLength() <= 0)
	{
	  bombPosition = (PositionComponent*) explosive->getComponent("PositionComponent");
	  for (unsigned int i = 1; i <= explosiveComponent->getExplosionSize(); i++)
	    {
	      newExplosionLeft = 
		this->_entityFactory.createExplosion(bombPosition->getX() - i * TILE_SIZE,
						     bombPosition->getY(),
						     0);
	      this->_entityManager.addEntity(newExplosionLeft);
	      this->_display.createModel(newExplosionLeft);
	      newExplosionRight = 
		this->_entityFactory.createExplosion(bombPosition->getX() + i * TILE_SIZE,
						     bombPosition->getY(),
						     0);
	      this->_display.createModel(newExplosionRight);
	      newExplosionDown =
		this->_entityFactory.createExplosion(bombPosition->getX(),
						     bombPosition->getY() - i * TILE_SIZE,
						     0);
	      this->_entityManager.addEntity(newExplosionDown);
	      this->_display.createModel(newExplosionDown);
	      newExplosionUp = 
		this->_entityFactory.createExplosion(bombPosition->getX(),
						     bombPosition->getY() + i * TILE_SIZE,
						     0);
	      this->_entityManager.addEntity(newExplosionUp);
	      this->_display.createModel(newExplosionUp);
	    }
	}
      else
	explosiveComponent->setTimerLength(explosiveComponent->getTimerLength() - 1);
    }
}

