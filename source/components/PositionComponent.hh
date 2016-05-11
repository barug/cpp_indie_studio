//
// PositionComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 16:11:32 2016 Barthelemy Gouby
// Last update Mon May  2 16:45:26 2016 Barthelemy Gouby
//

#ifndef _POSITION_COMPONENT_HH_
# define _POSITION_COMPONENT_HH_

# include <string>
# include "Component.hh"

class				PositionComponent : public Component
{
public:
  PositionComponent();
  PositionComponent(const int &x, const int &y);
  ~PositionComponent();
  void				setX(const int &x);
  void				setY(const int &y);
  const int			&getX() const;
  const int			&getY() const;

private:
  int				_x;
  int				_y;
};

#endif /* !POSITION_COMPONENT */
