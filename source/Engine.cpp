//
// Engine.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 14:06:25 2016 Barthelemy Gouby
// Last update Wed May 11 16:23:32 2016 Barthelemy Gouby
//

#include "Engine.hh"

Engine::Engine()
  : _systems({&Engine::movementSystem})
{}

Engine::~Engine()
{}

void					Engine::gameLoop()
{
  std::chrono::system_clock::time_point	now;
  
  this->_lastTick = std::chrono::system_clock::now();
  while (this->_gameIsOn)
    {
      now = std::chrono::system_clock::now();
      if (std::chrono::duration_cast<std::chrono::milliseconds>(this->_lastTick - now).count() > TICK_DURATION)
	{
	  this->_lastTick = now;
	  for (auto system: this->_systems)
	    (this->*system)();
	}
    }
}
