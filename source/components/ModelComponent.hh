//
// ModelComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 16:51:48 2016 Barthelemy Gouby
// Last update Wed May 11 11:55:58 2016 Barthelemy Gouby
//

#ifndef _MODEL_COMPONENT_HH_
# define _MODEL_COMPONENT_HH_

# include <string>
# include "Component.hh"

class				ModelComponent : public Component
{
public:
  ModelComponent();
  ModelComponent(const std::string &model);
  ~ModelComponent();
  void					setModel(const std::string &model);
  const std::string			&getModel() const;

private:
  std::string				_model;
};

#endif /* !MODEL_COMPONENT */
