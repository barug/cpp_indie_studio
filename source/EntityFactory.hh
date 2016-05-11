//
// EntityFactory.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 16:07:57 2016 Barthelemy Gouby
// Last update Mon May  2 16:31:31 2016 Barthelemy Gouby
//

#ifndef _ENTITY_FACTORY_HH_
# define _ENTITY_FACTORY_HH_

# include "Entity.hh"
# include "Component.hh"
# include "SpeedComponent.hh"

class				EntityFactory
{
public:
  EntityFactory();
  ~EntityFactory();

  Entity			*createSolidBlock(const unsigned int x, const unsigned int y);
  
};

#endif /* !_ENTITY_FACTORY_HH_ */
