//
// EntityManager.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Mon May  2 14:13:17 2016 Barthelemy Gouby
// Last update Wed May 25 15:34:31 2016 Erwan Dupard
//

#include "EntityManager.hh"

EntityManager::EntityManager()
{}

EntityManager::~EntityManager()
{}

void							EntityManager::addEntity(Entity *entity)
{
  this->_entities.push_back(entity);
}

void							EntityManager::destroyEntity(const unsigned int &id)
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

Entity							*EntityManager::getEntity(const unsigned int id)
{
  for (std::vector<Entity*>::iterator it = this->_entities.begin(); it != this->_entities.end(); it++)
    {
      if ((*it)->getId() == id)
	return (*it);
    }
  return (NULL);
}

const std::vector<Entity*>				&EntityManager::getEntities()
{
  return (this->_entities);
}

std::vector<Entity*>					*EntityManager::getEntitiesWithComponents(std::vector<Component::ComponentType> typeList)
{
  std::vector<Entity*>					*validEntities = new std::vector<Entity*>;
  bool							isValid;

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

void							EntityManager::_serializeEntityComponents(std::string &out, const Entity *entity) const
{
  std::vector<Component *>				components;
  std::vector<Component *>::const_iterator		it;
  Component						*component;

  components = entity->getComponents();
  it = components.begin();
  while (it != components.end())
    {
      out += '{';
      component->getType();
      out += "}, ";
      ++it;
    }
}

void							EntityManager::serialize(const std::string &fileName) const
{
  std::fstream						fs;
  std::vector<Entity *>::const_iterator			it;			
  std::string						out;
  Entity						*entity;

  fs.open(fileName, std::fstream::in | std::fstream::out);
  if (fs.is_open())
    {
      it = this->_entities.begin();
      while (it != this->_entities.end())
	{
	  entity = *it;
	  out += entity->getId();
	  out += ':';
	  this->_serializeEntityComponents(out, entity);
	  out += '|';
	  ++it;
	}
    }
}

void							EntityManager::unserialize(const std::string &fileName) const
{
  (void)fileName;
}
