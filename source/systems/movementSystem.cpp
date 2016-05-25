//
// DeplacementSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/systems
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Wed May 11 15:59:24 2016 Barthelemy Gouby
// Last update Wed May 25 12:22:10 2016 Barthelemy Gouby
//

#include "../Engine.hh"

void			Engine::movementSystem()
{
  std::vector<Entity*>  *movableEntities =
    this->_entityManager.getEntitiesWithComponents({Component::POSITION_COMPONENT,
	  Component::SPEED_COMPONENT});
  std::vector<Entity*>  *solidEntities =
    this->_entityManager.getEntitiesWithComponents({Component::POSITION_COMPONENT,
	  Component::SOLIDITY_COMPONENT});
  SpeedComponent	*speedComponent;
  PositionComponent	*positionComponent;
  unsigned int		newX;
  unsigned int		newY;
  bool			blocked = false;

  for (Entity *movable: *movableEntities)
    {
      speedComponent = (SpeedComponent*) movable->getComponent(Component::SPEED_COMPONENT);
      positionComponent = (PositionComponent*) movable->getComponent(Component::POSITION_COMPONENT);
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

      // rotation
      if (newX < positionComponent->getX())
        positionComponent->setRotation(90);
      else if (newX > positionComponent->getX())
        positionComponent->setRotation(270);
      else if (newY < positionComponent->getY())
        positionComponent->setRotation(360);
      else if (newY > positionComponent->getY())
        positionComponent->setRotation(180);
      // update animation
      this->_display.updateModelAnimation(movable->getId(), positionComponent->getRotation(),
                                          positionComponent->getX(), positionComponent->getOldX(),
                                          positionComponent->getY(), positionComponent->getOldY());
      positionComponent->setOldX(positionComponent->getX());
      positionComponent->setOldY(positionComponent->getY());

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
