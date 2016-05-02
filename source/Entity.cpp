//
// Entity.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 13:46:52 2016 Barthelemy Gouby
// Last update Mon May  2 13:52:42 2016 Barthelemy Gouby
//

#include "Entity.hh"

Entity(const int &id)
  : _id(id)
{}

~Entity()
{}

void				addComponent(Component *component)
{
  this->_components.push_back(component);
}

void				removeComponent(const std::string &type)
{
    for (std::vector<Component*>::iterator it = this->_components.begin(); it != this->_components.end(); it++)
    {
      if (*it->getType == type)
	{
	  this->_components.erase(it);
	  break;
	}
    }
}

Component			*getComponent(const std::string &type)
{
  for (std::vector<Component*>::iterator it = this->_components.begin(); it != this->_components.end(); it++)
    {
      if (*it->getType == type)
	return (*it);
    }
  return (NULL);
}
