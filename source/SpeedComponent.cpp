//
// SpeedComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 14:22:56 2016 Barthelemy Gouby
// Last update Mon May  2 14:28:56 2016 Barthelemy Gouby
//

#include "SpeedComponent.hh"

SpeedComponent()
  : Component("SpeedComponent")
{}

SpeedComponent(const int &speedX, const int &speedY, const int &rotation)
  : Component("SpeedComponent"), _speedX(speedX), _speedY(speedY), _rotation(rotation)

~SpeedComponent()
{}

int				setSpeedX(const int &speedX)
{
  this->_speedX = speedX;
}

int				setSpeedY(const int &speedY)
{
  this->_speedY = speedY;
}

int				setRotation(const int &rotation)
{
  this->_rotation = rotation;
}

const int			&getSpeedX() const
{
  return (this->_speedX);
}

const int			&getSpeedY() const
{
  return (this->_speedY);
}

const int			&getRotation() const
{
  return (this->_rotation);
}
