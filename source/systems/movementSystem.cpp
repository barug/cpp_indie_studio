//
// DeplacementSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/systems
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 15:59:24 2016 Barthelemy Gouby
// Last update Fri May 20 17:07:51 2016 Barthelemy Gouby
//

#include "../Engine.hh"

void			Engine::movementSystem()
{
  std::vector<Entity*>  *movableEntities = this->_entityManager.getEntitiesWithComponents({"PositionComponent",
											   "SpeedComponent"});
  std::vector<Entity*>  *solidEntities = this->_entityManager.getEntitiesWithComponents({"PositionComponent",
											 "SolidityComponent"});
  SpeedComponent	*speedComponent;
  PositionComponent	*positionComponent;
  unsigned int		newX;
  unsigned int		newY;
  bool			blocked = false;

  for (Entity *movable: *movableEntities)
    {
      speedComponent = (SpeedComponent*) movable->getComponent("SpeedComponent");
      positionComponent = (PositionComponent*) movable->getComponent("PositionComponent");
      newX = positionComponent->getX() + speedComponent->getSpeedX();
      newY = positionComponent->getY() + speedComponent->getSpeedY();
      this->_display.updateModelPosition(movable->getId(), newX, newY);
      for (Entity *solid: *solidEntities)
	{
	  if (solid != movable && this->_display.collision(movable->getId(), solid->getId()))
	    {
	      blocked = true;
	      break;
	    }
	}
      if (blocked)
	this->_display.updateModelPosition(movable->getId(), positionComponent->getX(), positionComponent->getY());
      else
	{
	  positionComponent->setX(newX);
	  positionComponent->setY(newY);
	}
    }
}
