//
// Serialization.cpp for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Tue May 24 02:23:21 2016 Thomas Bogard
// Last update Tue May 24 15:16:12 2016 Barthelemy Gouby
//

# include <fstream>
# include <iostream>
# include <cstring>
# include <algorithm>
# include <dirent.h>
# include "Serialization.hh"
# include "./components/ModelComponent.hh"
# include "./components/PositionComponent.hh"

Serialization::Serialization() : _file("./saves/bomberman.save"), _id(0)
{
}

Serialization::Serialization(const std::string &file) : _file(file), _id(0)
{
}

Serialization::~Serialization()
{
}

void		Serialization::setFile(const std::string &file)
{
  this->_file = file;
}

const std::string& Serialization::getFile()
{
  return (this->_file);
}

int		Serialization::writeSerialization(const std::vector<Entity*> entities)
{
  std::vector <std::string> result;
  dirent	*entry;
  DIR		*directory;
  unsigned int	size = 14;

  if (!(directory = opendir("./saves")))
    return (RETURN_FAILURE);
  while (entry = readdir(directory))
    result.push_back(std::string(entry->d_name));
  closedir(directory);
  std::sort(result.begin(), result.end());
  for (const auto &e_result : result)
    {
      const std::string& current = e_result;
      if (!strncmp(current.c_str(), "bomberman.save", 14))
	if (isdigit(current[size]))
	  this->_id = atoi(current.c_str() + size);
	else if (isdigit(current[size + 1]))
	  size++;
    }
  ++(this->_id);
  this->_file += std::to_string(this->_id);
  std::ofstream	ofs(this->_file.c_str(), std::ios::binary);
  this->_entities = entities;
  for (const auto &e_entities : entities)
    ofs.write((char *)&e_entities, sizeof(e_entities));
  return (RETURN_SUCCESS);
}

int		Serialization::readSerialization()
{
  std::vector<Entity*> newEntities;
  std::ifstream	ifs(this->_file.c_str(), std::ios::binary);
  std::cout << "=====read serialization of " << this->_file.c_str() << "====" << std::endl;

  ifs.read((char *)&e_entities, sizeof(e_entities));
  for (ifs.gcount())
    {

      // std::vector<Component*> compo;
      // for (const auto &e_compo : compo)
      // 	{

      // 	}
      ModelComponent	*model = (ModelComponent*)e_entities->getComponent("ModelComponent");
      PositionComponent *pos = (PositionComponent*)e_entities->getComponent("PositionComponent");
      std::cout << "id = " << e_entities->getId();
      std::cout << " model = " << model->getModel();
      std::cout << " posx = " << pos->getX();
      std::cout << " posy = " << pos->getY() << std::endl;
    }
  return (RETURN_SUCCESS);
}
