//
// Entity.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 12:51:51 2016 Barthelemy Gouby
// Last update Mon May  2 13:02:21 2016 Barthelemy Gouby
//

#ifndef _ENTITY_HH_
# define _ENTITY_HH_

# include <string>
# include "Component.hh"

class				Entity
{
public:
  Entity(const int &id);
  ~Entity();
  void				addComponent(Component *component);
  void				removeComponent(const std::string &type);
  Component			*getComponent(const std::string &type);

private:
  const int			_id;
  std::vector<Component*>	_components;
};

#endif /* !_ENTITY_HH_ */
