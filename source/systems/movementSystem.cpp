//
// DeplacementSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/systems
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 15:59:24 2016 Barthelemy Gouby
// Last update Tue May 17 16:15:59 2016 Barthelemy Gouby
//

#include "../Engine.hh"

void			Engine::movementSystem()
{
  std::vector<Entity*>  movableEntities = getEntitiesWithComponents({"PositionComponent", "SpeedComponent"});
  PositionComponent	position;
  SpeedComponent	speed;

  for (Entity *movable: movableEntities)
    {
      if (!this->_display.getIfBlocked(movable))
	{
	  position = movable.getComponent("PositionComponent");
	  speed = movable.getComponent("SpeedComponent");
	  position.setX(position.getX() + speed.getSpeedX());
	  position.setY(position.getY() + speed.getSpeedY());
	  this->_display.updateModel(movable);
	}
    }
}
