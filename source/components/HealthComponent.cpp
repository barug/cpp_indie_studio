//
// DestructibleComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/components
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May 23 17:11:08 2016 Barthelemy Gouby
// Last update Wed May 25 15:53:00 2016 Barthelemy Gouby
//

#include "HealthComponent.hh"

HealthComponent::HealthComponent(const unsigned int &lives)
  : Component(Component::HEALTH_COMPONENT),
    _lives(lives)
{}

const unsigned int		&HealthComponent::getLives() const
{
  return (this->_lives);
}

void				HealthComponent::setLives(const unsigned int &lives)
{
  this->_lives = lives;
}
