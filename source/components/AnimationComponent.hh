//
// AnimationComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 11 11:53:00 2016 Barthelemy Gouby
// Last update Wed May 11 12:06:34 2016 Barthelemy Gouby
//

#ifndef ANIMATION_COMPONENT_HH_
# define ANIMATION_COMPONENT_HH_

# include <string>
# include <vector>
# include "Component.hh"

class			AnimationComponent : public Component
{
public:
  AnimationComponent();
  AnimationComponent(const std::vector<std::string> &animations,
		     const unsigned int &selectedAnimation);
  ~AnimationComponent();
  void					setAnimations(const std::vector<std::string> &animations);
  void					changeSelectedAnimation(const unsigned int &animation);
  const std::string			&getSelectedAnimation() const;

private:
  std::vector<std::string>		_animations;
  unsigned int				_selectedAnimation;
};

#endif /* !ANIMATION_COMPONENT_HH_ */
