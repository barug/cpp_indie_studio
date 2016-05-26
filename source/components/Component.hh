//
// Component.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 12:58:19 2016 Barthelemy Gouby
// Last update Thu May 26 15:56:47 2016 Barthelemy Gouby
//

#ifndef _COMPONENT_HH_
# define _COMPONENT_HH_

# include <string>

class						Component
{
public:
  enum ComponentType : unsigned int
    {
      POSITION_COMPONENT			= 0,
      SPEED_COMPONENT				= 1,
      MODEL_COMPONENT				= 2,
      SOLIDITY_COMPONENT			= 3,
      HEALTH_COMPONENT				= 4,
      EXPLOSIVE_COMPONENT			= 5,
      EXPLOSION_COMPONENT			= 6,
      POWER_UP_COMPONENT			= 7,
      PLAYER_INPUT_COMPONENT			= 8
    };

  Component(Component::ComponentType type);
  ~Component();
  const Component::ComponentType		&getType() const;
private:
  const Component::ComponentType		_type;
};

#endif /* !_COMPONENT_HH_ */

