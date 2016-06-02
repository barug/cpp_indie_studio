//
// Main.cpp for cpp_indie_studio in /home/dupard_e/rendus/cpp_indie_studio/source
//
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
//
// Started on  Tue May 10 16:01:52 2016 Erwan Dupard
// Last update Thu Jun  2 21:02:31 2016 Barthelemy Gouby
//

#include "Engine.hh"
#include "Menu.hh"
#include "Resources.hh"

int				main(int argc, char **argv)
{
  Engine			engine;
  Menu				menu;

  menu.startMenu();
  return (RETURN_SUCCESS);
}
