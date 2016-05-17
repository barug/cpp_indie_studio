//
// ModelComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 11:19:20 2016 Barthelemy Gouby
// Last update Fri May 13 18:00:45 2016 Barthelemy Gouby
//

#include "ModelComponent.hh"

ModelComponent::ModelComponent()
  : Component("ModelComponent")
{}

ModelComponent::ModelComponent(const std::string &model,
			       const std::string &texture,
			       unsigned int &scale)
  : Component("ModelComponent"),
    _model(model),
    _texture(texture),
    _scale(scale)
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

void					setTexture(const std::string &texture)
{
  this->_texture = texture;
}

const std::string			&getTexture() const
{
  return (this->_texture);
}

void					setScale(const unsigned int &&scale)
{
  this->_scale = scale;
}

const unsigned int			&getScale() const
{
  return (this->_scale);
}
