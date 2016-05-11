//
// AnimationComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 11:56:37 2016 Barthelemy Gouby
// Last update Wed May 11 12:04:00 2016 Barthelemy Gouby
//

#include "AnimationComponent.hh"

AnimationComponent::AnimationComponent()
  : Component("AnimationComponent")
{}

AnimationComponent::AnimationComponent(const std::vector<std::string> &animations,
		   const unsigned int &selectedAnimation)
  : Component("AnimationComponent"),
    _animations(animations),
    _selectedAnimation(selectedAnimation)
{}

AnimationComponent::~AnimationComponent()
{}

void				        AnimationComponent::setAnimations(const std::vector<std::string> &animations)
{
  this->_animations = animations;
}

void				        AnimationComponent::changeSelectedAnimation(const unsigned int &animation)
{
  this->_selectedAnimation = animation;
}

const std::string			&AnimationComponent::getSelectedAnimation() const
{
  return (this->_animations[this->_selectedAnimation]);
}
