//
// EntityFactory.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 16:07:57 2016 Barthelemy Gouby
// Last update Wed May 11 12:21:35 2016 Barthelemy Gouby
//

#ifndef _ENTITY_FACTORY_HH_
# define _ENTITY_FACTORY_HH_

# include "Entity.hh"
# include "Component.hh"
# include "PositionComponent.hh"
# include "ModelComponent.hh"
# include "SpeedComponent.hh"

class				EntityFactory
{
public:
  EntityFactory();
  ~EntityFactory();

  Entity			*createSolidBlock(const unsigned int &x, const unsigned int &y);

private:
  unsigned int			_nextFreeId;
};

#endif /* !_ENTITY_FACTORY_HH_ */
