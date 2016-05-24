//
// PlayerInputComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/components
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Tue May 17 19:31:35 2016 Barthelemy Gouby
// Last update Tue May 24 16:51:52 2016 Barthelemy Gouby
//

#include "Component.hh"

#ifndef _PLAYER_INPUT_COMPONENT_HH_
# define _PLAYER_INPUT_COMPONENT_HH_

# include "IEventReceiver.h"

class			PlayerInputComponent : public Component
{
public:
  PlayerInputComponent(const irr::EKEY_CODE &keyUp,
		       const irr::EKEY_CODE &keyDown,
		       const irr::EKEY_CODE &keyLeft,
		       const irr::EKEY_CODE &keyRight,
		       const irr::EKEY_CODE &keyBomb,
		       const unsigned int &maxBombs);
  const irr::EKEY_CODE		&getKeyUp() const;
  const irr::EKEY_CODE		&getKeyDown() const;
  const irr::EKEY_CODE		&getKeyLeft() const;
  const irr::EKEY_CODE		&getKeyRight() const;
  const irr::EKEY_CODE		&getKeyBomb() const;
  const unsigned int		&getMaxBombs() const;
  const unsigned int		&getActiveBombs() const;
  void				setMaxBombs(const unsigned int &newMaxBombs);
  void				setActiveBombs(const unsigned int &activeBombs);
  void				incrementActiveBombs();
  void			        decrementActiveBombs();
private:
  irr::EKEY_CODE	_keyUp;
  irr::EKEY_CODE	_keyDown;
  irr::EKEY_CODE	_keyLeft;
  irr::EKEY_CODE	_keyRight;
  irr::EKEY_CODE	_keyBomb;
  unsigned int		_maxBombs;
  unsigned int		_activeBombs;
};

#endif /* !_PLAYER_INPUT_COMPONENT_HH_ */
