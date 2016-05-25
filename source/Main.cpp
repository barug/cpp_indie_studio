//
// Main.cpp for cpp_indie_studio in /home/dupard_e/rendus/cpp_indie_studio/source
//
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
//
// Started on  Tue May 10 16:01:52 2016 Erwan Dupard
// Last update Wed May 25 14:27:59 2016 Erwan Dupard
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
