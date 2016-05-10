//
// Main.cpp for cpp_indie_studio in /home/dupard_e/rendus/cpp_indie_studio/source
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue May 10 16:01:52 2016 Erwan Dupard
// Last update Tue May 10 16:04:17 2016 Erwan Dupard
//

#include "Display.hh"
#include "Resources.hh"

int				main(int argc, char **argv)
{
  Display			display;

  display.init();
  display.run();
  return (RETURN_SUCCESS);
}
