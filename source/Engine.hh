//
// Engine.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Wed May 11 13:48:23 2016 Barthelemy Gouby
// Last update Thu Jun  2 18:38:22 2016 Barthelemy Gouby
//

#ifndef _ENGINE_HH_
# define _ENGINE_HH_

# include <chrono>
# include <vector>
# include "Display.hh"
# include "EntityManager.hh"
# include "EntityFactory.hh"

# define TICK_DURATION			(10)

class					Engine
{
public:
  Engine();
  ~Engine();

  void					initMap();
  void				        initGame(irr::IrrlichtDevice *device);
  void					gameLoop();
  // void					loadSave();
  void					movementSystem();
  void					playerInputSystem();
  void					ExplosiveSystem();
  void					ExplosionSystem();
  void					powerUpSystem();
  void					healthSystem();
  void					guiSystem();

private:
  EntityManager				_entityManager;
  EntityFactory				_entityFactory;
  Display				_display;
  std::chrono::system_clock::time_point	_lastTick;
  bool					_gameIsOn;
  std::vector<void (Engine::*) ()>	_systems;

  void					_addNewExplosion(const unsigned int &x,
							 const unsigned &y,
							 bool &isBlocked);
};

#endif /* !_ENGINE_HH_ */
