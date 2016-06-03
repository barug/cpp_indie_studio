//
// Engine.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Wed May 11 13:48:23 2016 Barthelemy Gouby
// Last update Fri Jun  3 15:34:36 2016 Thomas Bogard
//

#ifndef _ENGINE_HH_
# define _ENGINE_HH_

# include <chrono>
# include <vector>
# include <random>
# include "Audio.hh"
# include "Display.hh"
# include "EntityManager.hh"
# include "EntityFactory.hh"

# define TICK_DURATION			(10)

enum GameType
  {
    SOLO,
    VERSUS,
    COOP
  };

class					Engine
{
public:
  enum GameType
    {
      SOLO,
      VERSUS,
      COOP
    };

  Engine();
  ~Engine();

  void					initMap();
  void				        initGame(irr::IrrlichtDevice *device,
						 EventReceiver *receiver,
						 GameType gameType);
  void					gameLoop();
  void					setVolumeMusic(const unsigned int &volume);
  void					setVolumeSound(const unsigned int &volume);
  void					loadSave(const std::string &fileName);
  void					saveGame(const std::string &fileName);
  void					movementSystem();
  void					playerInputSystem();
  void					ExplosiveSystem();
  void					ExplosionSystem();
  void					powerUpSystem();
  void					healthSystem();
  void					guiSystem();
  void					basicEnemySystem();

private:
  EntityManager				_entityManager;
  EntityFactory				_entityFactory;
  Display				_display;
  Audio					_audio;
  std::chrono::system_clock::time_point	_lastTick;
  bool					_gameIsOn;
  std::vector<void (Engine::*) ()>	_systems;
  Engine::GameType			_gameType;
  void					_addNewExplosion(const unsigned int &x,
							 const unsigned &y,
							 bool &isBlocked);
};

#endif /* !_ENGINE_HH_ */
