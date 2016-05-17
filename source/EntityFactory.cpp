//
// EntityFactory.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 12:08:54 2016 Barthelemy Gouby
// Last update Tue May 17 18:45:44 2016 Barthelemy Gouby
//

#include "EntityFactory.hh"

EntityFactory::EntityFactory()
  : _nextFreeId(1)
{}

EntityFactory::~EntityFactory()
{}

Entity			*EntityFactory::createSolidBlock(const unsigned int &x, const unsigned int &y, const unsigned int &rotation)
{
  Entity		*solidBlock = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/BOMBERSTAND.b3d", "./textures/bomberman_black.png", 10);
  PositionComponent	*positionComponent = new PositionComponent(x, y, rotation);

  solidBlock->addComponent(modelComponent);
  solidBlock->addComponent(positionComponent);
  this->_nextFreeId++;
  return (solidBlock);
}

