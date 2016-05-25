//
// Serialization.hh for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Tue May 24 02:24:18 2016 Thomas Bogard
// Last update Wed May 25 14:48:41 2016 Erwan Dupard
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
  Serialization();
  ~Serialization();
  void				setFileName(const std::string &fileName);
  void				serialize();
  void				unserialize();
  void				setEntities(const std::vector<Entity *> &entities);
private:
  void				_serializeEntity(const Entity *entity, std::string &s);
  void				_serializeComponent(const Component *component, std::string &sx);
  std::fstream			_fs;
  std::vector<Entity *>		_entities;
  std::string			_fileName;
};

#endif		// ! SERIALIZATION_HH_
