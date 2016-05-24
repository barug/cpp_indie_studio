//
// PlayerInputComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/components
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 18 16:42:06 2016 Barthelemy Gouby
// Last update Tue May 24 16:51:03 2016 Barthelemy Gouby
//

#include "PlayerInputComponent.hh"

PlayerInputComponent::PlayerInputComponent(const irr::EKEY_CODE &keyUp,
					   const irr::EKEY_CODE &keyDown,
					   const irr::EKEY_CODE &keyLeft,
					   const irr::EKEY_CODE &keyRight,
					   const irr::EKEY_CODE &keyBomb,
					   const unsigned int &maxBombs)
  : Component("PlayerInputComponent"),
    _keyUp(keyUp),
    _keyDown(keyDown),
    _keyLeft(keyLeft),
    _keyRight(keyRight),
    _keyBomb(keyBomb),
    _maxBombs(maxBombs),
    _activeBombs(0)
{}

const irr::EKEY_CODE		&PlayerInputComponent::getKeyUp() const
{
  return (this->_keyUp);
}

const irr::EKEY_CODE		&PlayerInputComponent::getKeyDown() const
{
  return (this->_keyDown);
}

const irr::EKEY_CODE		&PlayerInputComponent::getKeyLeft() const
{
  return (this->_keyLeft);
}

const irr::EKEY_CODE		&PlayerInputComponent::getKeyRight() const
{
  return (this->_keyRight);
}

const irr::EKEY_CODE		&PlayerInputComponent::getKeyBomb() const
{
  return (this->_keyBomb);
}

const unsigned int		&PlayerInputComponent::getMaxBombs() const
{
  return (this->_maxBombs);
}

const unsigned int		&PlayerInputComponent::getActiveBombs() const
{
  return (this->_activeBombs);
}

void				PlayerInputComponent::setMaxBombs(const unsigned int &newMaxBombs)
{
  this->_maxBombs = newMaxBombs;
}

void				PlayerInputComponent::setActiveBombs(const unsigned int &activeBombs)
{
  this->_activeBombs = activeBombs;
}

void				PlayerInputComponent::incrementActiveBombs()
{
  this->_activeBombs++;
}

void				PlayerInputComponent::decrementActiveBombs()
{
  this->_activeBombs--;
}
