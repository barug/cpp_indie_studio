//
// ExplosionComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May 23 12:27:41 2016 Barthelemy Gouby
// Last update Mon May 23 12:30:31 2016 Barthelemy Gouby
//

#include "ExplosionComponent.hh"

ExplosionComponent::ExplosionComponent(const unsigned int &explosionDuration)
  : Component("ExplosionComponent"),
    _explosionDuration(explosionDuration)
{}

const unsigned int	&ExplosionComponent::getExplosionDuration()
{
  return (this->_explosionDuration);
}

void			ExplosionComponent::setExplosionDuration(const unsigned int &newExplosionDuration)
{
  this->_explosionDuration = newExplosionDuration;
}
