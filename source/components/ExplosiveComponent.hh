//
// ExplosiveComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May 23 11:18:50 2016 Barthelemy Gouby
// Last update Mon May 23 12:32:53 2016 Barthelemy Gouby
//

#ifndef _EXPLOSIVE_COMPONENT_HH_
# define _EXPLOSIVE_COMPONENT_HH_

# include "Component.hh"

class			ExplosiveComponent : public Component
{
public:
  ExplosiveComponent(const unsigned int &timerLength,
		     const unsigned int &explosionSize);

  const unsigned int	&getTimerLength();
  const unsigned int	&getExplosionSize();
  void			setTimerLength(const unsigned int &newLength);
private:
  unsigned int		_timerLength;
  unsigned int		_explosionSize;
};

#endif /* !_EXPLOSIVE_COMPONENT_HH_ */
