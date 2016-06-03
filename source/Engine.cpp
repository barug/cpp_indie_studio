//
// Engine.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Wed May 11 14:06:25 2016 Barthelemy Gouby
// Last update Fri Jun  3 16:23:12 2016 Barthelemy Gouby
//

#include <unistd.h>
#include <iostream>
#include "Engine.hh"

Engine::Engine()
  : _systems({&Engine::playerInputSystem,
	&Engine::movementSystem,
	&Engine::ExplosiveSystem,
	&Engine::ExplosionSystem,
	&Engine::powerUpSystem,
	&Engine::healthSystem,
	&Engine::guiSystem,
	&Engine::basicEnemySystem})
{
  this->_entityManager.setDisplay(&this->_display);
}

Engine::~Engine()
{}

void					Engine::initMap()
{
  Entity				*entity;
  std::vector<int>			map =
    {
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 8, 0, 2, 2, 0, 0, 3, 0, 0, 2, 2, 0, 0, 1,
      1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1,
      1, 2, 1, 4, 7, 0, 0, 2, 0, 0, 7, 4, 1, 2, 1,
      1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
      1, 0, 2, 2, 0, 0, 0, 5, 0, 0, 0, 2, 2, 0, 1,
      1, 0, 1, 0, 1, 7, 1, 0, 1, 7, 1, 0, 1, 0, 1,
      1, 2, 0, 6, 0, 6, 0, 1, 0, 5, 0, 4, 0, 2, 1,
      1, 0, 1, 0, 1, 7, 1, 0, 1, 7, 1, 0, 1, 0, 1,
      1, 0, 2, 2, 0, 0, 0, 3, 0, 0, 0, 2, 2, 0, 1,
      1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
      1, 2, 1, 3, 7, 0, 0, 2, 0, 0, 7, 3, 1, 2, 1,
      1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1,
      1, 0, 0, 2, 2, 0, 0, 4, 0, 0, 2, 2, 0, 0, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

  for (unsigned int i = 0; i < map.size(); i++)
    {
      if (map[i] != EntityFactory::EMPTY)
	{
	  switch (map[i])
	    {
	    case EntityFactory::SOLID_BLOCK:
	      entity = this->_entityFactory.createSolidBlock((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
							     (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2, 0);
	      break;
	    case EntityFactory::DESTRUCTIBLE_BLOCK:
	      entity = this->_entityFactory.createDestructibleBlock((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								    (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2, 0);
	      break;
	    case EntityFactory::BOMB_UP_POWER_UP:
	      entity = this->_entityFactory.createPowerUpContainer((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   PowerUpComponent::BOMB_UP);
	      break;
	    case EntityFactory::FIRE_UP_POWER_UP:
	      entity = this->_entityFactory.createPowerUpContainer((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   PowerUpComponent::FIRE_UP);
	      break;
	    case EntityFactory::SPEED_UP_POWER_UP:
	      entity = this->_entityFactory.createPowerUpContainer((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   PowerUpComponent::SPEED_UP);
	      break;
	    case EntityFactory::LIVE_UP_POWER_UP:
	      entity = this->_entityFactory.createPowerUpContainer((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   PowerUpComponent::LIVE_UP);
	      break;
	    case EntityFactory::BASIC_ENEMY:
	      entity = this->_entityFactory.createBasicEnemy((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
							     (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2);
	      break;
	    case EntityFactory::PLAYER_ONE:
	      entity = this->_entityFactory.createPlayer((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
							 (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
							 0,
							 irr::KEY_KEY_Z,
							 irr::KEY_KEY_S, irr::KEY_KEY_Q, irr::KEY_KEY_D,
							 irr::KEY_SPACE, 1, 1, 50, &(this->_display));
	      break;
	    default:
	      break;
	    }
          this->_display.createModel(entity);
	  this->_entityManager.addEntity(entity);
	}
    }
}

void					Engine::initGame(irr::IrrlichtDevice *device,
							 EventReceiver *receiver,
							 GameType gameType)
{
  Entity				*player1;
  Entity				*player2;

  this->_gameType = gameType;
  this->_display.init(device, receiver);
  this->initMap();
}

void					Engine::setVolumeMusic(const unsigned int &volume)
{
  this->_audio.musicSetVolume(volume);
}

void					Engine::setVolumeSound(const unsigned int &volume)
{
  this->_audio.soundSetVolume(volume);
}

void					Engine::saveGame(const std::string &fileName)
{
  this->_entityManager.serialize(fileName);
}

void					Engine::loadSave(const std::string &fileName,
							 EventReceiver *receiver,
							 irr::IrrlichtDevice *device)
{
  this->_entityManager.unserialize(fileName);
  this->_display.init(device, receiver);
}

void					Engine::gameLoop()
{
  std::chrono::system_clock::time_point	now;

  this->_gameIsOn = true;
  this->_lastTick = std::chrono::system_clock::now();
  this->_display.setCursorVisibility(false);
  this->_audio.makeMusic("sound/mortalkombat.wav");
  this->_audio.musicSetLoop(true);
  while (this->_gameIsOn)
    {
      now = std::chrono::system_clock::now();
      if (std::chrono::duration_cast<std::chrono::milliseconds>(now - this->_lastTick).count() > TICK_DURATION)
	{
	  this->_lastTick = now;
	  for (auto system: this->_systems)
	    (this->*system)();
	}
      (this->_display.windowIsActive() ? this->_display.refreshScreen() : this->_gameIsOn = false);
    }
  this->_display.setCursorVisibility(true);
  // this->_display.closeDisplay();
}
