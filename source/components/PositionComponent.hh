//
// PositionComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Mon May  2 16:11:32 2016 Barthelemy Gouby
// Last update Sun May 22 04:01:03 2016 Thomas Bogard
//

#ifndef _POSITION_COMPONENT_HH_
# define _POSITION_COMPONENT_HH_

# include <string>
# include "Component.hh"

class				PositionComponent : public Component
{
public:
  PositionComponent();
  PositionComponent(const unsigned int &x, const unsigned int &y, const unsigned int rotation);
  ~PositionComponent();
  void				setX(const unsigned int &x);
  void				setY(const unsigned int &y);
  void				setOldX(const unsigned int &oldx);
  void				setOldY(const unsigned int &oldy);
  void				setRotation(const unsigned int &rotation);
  const unsigned int			&getX() const;
  const unsigned int			&getY() const;
  const unsigned int			&getOldX() const;
  const unsigned int			&getOldY() const;
  const unsigned int			&getRotation() const;

private:
  unsigned int				_x;
  unsigned int				_y;
  unsigned int				_old_x;
  unsigned int				_old_y;
  unsigned int				_rotation;
};

#endif /* !POSITION_COMPONENT */
