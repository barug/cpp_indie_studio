//
// Engine.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 13:48:23 2016 Barthelemy Gouby
// Last update Wed May 11 14:17:26 2016 Barthelemy Gouby
//

#ifndef _ENGINE_HH_
# define _ENGINE_HH_

# include <vector>
# include "EntityManager.hh"
# include "EntityFactory.hh"

class					Engine
{
public:
  Engine();
  ~Engine();

  void					gameLoop();		

private:
  bool					_gameIsOn;
  EntityManager				_entityManager;
  EntityFactory				_entityFactory;
  std::vector<void (Engine::*) ()>	_systems;
};

#endif /* !_ENGINE_HH_ */
