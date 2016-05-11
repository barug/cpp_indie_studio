//
// ModelComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 11:19:20 2016 Barthelemy Gouby
// Last update Wed May 11 11:59:41 2016 Barthelemy Gouby
//

#include "ModelComponent.hh"

ModelComponent::ModelComponent()
  : Component("ModelComponent")
{}

ModelComponent::ModelComponent(const std::string &model)
  : Component("ModelComponent"),
    _model(model)
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
