//
// DeplacementSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/systems
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 15:59:24 2016 Barthelemy Gouby
// Last update Fri May 20 16:40:31 2016 Barthelemy Gouby
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
  
  for (Entity *movable: *movableEntities)
    {
      speedComponent = (SpeedComponent*) movable->getComponent("SpeedComponent");
      positionComponent = (PositionComponent*) movable->getComponent("PositionComponent");
      newX = positionComponent->setX(positionComponent->getX() + speedComponent->getSpeedX());
      newY = positionComponent->setY(PositionComponent->getY() + speedComponent->getSpeedY());
      this->_display.updateModelPosition(movable->getId(), newX, newY);
      for (Entity *solid: *solidEntities)
	{
	  if (solid != movable && colision(movable->getId(), solid->getId))
	    {

	    }
	}
    }
}
