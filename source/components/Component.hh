//
// Component.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 12:58:19 2016 Barthelemy Gouby
// Last update Wed May 25 16:48:31 2016 Barthelemy Gouby
//

#ifndef _COMPONENT_HH_
# define _COMPONENT_HH_

# include <string>
# include <vector>

class						Component
{
public:
  enum ComponentType
    {
      POSITION_COMPONENT			= 1,
      SPEED_COMPONENT				= 2,
      MODEL_COMPONENT				= 3,
      SOLIDITY_COMPONENT			= 4,
      HEALTH_COMPONENT				= 5,
      EXPLOSIVE_COMPONENT			= 6,
      EXPLOSION_COMPONENT			= 7,
      POWER_UP_COMPONENT			= 8,
      PLAYER_INPUT_COMPONENT			= 9,
    };

  Component(Component::ComponentType type);
  ~Component();
  const Component::ComponentType		&getType() const;
private:
  const Component::ComponentType		_type;
};

#endif /* !_COMPONENT_HH_ */

