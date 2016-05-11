//
// ModelComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 11:19:20 2016 Barthelemy Gouby
// Last update Wed May 11 11:35:08 2016 Barthelemy Gouby
//

#include "ModelComponent.hh"

ModelComponent::ModelComponent()
  : Component("ModelComponent")
{}

ModelComponent::ModelComponent(const std::string &model,
	       const std::vector<std::string> &animations,
	       const unsigned int &selectedAnimation)
  : Component("ModelComponent"),
    _model(model),
    _animations(animations),
    _selectedAnimation(selectedAnimation)
{}

ModelComponent::~ModelComponent()
{}

void					ModelComponent::setModel(const std::string &model)
{
  this->_model = model;
}

const std::string			&ModelComponent::getModel() const
{
  return (this->_model);
}

void					ModelComponent::setAnimations(const std::vector<std::string> &animations)
{
  this->_animations = animations;
}

void					ModelComponent::changedSelectedAnimation(const unsigned int &animation)
{
  this->_selectedAnimation = animation;
}

const std::string			&ModelComponent::getSelectedAnimation() const
{
  return (this->_animations[this->_selectedAnimation]);
}
