//
// Serialization.cpp for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Tue May 24 02:23:21 2016 Thomas Bogard
// Last update Tue May 24 02:46:15 2016 Thomas Bogard
//

# include <fstream>
# include <iostream>
# include "Serialization.hh"

Serialization::Serialization() : _file("bomberman.save")
{
}

Serialization::Serialization(const std::string &file) : _file(file)
{
}

Serialization::~Serialization()
{
}

int		Serialization::serialization()
{
  if (access(this->_file.c_str(), F_OK) != -1)
    remove(this->_file.c_str());
  std::ofstream	ofs(this->_file.c_str(), std::ios::binary);
  return (RETURN_SUCCESS);
}

int		Serialization::writeSerialization()
{
  std::vector<Entity*>	entities;
  EntityManager		entityManager;

  entities = entityManager.getEntities();
  if (access(this->_file.c_str(), F_OK) == -1)
    return (RETURN_FAILURE);

  std::ofstream	ofs(this->_file.c_str(), std::ios::binary);

  for (auto m_entities : entities)
    ofs.write((char *)&entities, sizeof(entities));
  return (RETURN_SUCCESS);
}

int		Serialization::readSerialization()
{
  std::vector<Entity*>	entities;
  EntityManager		entityManager;

  entities = entityManager.getEntities();
  if (access(this->_file.c_str(), F_OK) == -1)
    return (RETURN_FAILURE);

  std::ifstream	ifs(this->_file.c_str(), std::ios::binary);

  for (auto m_entities : entities)
    ifs.read((char *)&entities, sizeof(entities));
  return (RETURN_SUCCESS);
}
