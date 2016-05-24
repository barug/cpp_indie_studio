//
// Engine.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Wed May 11 13:48:23 2016 Barthelemy Gouby
// Last update Mon May 23 19:01:50 2016 Barthelemy Gouby
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
    SOLID_BLOCK,
    DESTRUCTIBLE_BLOCK,
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
  void					ExplosionSystem();
private:
  EntityManager				_entityManager;
  EntityFactory				_entityFactory;
  Display				_display;
  std::chrono::system_clock::time_point	_lastTick;
  bool					_gameIsOn;
  std::vector<void (Engine::*) ()>	_systems;

  void					_addNewExplosion(const unsigned int &x,
							 const unsigned &y,
							 std::vector<Entity*> *solids,
							 bool &isBlocked);
};

#endif /* !_ENGINE_HH_ */
