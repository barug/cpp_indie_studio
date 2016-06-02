//
// Main.cpp for cpp_indie_studio in /home/dupard_e/rendus/cpp_indie_studio/source
//
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
//
// Started on  Tue May 10 16:01:52 2016 Erwan Dupard
// Last update Thu Jun  2 15:05:02 2016 Erwan Dupard
//

#include "Engine.hh"
#include "Resources.hh"
#include <SFML/System.hpp>

int				main(int argc, char **argv)
{
  Engine			engine;

sf::Clock			Clock;  

  engine.initGame();
  engine.gameLoop();
  return (RETURN_SUCCESS);
}
