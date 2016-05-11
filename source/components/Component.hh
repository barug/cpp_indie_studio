//
// Component.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 12:58:19 2016 Barthelemy Gouby
// Last update Mon May  2 16:19:39 2016 Barthelemy Gouby
//

#ifndef _COMPONENT_HH_
# define _COMPONENT_HH_

# include <string>
# include <vector>

class				Component
{
public:
  Component(const std::string &type);
  ~Component();
  const std::string		&getType() const;
private:
  const std::string		_type;
};

#endif /* !_COMPONENT_HH_ */

