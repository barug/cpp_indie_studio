//
// Entity.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 12:51:51 2016 Barthelemy Gouby
// Last update Wed May 25 12:14:58 2016 Barthelemy Gouby
//

#ifndef _ENTITY_HH_
# define _ENTITY_HH_

# include <string>
# include <vector>
# include "components/Component.hh"

class				Entity
{
public:
  Entity(const unsigned int &id);
  ~Entity();
  const unsigned int		&getId() const;
  void				addComponent(Component *component);
  void				removeComponent(Component::ComponentType type);
  Component			*getComponent(Component::ComponentType type);

private:
  const unsigned int		_id;
  std::vector<Component*>	_components;
};

#endif /* !_ENTITY_HH_ */
