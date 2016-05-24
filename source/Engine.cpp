//
// Engine.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Wed May 11 14:06:25 2016 Barthelemy Gouby
// Last update Mon May 23 18:48:20 2016 Barthelemy Gouby
//

#include <unistd.h>
#include <iostream>
#include "Engine.hh"

Engine::Engine()
  : _systems({&Engine::playerInputSystem,
	&Engine::movementSystem,
	&Engine::ExplosiveSystem,
	&Engine::ExplosionSystem})
{}

Engine::~Engine()
{}

void					Engine::initMap()
{
  Entity				*entity;
  std::vector<int>			map =
    {
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
      1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

  for (unsigned int i = 0; i < map.size(); i++)
    {
      if (map.at(i) == SOLIDBLOCK)
        {
          entity = this->_entityFactory.createSolidBlock((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
							 (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2, 0);
          this->_display.createModel(entity);
	  this->_entityManager.addEntity(entity);
        }
      else if (map.at(i) == BOT)
        {
          entity = this->_entityFactory.createSolidBlock((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
							 (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2, 0);
          this->_display.createModel(entity);
	  this->_entityManager.addEntity(entity);
        }
    }
}

void					Engine::initGame()
{
  Entity				*player1;
  Entity				*player2;

  this->_display.init();
  player1 = this->_entityFactory.createPlayer(1000, 1000, 0, irr::KEY_KEY_Z,
					     irr::KEY_KEY_S, irr::KEY_KEY_Q, irr::KEY_KEY_D,
					     irr::KEY_SPACE, &(this->_display));
  player2 = this->_entityFactory.createPlayer(4000, 4000, 0, irr::KEY_UP,
					     irr::KEY_DOWN, irr::KEY_RIGHT, irr::KEY_LEFT,
					     irr::KEY_RETURN, &(this->_display));

  this->_entityManager.addEntity(player1);
  this->_entityManager.addEntity(player2);
  this->_display.createModel(player1);
  this->_display.createModel(player2);

  this->initMap();
}

void					Engine::gameLoop()
{
  std::chrono::system_clock::time_point	now;

  this->_lastTick = std::chrono::system_clock::now();
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
  this->_display.closeDisplay();
}
