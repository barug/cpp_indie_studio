//
// DestructibleComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/components
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May 23 17:11:08 2016 Barthelemy Gouby
// Last update Mon May 23 17:16:31 2016 Barthelemy Gouby
//

#include "DestructibleComponent.hh"

DestructibleComponent::DestructibleComponent(const DestructibleType type)
  : Component("DestructibleComponent"), _type(type)
{}

const DestructibleComponent::DestructibleType	&DestructibleComponent::getType() const
{
  return (this->_type);
}
