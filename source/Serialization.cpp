//
// Serialization.cpp for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Tue May 24 02:23:21 2016 Thomas Bogard
// Last update Wed May 25 14:48:13 2016 Erwan Dupard
//

# include <fstream>
# include <iostream>
# include <cstring>
# include <algorithm>
# include <dirent.h>
# include "Serialization.hh"
# include "./components/ModelComponent.hh"
# include "./components/PositionComponent.hh"

Serialization::Serialization()
{}

Serialization::~Serialization()
{
  if (this->_fs.is_open())
    this->_fs.close();
}

void						Serialization::setFileName(const std::string &fileName)
{
  this->_fileName = fileName;
  if (this->_fs.is_open())
    this->_fs.close();
  this->_fs.open(fileName, std::fstream::in | std::fstream::out);
  if (!this->_fs.is_open())
    std::cout << "[-] Failed to open file " << fileName << std::endl;
}

void						Serialization::setEntities(const std::vector<Entity *> &entities)
{
  this->_entities = entities;
}

void						Serialization::_serializeEntity(const Entity *entity, std::string &s)
{
  std::vector<Component *>::const_iterator	it;
  std::vector<Component *>			entityComponents;
  Component					*component;

  s += entity->getId();
  s += ':';
  //SerializeComponent
  entityComponents = entity->getComponents();
  it = entityComponents.begin();
  while (it != entityComponents.end())
    {
      component = *it;
      s += '{';
      s += component->getType();
      s += ':';
      this->_serializeComponent(component, s);
      s += "}, ";
      ++it;
    }
  s += '|';
}

void						Serialization::_serializeComponent(const Component *component, std::string &s)
{
  (void)s;
}

void						Serialization::serialize()
{
  std::vector<Entity *>::const_iterator		it;
  Entity					*entity;
  std::string					s;

  it = this->_entities.begin();
  while (it != this->_entities.end())
    {
      entity = *it;
      this->_serializeEntity(entity, s);
      ++it;
    }
  std::cout << "Serialized : " << s << std::endl;
}

void						Serialization::unserialize()
{
  
}
