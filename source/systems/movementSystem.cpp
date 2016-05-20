//
// DeplacementSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/systems
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 15:59:24 2016 Barthelemy Gouby
// Last update Fri May 20 12:52:43 2016 Barthelemy Gouby
//

#include "../Engine.hh"

void			Engine::movementSystem()
{
  std::vector<Entity*>  *movableEntities = this->_entityManager.getEntitiesWithComponents({"PositionComponent"
											, "SpeedComponent"});
  for (Entity *movable: *movableEntities)
    this->_display.moveModel(movable);
}
