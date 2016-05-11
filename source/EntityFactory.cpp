//
// EntityFactory.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 12:08:54 2016 Barthelemy Gouby
// Last update Wed May 11 12:21:53 2016 Barthelemy Gouby
//

#include "EntityFactory.hh"

EntityFactory::EntityFactory()
  : _nextFreeId(1)
{}

EntityFactory::~EntityFactory()
{}

Entity			*EntityFactory::createSolidBlock(const unsigned int &x, const unsigned int &y)
{
  Entity		*solidBlock = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("solidBlock.obj");
  PositionComponent	*positionComponent = new PositionComponent(x, y);

  solidBlock->addComponent(modelComponent);
  solidBlock->addComponent(positionComponent);
  this->_nextFreeId++;
  return (solidBlock);
}

