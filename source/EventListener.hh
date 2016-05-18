//
// EventListener.hh for indiStudio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 18 15:27:32 2016 Barthelemy Gouby
// Last update Wed May 18 15:28:40 2016 Barthelemy Gouby
//

#ifndef _EVENT_LISTENER_HH_
# define _EVENT_LISTENER_HH_

# include <vector>
# include "EventReceiver.hh"

class				EventListener
{
public:
  EventListener(std::vector<irr::EKEY_CODE> keys, EventReceiver *receiver);
    std::vector<irr::EKEY_CODE>	*getKeysDown();
  
private:
  std::vector<irr::EKEY_CODE>	_keys;
  EventReceiver		*receiver;
};

#endif /* !_EVENT_LISTENER_HH_ */
