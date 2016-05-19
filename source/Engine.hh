//
// Engine.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 13:48:23 2016 Barthelemy Gouby
// Last update Thu May 19 13:37:03 2016 Barthelemy Gouby
//

#ifndef _ENGINE_HH_
# define _ENGINE_HH_

# include <chrono>
# include <vector>
# include "Display.hh"
# include "EntityManager.hh"
# include "EntityFactory.hh"

# define TICK_DURATION			(10)
# define PLAYER_MOVEMENT_SPEED		(50)

class					Engine
{
public:
  Engine();
  ~Engine();

  void				        initGame();
  void					gameLoop();

  void					movementSystem();
  void					playerInputSystem();
private:
  EntityManager				_entityManager;
  EntityFactory				_entityFactory;
  Display				_display;
  std::chrono::system_clock::time_point	_lastTick;
  bool					_gameIsOn;
  std::vector<void (Engine::*) ()>	_systems;
};

#endif /* !_ENGINE_HH_ */
