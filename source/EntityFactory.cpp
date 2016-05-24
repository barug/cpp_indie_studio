//
// EntityFactory.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Wed May 11 12:08:54 2016 Barthelemy Gouby
// Last update Tue May 24 19:25:47 2016 Barthelemy Gouby
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
  PositionComponent	*positionComponent = new PositionComponent((x / TILE_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   (y / TILE_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   rotation);
  return (positionComponent);
}

Entity			*EntityFactory::createBomb(const unsigned int &x,
						   const unsigned int &y,
						   const unsigned int &rotation,
						   const unsigned int &ownerId,
						   const ExplosiveComponent::Owner &ownerType,
						   const unsigned int &explosionSize)
{
  Entity		*normalBomb = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/bomb.obj",
							     "./textures/bomb.png",
							     30);
  PositionComponent	*positionComponent = getClosestTileCenter(x, y, rotation);
  ExplosiveComponent	*explosiveComponent = new ExplosiveComponent(100, explosionSize, ownerId, ownerType);

  normalBomb->addComponent(modelComponent);
  normalBomb->addComponent(positionComponent);
  normalBomb->addComponent(explosiveComponent);
  this->_nextFreeId++;
  return (normalBomb);
}

Entity			*EntityFactory::createExplosion(const unsigned int &x,
					 const unsigned int &y,
					 const unsigned int &rotation)
{
  Entity		*explosion = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/bomb.obj",
							     "./textures/bomb.png",
							     25);
  PositionComponent	*positionComponent = getClosestTileCenter(x, y, rotation);
  ExplosionComponent	*explosionComponent = new ExplosionComponent(100);

  explosion->addComponent(modelComponent);
  explosion->addComponent(positionComponent);
  explosion->addComponent(explosionComponent);
  this->_nextFreeId++;
  return (explosion);
}

Entity			*EntityFactory::createSolidBlock(const unsigned int &x,
							 const unsigned int &y,
							 const unsigned int &rotation)
{
  Entity		*solidBlock = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/cube.obj",
							     "./textures/stonebox.png",
							     375);
  PositionComponent	*positionComponent = getClosestTileCenter(x, y, rotation);
  SolidityComponent	*solidityComponent = new SolidityComponent;

  solidBlock->addComponent(modelComponent);
  solidBlock->addComponent(positionComponent);
  solidBlock->addComponent(solidityComponent);
  this->_nextFreeId++;
  return (solidBlock);
}

Entity			*EntityFactory::createDestructibleBlock(const unsigned int &x,
								const unsigned int &y,
								const unsigned int &rotation)
{
  Entity		*destructibleBlock = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/cube.obj",
							     "./textures/woodbox.jpg",
							     375);
  PositionComponent	*positionComponent = getClosestTileCenter(x, y, rotation);
  SolidityComponent	*solidityComponent = new SolidityComponent;
  DestructibleComponent	*destructibleComponent = new DestructibleComponent(DestructibleComponent::BLOCK);

  destructibleBlock->addComponent(modelComponent);
  destructibleBlock->addComponent(positionComponent);
  destructibleBlock->addComponent(solidityComponent);
  destructibleBlock->addComponent(destructibleComponent);
  this->_nextFreeId++;
  return (destructibleBlock);
}


Entity			*EntityFactory::createPlayer(const unsigned int &x,
						     const unsigned int &y,
						     const unsigned int &rotation,
						     const irr::EKEY_CODE &keyUp,
						     const irr::EKEY_CODE &keyDown,
						     const irr::EKEY_CODE &keyRight,
						     const irr::EKEY_CODE &keyLeft,
						     const irr::EKEY_CODE &keyBomb,
						     const unsigned int &maxBombs,
						     const unsigned int &explosionSize,
						     Display *display)
{
  Entity		*player = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/BOMBERSTAND.b3d",
							     "./textures/bomberman_black.png",
							     250);
  PositionComponent	*positionComponent = new PositionComponent(x, y, rotation);
  SpeedComponent	*speedComponent = new SpeedComponent(0, 0, 0);
  PlayerInputComponent	*playerInputComponent = new PlayerInputComponent(keyUp,
									 keyDown,
									 keyLeft,
									 keyRight,
									 keyBomb,
									 maxBombs,
									 explosionSize);

  player->addComponent(modelComponent);
  player->addComponent(positionComponent);
  player->addComponent(playerInputComponent);
  player->addComponent(speedComponent);
  display->createEventListener(player->getId(), {keyUp, keyDown, keyRight, keyLeft, keyBomb});
  this->_nextFreeId++;
  return (player);
}

Entity			*EntityFactory::createPowerUp(const unsigned int &x,
						      const unsigned int &y,
						      PowerUpComponent::Type type)
{
  Entity		*powerUp = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/cube.obj",
							     300);
  PositionComponent	*positionComponent = new PositionComponent(x, y, 0);
  PowerUpComponent	*powerUpComponent = new PowerUpComponent(type);

  if (type == PowerUpComponent::BOMB_UP)
    modelComponent->setTexture("./textures/powerup/bombup.png");
  if (type == PowerUpComponent::FIRE_UP)
    modelComponent->setTexture("./textures/powerup/fireup.png");
  powerUp->addComponent(modelComponent);
  powerUp->addComponent(positionComponent);
  powerUp->addComponent(powerUpComponent);
  this->_nextFreeId++;
  return (powerUp);
}
