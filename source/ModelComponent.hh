//
// ModelComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 16:51:48 2016 Barthelemy Gouby
// Last update Wed May 11 11:32:15 2016 Barthelemy Gouby
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
		 const std::vector<std::string> &animations,
		 const unsigned int &selectedAnimation);
  ~ModelComponent();
  void					setModel(const std::string &model);
  const std::string			&getModel() const;
  void					setAnimations(const std::vector<std::string> &animations);
  void					changedSelectedAnimation(const unsigned int &animation);
  const std::string			&getSelectedAnimation() const;

private:
  std::string				_model;
  std::vector<std::string>		_animations;
  unsigned int				_selectedAnimation;
};

#endif /* !MODEL_COMPONENT */
