//
// EntityFactory.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 12:08:54 2016 Barthelemy Gouby
// Last update Mon May 23 14:41:28 2016 Barthelemy Gouby
//

#include "EntityFactory.hh"

EntityFactory::EntityFactory()
  : _nextFreeId(1)
{}

EntityFactory::~EntityFactory()
{}

PositionComponent	*getClosestTileCenter(const unsigned int &x,
					      const unsigned int &y,
					      const unsigned int &rotation)
{
  PositionComponent	*positionComponent = new PositionComponent((x / TILE_SIZE) * TILE_SIZE,
								   (y / TILE_SIZE) * TILE_SIZE,
								   rotation);
  return (positionComponent);
}

Entity			*EntityFactory::createNormalBomb(const unsigned int &x,
					  const unsigned int &y,
					  const unsigned int &rotation)
{
  Entity		*normalBomb = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/BomB.obj",
							     "./textures/BomB.png",
							     50);
  PositionComponent	*positionComponent = getClosestTileCenter(x, y, rotation);
  SolidityComponent	*solidityComponent = new SolidityComponent;
  ExplosiveComponent	*explosiveComponent = new ExplosiveComponent(100, 3);

  normalBomb->addComponent(modelComponent);
  normalBomb->addComponent(positionComponent);
  normalBomb->addComponent(solidityComponent);
  normalBomb->addComponent(explosiveComponent);
  this->_nextFreeId++;
  return (normalBomb);
}

Entity			*EntityFactory::createExplosion(const unsigned int &x,
					 const unsigned int &y,
					 const unsigned int &rotation)
{
  Entity		*explosion = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/BomB.obj",
							     "./textures/BomB.png",
							     50);
  PositionComponent	*positionComponent = getClosestTileCenter(x, y, rotation);
  SolidityComponent	*solidityComponent = new SolidityComponent;
  ExplosionComponent	*explosionComponent = new ExplosionComponent(100);

  explosion->addComponent(modelComponent);
  explosion->addComponent(positionComponent);
  explosion->addComponent(solidityComponent);
  explosion->addComponent(explosionComponent);
  this->_nextFreeId++;
  return (explosion);
}

Entity			*EntityFactory::createSolidBlock(const unsigned int &x,
							 const unsigned int &y,
							 const unsigned int &rotation)
{
  Entity		*solidBlock = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/BOMBERSTAND.b3d",
							     "./textures/bomberman_black.png",
							     200);
  PositionComponent	*positionComponent = getClosestTileCenter(x, y, rotation);
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
							     200);
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
