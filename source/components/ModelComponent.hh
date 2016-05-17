//
// ModelComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 16:51:48 2016 Barthelemy Gouby
// Last update Fri May 13 17:58:31 2016 Barthelemy Gouby
//

#ifndef _MODEL_COMPONENT_HH_
# define _MODEL_COMPONENT_HH_

# include <string>
# include "Component.hh"

class				ModelComponent : public Component
{
public:
  ModelComponent();
  ModelComponent(const std::string &model,
		 const std::string &texture,
		 unsigned int &scale);
  ~ModelComponent();
  void					setModel(const std::string &model);
  const std::string			&getModel() const;
  void					setTexture(const std::string &texture);
  const std::string			&getTexture() const;
  void					setScale(const unsigned int &&scale);
  const unsigned int			&getScale() const;

private:
  std::string				_model;
  std::string				_texture;
  unsigned int				_scale;
};

#endif /* !MODEL_COMPONENT */
