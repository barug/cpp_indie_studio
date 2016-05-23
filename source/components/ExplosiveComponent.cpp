//
// ExplosiveComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May 23 11:26:56 2016 Barthelemy Gouby
// Last update Mon May 23 12:21:47 2016 Barthelemy Gouby
//

#include "ExplosiveComponent.hh"

ExplosiveComponent::ExplosiveComponent(const unsigned int &timerLength,
				       const unsigned int &explosionSize)
  : Component("ExplosiveComponent"),
    _timerLength(timerLength),
    _explosionSize(explosionSize)
{}

const unsigned int	&ExplosiveComponent::getTimerLength()
{
  return (this->_timerLength);
}

const unsigned int	&ExplosiveComponent::getExplosionSize()
{
  return (this->_explosionSize);
}

void			ExplosiveComponent::setTimerLength(const unsigned int &newLength)
{
  this->_timerLength = newLength;
}
