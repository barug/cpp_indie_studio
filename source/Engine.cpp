//
// Engine.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 14:06:25 2016 Barthelemy Gouby
// Last update Wed May 11 14:39:07 2016 Barthelemy Gouby
//

#include "Engine.hh"

Engine::Engine()
{}

Engine::~Engine()
{}

void			Engine::gameLoop()
{
  while (this->_gameIsOn)
    {
      for (auto system: this->_systems)
	(this->*system)();
    }
}
