//
// Component.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 13:02:59 2016 Barthelemy Gouby
// Last update Mon May  2 16:30:19 2016 Barthelemy Gouby
//

#include "Component.hh"

Component::Component(const std::string &type)
  : _type(type)
{}

Component::~Component()
{}

const std::string		&Component::getType() const
{
  return (this->_type);
}
