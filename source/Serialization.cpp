//
// Serialization.cpp for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Tue May 24 02:23:21 2016 Thomas Bogard
// Last update Wed May 25 12:28:25 2016 Erwan Dupard
//

# include <fstream>
# include <iostream>
# include <cstring>
# include <algorithm>
# include <dirent.h>
# include "Serialization.hh"
# include "./components/ModelComponent.hh"
# include "./components/PositionComponent.hh"

Serialization::Serialization(const std::string &fileName, const std::vector<Entity *> &entities)
{
  this->_fs.open(fileName, std::fstream::in | std::fstream::out);
  if (!this->_fs.is_open())
    std::cout << "[-] Can't Serialize .. " << fileName << " is busy " << std::endl;
  this->_entities = entities;
}

Serialization::~Serialization()
{
  if (this->_fs.is_open())
    this->_fs.close();
}

void				_serializeEntity(const Entity *entity, const std::stringstream &ss)
{
  ss << entity->getId();
  ss << ":";
  //SerializeComponent

  ss << "|";
}

void						Serialization::serialize()
{
  std::vector<Entity *>::const_iterator		it;
  Entity					*entity;
  std::stringstream				ss;

  it = this->_entities.begin();
  while (it != this->_entities.end())
    {
      entity = *it;
      this->_serializeEntity(entity, ss);
      ++it;
    }
}

void						Serialization::unserialize()
{
  
}
