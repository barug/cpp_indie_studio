//
// EntityFactory.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 12:08:54 2016 Barthelemy Gouby
// Last update Fri May 20 13:56:12 2016 Barthelemy Gouby
//

#include "EntityFactory.hh"

EntityFactory::EntityFactory()
  : _nextFreeId(1)
{}

EntityFactory::~EntityFactory()
{}

Entity			*EntityFactory::createSolidBlock(const unsigned int &x,
							 const unsigned int &y,
							 const unsigned int &rotation)
{
  Entity		*solidBlock = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/BOMBERSTAND.b3d",
							     "./textures/bomberman_black.png",
							     10);
  PositionComponent	*positionComponent = new PositionComponent(x, y, rotation);
  SolidityComponent	*solidityComponent = new SolidityComponent;

  solidBlock->addComponent(modelComponent);
  solidBlock->addComponent(positionComponent);
  solidBlock->addComponent(solidityComponent);
  this->_nextFreeId++;
  return (solidBlock);
}

Entity			*EntityFactory::createPlayer(const unsigned int &x,
						     const unsigned int &y,
						     const unsigned int &rotation,
						     irr::EKEY_CODE keyUp,
						     irr::EKEY_CODE keyDown,
						     irr::EKEY_CODE keyRight,
						     irr::EKEY_CODE keyLeft,
						     irr::EKEY_CODE keyBomb,
						     Display *display)
{
  Entity		*player = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/BOMBERSTAND.b3d",
							     "./textures/bomberman_black.png",
							     10);
  PositionComponent	*positionComponent = new PositionComponent(x, y, rotation);
  SpeedComponent	*speedComponent = new SpeedComponent(0, 0, 0);
  PlayerInputComponent	*playerInputComponent = new PlayerInputComponent(keyUp,
									 keyDown,
									 keyLeft,
									 keyRight,
									 keyBomb);

  player->addComponent(modelComponent);
  player->addComponent(positionComponent);
  player->addComponent(playerInputComponent);
  player->addComponent(speedComponent);
  display->createEventListener(player->getId(), {keyUp, keyDown, keyRight, keyLeft, keyBomb});
  this->_nextFreeId++;
  return (player);
}
