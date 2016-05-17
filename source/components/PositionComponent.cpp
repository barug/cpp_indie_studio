//
// PositionComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 16:13:50 2016 Barthelemy Gouby
// Last update Tue May 17 17:19:14 2016 Barthelemy Gouby
//

#include "PositionComponent.hh"

PositionComponent::PositionComponent()
  : Component("PositionComponent")
{}

PositionComponent::PositionComponent(const unsigned int &x, const unsigned int &y, const unsigned int rotation)
  : Component("PositionComponent"), _x(x), _y(y), _rotation(rotation)
{}

PositionComponent::~PositionComponent()
{}

void				PositionComponent::setX(const unsigned int &x)
{
  this->_x = x;
}

void				PositionComponent::setY(const unsigned int &y)
{
  this->_y = y;
}

const unsigned int			&PositionComponent::getX() const
{
  return (this->_x);
}

const unsigned int			&PositionComponent::getY() const
{
  return (this->_y);
}
