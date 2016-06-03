//
// basicEnemySystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Fri May 27 18:51:39 2016 Barthelemy Gouby
// Last update Fri Jun  3 14:55:26 2016 Barthelemy Gouby
//

#include "../Engine.hh"

void					Engine::basicEnemySystem()
{
  std::vector<Entity*>			*basicEnemies =
    this->_entityManager.getEntitiesWithComponents({Component::BASIC_ENEMY_COMPONENT});
  std::vector<Entity*>			*solids =
    this->_entityManager.getEntitiesWithComponents({Component::SOLIDITY_COMPONENT});
  std::vector<Entity*>			*players =
    this->_entityManager.getEntitiesWithComponents({Component::PLAYER_INPUT_COMPONENT});
  BasicEnemyComponent			*basicEnemyComponent;
  PositionComponent			*positionComponent;
  SpeedComponent			*speedComponent;
  HealthComponent			*healthComponent;
  PositionComponent			validTiles[4];
  unsigned int				numberOfValidTiles;
  bool					upIsValid;
  bool					downIsValid;
  bool					leftIsValid;
  bool					rightIsValid;
  std::random_device			rd;
  std::mt19937				rng(rd());
  int					randomTile;

  for (Entity *basicEnemy: *basicEnemies)
    {
      basicEnemyComponent = (BasicEnemyComponent*) basicEnemy->getComponent(Component::BASIC_ENEMY_COMPONENT);
      positionComponent = (PositionComponent*) basicEnemy->getComponent(Component::POSITION_COMPONENT);
      speedComponent = (SpeedComponent*) basicEnemy->getComponent(Component::SPEED_COMPONENT);

      for (Entity *player: *players)
	{
	  if (this->_display.collision(basicEnemy->getId(), player->getId()))
	    {
	      healthComponent = (HealthComponent*) player->getComponent(Component::HEALTH_COMPONENT);
	      if (healthComponent->getInvincibleTimer() <= 0)
		{
		  healthComponent->setLives(healthComponent->getLives() - 1);
		  healthComponent->setInviciblesTimer(110);
		}
	    }
	}

      if (basicEnemyComponent->getTileGoingToX() == positionComponent->getX()
	  && basicEnemyComponent->getTileGoingToY() == positionComponent->getY())
	{ 
	  std::cout << "searching new direction" << std::endl;
	  numberOfValidTiles = 0;
	  if (speedComponent->getSpeedY() < 0)
	    upIsValid = false;
	  else
	    upIsValid = true;
	  if (speedComponent->getSpeedY() > 0)
	    downIsValid = false;
	  else
	    downIsValid = true;
	  if (speedComponent->getSpeedX() > 0)
	    leftIsValid = false;
	  else
	    leftIsValid = true;
	  if (speedComponent->getSpeedX() < 0)
	    rightIsValid = false;
	  else
	    rightIsValid = true;
	  for (Entity *solid: *solids)
	    {
	      if (this->_display.tileIsOccupied(positionComponent->getX(),
						positionComponent->getY() + TILE_SIZE,
						solid))
		upIsValid = false;
	      if (this->_display.tileIsOccupied(positionComponent->getX(),
						positionComponent->getY() - TILE_SIZE,
						solid))
		downIsValid = false;
	      if (this->_display.tileIsOccupied(positionComponent->getX() - TILE_SIZE,
						positionComponent->getY(),
						solid))
		leftIsValid = false;
	      if (this->_display.tileIsOccupied(positionComponent->getX() + TILE_SIZE,
						positionComponent->getY(),
						solid))
		rightIsValid = false;
	    }
	  if (upIsValid)
	    {
	      validTiles[numberOfValidTiles].setX(positionComponent->getX());
	      validTiles[numberOfValidTiles].setY(positionComponent->getY() + TILE_SIZE);
	      numberOfValidTiles++;
	      std::cout << "up free" << std::endl;
	    }
	  if (downIsValid)
	    {
	      validTiles[numberOfValidTiles].setX(positionComponent->getX());
	      validTiles[numberOfValidTiles].setY(positionComponent->getY() - TILE_SIZE);
	      numberOfValidTiles++;
	      std::cout << "down free" << std::endl;
	    }
	  if (leftIsValid)
	    {
	      validTiles[numberOfValidTiles].setX(positionComponent->getX() - TILE_SIZE);
	      validTiles[numberOfValidTiles].setY(positionComponent->getY());
	      numberOfValidTiles++;
	      std::cout << "left free" << std::endl;
	    }
	  if (rightIsValid)
	    {
	      validTiles[numberOfValidTiles].setX(positionComponent->getX() + TILE_SIZE);
	      validTiles[numberOfValidTiles].setY(positionComponent->getY());
	      numberOfValidTiles++;
	      std::cout << "right free" << std::endl;
	    }
	  std::cout << "numberOfValidTiles:  " << numberOfValidTiles << std::endl;
	  if (numberOfValidTiles > 0)
	    {
	      std::uniform_int_distribution<int>	distribution(1, numberOfValidTiles);
	      randomTile = distribution(rng) - 1;
	      std::cout << "random tile :" << randomTile << std::endl;
	      basicEnemyComponent->setTileGoingToX(validTiles[randomTile].getX());
	      basicEnemyComponent->setTileGoingToY(validTiles[randomTile].getY());
	    }
	  else
	    {
	      basicEnemyComponent->setTileGoingToX(basicEnemyComponent->getTileComingFromX());
	      basicEnemyComponent->setTileGoingToY(basicEnemyComponent->getTileComingFromY());
	    }
	  basicEnemyComponent->setTileComingFromX(positionComponent->getX());
	  basicEnemyComponent->setTileComingFromY(positionComponent->getY());
	  std::cout << "player x: " << positionComponent->getX()
		    << " player y: " << positionComponent->getY() << std::endl;
	  std::cout << "new direction x: " << basicEnemyComponent->getTileGoingToX()
		    << " new direction y: " << basicEnemyComponent->getTileGoingToY() << std::endl;
	  speedComponent->setSpeedY(0);
	  speedComponent->setSpeedX(0);
	  if (basicEnemyComponent->getTileGoingToY() > positionComponent->getY())
	    speedComponent->setSpeedY(50);
	  else if (basicEnemyComponent->getTileGoingToY() < positionComponent->getY())
	    speedComponent->setSpeedY(- 50);
	  else if (basicEnemyComponent->getTileGoingToX() > positionComponent->getX())
	    speedComponent->setSpeedX(50);
	  else if (basicEnemyComponent->getTileGoingToX() < positionComponent->getX())
	    speedComponent->setSpeedX(- 50);
	  std::cout << "new speed x: " << speedComponent->getSpeedX()
		    << " new speed y: " << speedComponent->getSpeedY() << std::endl;	    
	}
    }
}
