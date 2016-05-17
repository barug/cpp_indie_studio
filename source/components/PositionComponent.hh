//
// PositionComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 16:11:32 2016 Barthelemy Gouby
// Last update Tue May 17 16:23:24 2016 Barthelemy Gouby
//

#ifndef _POSITION_COMPONENT_HH_
# define _POSITION_COMPONENT_HH_

# include <string>
# include "Component.hh"

class				PositionComponent : public Component
{
public:
  PositionComponent();
  PositionComponent(const int &x, const int &y, const int rotation);
  ~PositionComponent();
  void				setX(const int &x);
  void				setY(const int &y);
  void				setRotation(const int &rotation);
  const int			&getX() const;
  const int			&getY() const;
  const int			&getRotation() const;

private:
  int				_x;
  int				_y;
  int				_rotation;
};

#endif /* !POSITION_COMPONENT */
