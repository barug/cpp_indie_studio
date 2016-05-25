//
// Component.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 13:02:59 2016 Barthelemy Gouby
// Last update Wed May 25 12:40:45 2016 Barthelemy Gouby
//

#include "Component.hh"

Component::Component(Component::ComponentType type)
  : _type(type)
{}

Component::~Component()
{}

const Component::ComponentType		&Component::getType() const
{
  return (this->_type);
}
