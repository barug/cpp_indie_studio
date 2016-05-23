//
// DestructibleComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/components
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May 23 17:07:02 2016 Barthelemy Gouby
// Last update Mon May 23 17:15:40 2016 Barthelemy Gouby
//

#include "Component.hh"

#ifndef _DESTRUCTIBLE_COMPONENT_HH_
# define _DESTRUCTIBLE_COMPONENT_HH_

class				DestructibleComponent : public Component
{
public:
  enum				DestructibleType
    {
      BLOCK,
      PLAYER,
      MONSTER
    };

  DestructibleComponent(const DestructibleType type);
  const DestructibleType	&getType() const;

private:
  DestructibleType		_type;
};

#endif /* !_DESTRUCTIBLE_COMPONENT_HH_ */
