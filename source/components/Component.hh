//
// Component.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 12:58:19 2016 Barthelemy Gouby
// Last update Wed May 25 12:34:39 2016 Barthelemy Gouby
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
      POSITION_COMPONENT,
      SPEED_COMPONENT,
      MODEL_COMPONENT,
      SOLIDITY_COMPONENT,
      DESTRUCTIBLE_COMPONENT,
      EXPLOSIVE_COMPONENT,
      EXPLOSION_COMPONENT,
      POWER_UP_COMPONENT,
      PLAYER_INPUT_COMPONENT,
    };

  Component(Component::ComponentType type);
  ~Component();
  const Component::ComponentType		&getType() const;
private:
  const Component::ComponentType		_type;
};

#endif /* !_COMPONENT_HH_ */

