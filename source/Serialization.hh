//
// Serialization.hh for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Tue May 24 02:24:18 2016 Thomas Bogard
// Last update Tue May 24 02:45:19 2016 Thomas Bogard
//

#ifndef		__SERIALIZATION_HH__
# define	__SERIALIZATION_HH__

# include	"EntityManager.hh"
# include	"Resources.hh"
# include	<unistd.h>

class		Serialization
{
public:
  Serialization();
  Serialization(const std::string &file);
  ~Serialization();
  int		serialization();
  int		writeSerialization();
  int		readSerialization();
protected:
  std::string		_file;
};

#endif		// __SERIALIZATION_HH__
