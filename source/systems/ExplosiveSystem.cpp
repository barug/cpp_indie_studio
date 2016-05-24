//
// ExplosiveSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May 23 12:15:59 2016 Barthelemy Gouby
// Last update Tue May 24 16:55:47 2016 Barthelemy Gouby
//

#include "Engine.hh"

void				Engine::_addNewExplosion(const unsigned int &x,
							 const unsigned &y,
							 bool &isBlocked)
{
  Entity			*newExplosion;
  bool				canAddExplosion = true;
  std::vector<Entity*>		*solids = this->_entityManager.getEntitiesWithComponents({"SolidityComponent"});

  if (!isBlocked)
    {
      for (Entity *solid: *solids)
  	{
  	  if (this->_display.tileIsOccupied(x, y, solid))
  	    {
  	      isBlocked = true;
  	      if (solid->getComponent("DestructibleComponent"))
  	      	{
  	      	  this->_display.removeModel(solid);
  	      	  this->_entityManager.destroyEntity(solid->getId());
  	      	}
  	      else
  	      	{
		  canAddExplosion = false;
		}
  	      isBlocked = true;
	      break;
  	    }
  	}
      if (canAddExplosion)
  	{
  	  newExplosion = this->_entityFactory.createExplosion(x, y, 0);
  	  this->_entityManager.addEntity(newExplosion);
  	  this->_display.createModel(newExplosion);      
  	}
    }
}

void				Engine::ExplosiveSystem()
{
  std::vector<Entity*>		*explosives = this->_entityManager.getEntitiesWithComponents({"ExplosiveComponent"});
  std::vector<Entity*>		*solids;
  PositionComponent		*bombPosition;
  ExplosiveComponent		*explosiveComponent;
  Entity			*newExplosionCenter;
  Entity			*owner;
  bool				leftIsBlocked;
  bool				rightIsBlocked;
  bool				downIsBlocked;
  bool				upIsBlocked;

  for (Entity *explosive: *explosives)
    {
      explosiveComponent = (ExplosiveComponent*) explosive->getComponent("ExplosiveComponent");
      if (explosiveComponent->getTimerLength() <= 0)
	{
	  // solids =  this->_entityManager.getEntitiesWithComponents({"SolidityComponent"});
	  leftIsBlocked = false;
	  rightIsBlocked = false;
	  downIsBlocked = false;
	  upIsBlocked = false;
	  bombPosition = (PositionComponent*) explosive->getComponent("PositionComponent");
	  newExplosionCenter = 
	    this->_entityFactory.createExplosion(bombPosition->getX(),
						 bombPosition->getY(),
						 0);
	  this->_entityManager.addEntity(newExplosionCenter);
	  this->_display.createModel(newExplosionCenter);
	  for (unsigned int i = 1; i <= explosiveComponent->getExplosionSize(); i++)
	    {
	      this->_addNewExplosion(bombPosition->getX() - i * TILE_SIZE,
				     bombPosition->getY(),
				     leftIsBlocked);
	      this->_addNewExplosion(bombPosition->getX() + i * TILE_SIZE,
				     bombPosition->getY(),
				     rightIsBlocked);
	      this->_addNewExplosion(bombPosition->getX(),
				     bombPosition->getY() - i * TILE_SIZE,
				     downIsBlocked);
	      this->_addNewExplosion(bombPosition->getX(),
				     bombPosition->getY() + i * TILE_SIZE,
				     upIsBlocked);
	    }
	  owner = this->_entityManager.getEntity(explosiveComponent->getOwnerId());
	  if (explosiveComponent->getOwnerType() == ExplosiveComponent::PLAYER)
	    ((PlayerInputComponent*)(owner->getComponent("PlayerInputComponent")))->decrementActiveBombs();
	  this->_display.removeModel(explosive);
	  this->_entityManager.destroyEntity(explosive->getId());
	}
      else
	explosiveComponent->setTimerLength(explosiveComponent->getTimerLength() - 1);
    }
}

