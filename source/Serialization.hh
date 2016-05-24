//
// Serialization.hh for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Tue May 24 02:24:18 2016 Thomas Bogard
// Last update Tue May 24 11:20:00 2016 Thomas Bogard
//

#ifndef		__SERIALIZATION_HH__
# define	__SERIALIZATION_HH__

# include	"EntityManager.hh"
# include	"Resources.hh"
# include	<vector>
# include	<unistd.h>

class		Serialization
{
public:
  Serialization();
  Serialization(const std::string &file);
  ~Serialization();
  void		setFile(const std::string &file);
  const std::string& getFile();
  int		writeSerialization(const std::vector<Entity*> entities);
  int		readSerialization();
protected:
  unsigned int		_id;
  std::string		_file;
  std::vector<Entity*>	_entities;
};

#endif		// __SERIALIZATION_HH__
