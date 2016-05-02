//
// SpeedComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 14:17:14 2016 Barthelemy Gouby
// Last update Mon May  2 14:26:41 2016 Barthelemy Gouby
//

#ifndef _SPEED_COMPONENT_HH_
# define _SPEED_COMPONENT_HH_

# include <string>

class				SpeedComponent : public Component
{
public:
  SpeedComponent();
  SpeedComponent(const int &speedX, const int &speedY, const int &rotation);
  ~SpeedComponent();
  int				setSpeedX(const int &speedX);
  int				setSpeedY(const int &speedY);
  int				setRotation(const int &rotation);
  const int			&getSpeedX() const;
  const int			&getSpeedY() const;
  const int			&getRotation() const;

private:
  int				_speedX;
  int				_speedY;
  double			_rotation;
};

#endif /* !_SPEED_COMPONENT_HH_ */
