//
// Serialization.hh for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Tue May 24 02:24:18 2016 Thomas Bogard
// Last update Wed May 25 12:31:50 2016 Erwan Dupard
//

#ifndef		SERIALIZATION_HH_
# define        SERIALIZATION_HH_

# include	<vector>
# include	<unistd.h>
# include	"EntityManager.hh"
# include	"Resources.hh"

class				Serialization
{
public:
  Serialization(const std::string &fileName, const std::vector<Entity *> &entities);
  ~Serialization();
  void				serialize();
  void				unserialize();
private:
  void				_serializeEntity(const Entity *entity, const std::stringstream &ss);
  std::fstream			_fs;
  std::vector<Entity *>		_entities;  
};

#endif		// ! SERIALIZATION_HH_
