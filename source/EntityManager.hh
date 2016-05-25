//
// EntityManager.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Mon May  2 14:00:42 2016 Barthelemy Gouby
// Last update Wed May 25 12:08:08 2016 Erwan Dupard
//

#ifndef _ENTITY_MANAGER_HH_
# define _ENTITY_MANAGER_HH_

# include <initializer_list>
# include <vector>
# include "Entity.hh"

class				EntityManager
{
public:
  EntityManager();
  ~EntityManager();
  void				addEntity(Entity *entity);
  void				destroyEntity(const unsigned int &id);
  Entity			*getEntity(const unsigned int id);
  const std::vector<Entity*>	&getEntities();
  std::vector<Entity*>		*getEntitiesWithComponents(std::initializer_list<std::string> typeList);
private:
  std::vector<Entity*>		_entities;
};

#endif /* !_ENTITY_MANAGER_HH_ */
