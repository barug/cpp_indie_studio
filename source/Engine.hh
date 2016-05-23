//
// Engine.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Wed May 11 13:48:23 2016 Barthelemy Gouby
// Last update Mon May 23 14:56:18 2016 Thomas Bogard
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

enum
  {
    EMPTY = 0,
    SOLIDBLOCK,
    BOT
  };

class					Engine
{
public:
  Engine();
  ~Engine();

  void					initMap();
  void				        initGame();
  void					gameLoop();

  void					movementSystem();
  void					playerInputSystem();
  void					ExplosiveSystem();
private:
  EntityManager				_entityManager;
  EntityFactory				_entityFactory;
  Display				_display;
  std::chrono::system_clock::time_point	_lastTick;
  bool					_gameIsOn;
  std::vector<void (Engine::*) ()>	_systems;
};

#endif /* !_ENGINE_HH_ */
