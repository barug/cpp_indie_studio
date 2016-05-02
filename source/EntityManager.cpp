//
// EntityManager.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 14:13:17 2016 Barthelemy Gouby
// Last update Mon May  2 16:42:05 2016 Barthelemy Gouby
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
	this->_entities.erase(it);
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

std::vector<Entity*>	*EntityManager::getEntitiesWithComponents(std::initializer_list<std::string> typeList)
{
  std::vector<Entity*>	*validEntities = new std::vector<Entity*>;
  bool			isValid;

  for (std::vector<Entity*>::iterator entitiesIt = this->_entities.begin();
       entitiesIt != this->_entities.end();
       entitiesIt++)
    {
      isValid = true;
      for (std::initializer_list<std::string>::iterator typesIt = typeList.begin();
	   typesIt != typeList.end();
	   typesIt++)
	{
	  if (!(*entitiesIt)->getComponent(*typesIt))
	    isValid = false;
	}
      if (isValid)
	validEntities->push_back(*entitiesIt);
    }
  return (validEntities);
}
