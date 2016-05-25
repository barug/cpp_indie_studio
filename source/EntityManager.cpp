//
// EntityManager.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Mon May  2 14:13:17 2016 Barthelemy Gouby
// Last update Wed May 25 13:41:56 2016 Barthelemy Gouby
//

#include "EntityManager.hh"

EntityManager::EntityManager()
{}

EntityManager::~EntityManager()
{}

void			EntityManager::addEntity(Entity *entity)
{
  this->_entities.push_back(entity);
}

void			EntityManager::destroyEntity(const unsigned int &id)
{
  for (std::vector<Entity*>::iterator it = this->_entities.begin(); it != this->_entities.end(); it++)
    {
      if ((*it)->getId() == id)
	{
	  it = this->_entities.erase(it);
	  break;
	}
    }
}

Entity			*EntityManager::getEntity(const unsigned int id)
{
  for (std::vector<Entity*>::iterator it = this->_entities.begin(); it != this->_entities.end(); it++)
    {
      if ((*it)->getId() == id)
	return (*it);
    }
  return (NULL);
}

const std::vector<Entity*>	&EntityManager::getEntities()
{
  return (this->_entities);
}

std::vector<Entity*>	*EntityManager::getEntitiesWithComponents(std::vector<Component::ComponentType> typeList)
{
  std::vector<Entity*>	*validEntities = new std::vector<Entity*>;
  bool			isValid;

  for (Entity *entity: this->_entities)
    {
      isValid = true;
      for (Component::ComponentType type: typeList)
	{
	  if (!entity->getComponent(type))
	    isValid = false;
	}
      if (isValid)
	validEntities->push_back(entity);
    }
  return (validEntities);
}
