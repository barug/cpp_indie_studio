//
// DeplacementSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/systems
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Wed May 11 15:59:24 2016 Barthelemy Gouby
// Last update Sat May 21 14:22:32 2016 Thomas Bogard
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
      this->_display.updateModelPosition(movable->getId(), positionComponent->getRotation(), newX, newY);
      for (Entity *solid: *solidEntities)
	{
	  if (solid != movable && this->_display.collision(movable->getId(), solid->getId()))
	    {
	      blocked = true;
	      break;
	    }
	}
      if (newX < positionComponent->getX())
        positionComponent->setRotation(90);
      else if (newX > positionComponent->getX())
        positionComponent->setRotation(270);
      else if (newY < positionComponent->getY())
        positionComponent->setRotation(360);
      else if (newY > positionComponent->getY())
        positionComponent->setRotation(180);

      if (blocked)
	this->_display.updateModelPosition(movable->getId(), positionComponent->getRotation(),
					   positionComponent->getX(), positionComponent->getY());
      else
	{
	  positionComponent->setX(newX);
	  positionComponent->setY(newY);
	}
    }
}
