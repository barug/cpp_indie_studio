//
// Engine.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Wed May 11 14:06:25 2016 Barthelemy Gouby
// Last update Thu May 19 17:50:14 2016 Thomas Bogard
//

#include <unistd.h>
#include <iostream>
#include "Engine.hh"

Engine::Engine()
  : _systems({&Engine::playerInputSystem, &Engine::movementSystem})
{}

Engine::~Engine()
{}

void					Engine::initGame()
{
  Entity				*player;
  Entity				*test2;

  this->_display.init();
  player = this->_entityFactory.createPlayer(500, 500, 0, irr::KEY_KEY_Z,
					     irr::KEY_KEY_S, irr::KEY_KEY_Q, irr::KEY_KEY_D,
					     irr::KEY_SPACE, &(this->_display));
  this->_entityManager.addEntity(player);
  this->_display.createModel(player->getId(),
  			     (ModelComponent*)player->getComponent("ModelComponent"),
  			     (AnimationComponent*)player->getComponent("AnimationComponent"),
  			     (PositionComponent*)player->getComponent("PositionComponent"));
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
