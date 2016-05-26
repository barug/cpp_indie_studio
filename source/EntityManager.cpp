//
// EntityManager.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Mon May  2 14:13:17 2016 Barthelemy Gouby
// Last update Thu May 26 13:07:23 2016 Erwan Dupard
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

void							EntityManager::_serializeEntityComponents(std::string &out, Entity *entity) const
{
  std::vector<Component *>				components;
  std::vector<Component *>::const_iterator		it;
  Component						*component;

  components = entity->getComponents();
  it = components.begin();
  while (it != components.end())
    {
      component = *it;
      out += '{';
      out += this->_intToString(component->getType());
      this->_serializeEntityComponent(out, component);
      out += "},";
      ++it;
    }
}

void							EntityManager::_serializePositionComponent(std::string &out, PositionComponent *component) const
{
  out += ':';
  out += this->_intToString(component->getX()) + ",";
  out += this->_intToString(component->getY()) + ",";
  out += this->_intToString(component->getOldX()) + ",";
  out += this->_intToString(component->getOldY()) + ",";
  out += this->_intToString(component->getRotation());
}

void							EntityManager::_serializeSpeedComponent(std::string &out, SpeedComponent *component) const
{
  out += ':';
  out += this->_intToString(component->getSpeedX());
  out += this->_intToString(component->getSpeedY());
}

void							EntityManager::_serializeModelComponent(std::string &out, ModelComponent *component) const
{
  out += ':';
  out += component->getModel();
  out += component->getTexture();
  out += component->getScale();
}

void							EntityManager::_serializeEntityComponent(std::string &out, Component *component) const
{
  switch(component->getType())
    {
    case Component::POSITION_COMPONENT:
      this->_serializePositionComponent(out, (PositionComponent *)component);
      break;
    case Component::SPEED_COMPONENT:
      this->_serializeSpeedComponent(out, (SpeedComponent *)component);
      break;
    case Component::MODEL_COMPONENT:
      this->_serializeModelComponent(out, (ModelComponent *)component);
      break;
    case Component::HEALTH_COMPONENT:
      break;
    case Component::EXPLOSIVE_COMPONENT:
      break;
    case Component::EXPLOSION_COMPONENT:
      break;
    case Component::POWER_UP_COMPONENT:
      break;
    case Component::PLAYER_INPUT_COMPONENT:
      break;
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
	  out += this->_intToString(entity->getId());
	  out += ':';
	  this->_serializeEntityComponents(out, entity);
	  out += '|';
	  ++it;
	}
      std::cout << "serialized : " << out << std::endl;
    }
  else
    std::cout << "[-] Can't serialize to file " << fileName << std::endl;
}

void							EntityManager::unserialize(const std::string &fileName) const
{
  (void)fileName;
}

std::string						EntityManager::_intToString(const unsigned int value) const
{
  std::stringstream					str;

  str << value;
  return (str.str());
}
