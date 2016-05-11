//
// PositionComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 16:13:50 2016 Barthelemy Gouby
// Last update Mon May  2 16:45:11 2016 Barthelemy Gouby
//

#include "PositionComponent.hh"

PositionComponent::PositionComponent()
  : Component("PositionComponent")
{}

PositionComponent::PositionComponent(const int &x, const int &y)
  : Component("PositionComponent"), _x(x), _y(y)
{}

PositionComponent::~PositionComponent()
{}

void				PositionComponent::setX(const int &x)
{
  this->_x = x;
}

void				PositionComponent::setY(const int &y)
{
  this->_y = y;
}

const int			&PositionComponent::getX() const
{
  return (this->_x);
}

const int			&PositionComponent::getY() const
{
  return (this->_y);
}
