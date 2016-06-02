//
// Main.cpp for cpp_indie_studio in /home/dupard_e/rendus/cpp_indie_studio/source
//
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
//
// Started on  Tue May 10 16:01:52 2016 Erwan Dupard
// Last update Thu Jun  2 17:26:54 2016 Thomas Bogard
//

#include "Engine.hh"
#include "Resources.hh"

int				main(int argc, char **argv)
{
  Engine			engine;

  engine.initGame();
  engine.gameLoop();
  return (RETURN_SUCCESS);
}
