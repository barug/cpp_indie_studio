//
// Engine.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Wed May 11 14:06:25 2016 Barthelemy Gouby
// Last update Mon May 23 14:28:53 2016 Barthelemy Gouby
//

#include <unistd.h>
#include <iostream>
#include "Engine.hh"

Engine::Engine()
  : _systems({&Engine::playerInputSystem,
	&Engine::movementSystem,
	&Engine::ExplosiveSystem})
{}

Engine::~Engine()
{}

void					Engine::initGame()
{
  Entity				*player1;
  Entity				*player2;
  Entity				*test2;
  Entity				*test3;
  Entity				*test4;
  Entity				*bomb;

  this->_display.init();
  test2 = this->_entityFactory.createSolidBlock(1000, 1000, 0);
  test3 = this->_entityFactory.createSolidBlock(1675, 1675, 0);
  test4 = this->_entityFactory.createSolidBlock(1735, 872, 0);

  player1 = this->_entityFactory.createPlayer(500, 500, 0, irr::KEY_KEY_Z,
					     irr::KEY_KEY_S, irr::KEY_KEY_Q, irr::KEY_KEY_D,
					     irr::KEY_SPACE, &(this->_display));
  player2 = this->_entityFactory.createPlayer(4000, 4000, 0, irr::KEY_UP,
					     irr::KEY_DOWN, irr::KEY_RIGHT, irr::KEY_LEFT,
					     irr::KEY_RETURN, &(this->_display));
  bomb = this->_entityFactory.createNormalBomb(2000, 2000, 0);
  this->_entityManager.addEntity(player1);
  this->_entityManager.addEntity(player2);
  this->_entityManager.addEntity(test2);
  this->_entityManager.addEntity(test3);
  this->_entityManager.addEntity(test4);
  this->_entityManager.addEntity(bomb);

  this->_display.createModel(player1);
  this->_display.createModel(player2);
  this->_display.createModel(test2);
  this->_display.createModel(test3);
  this->_display.createModel(test4);
  this->_display.createModel(bomb);

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
