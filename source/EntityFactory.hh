//
// EntityFactory.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 16:07:57 2016 Barthelemy Gouby
// Last update Tue May 24 18:15:28 2016 Barthelemy Gouby
//

#ifndef _ENTITY_FACTORY_HH_
# define _ENTITY_FACTORY_HH_

# include "Entity.hh"
# include "irrlicht.h"
# include "Display.hh"
# include "components/Component.hh"
# include "components/PositionComponent.hh"
# include "components/ModelComponent.hh"
# include "components/SpeedComponent.hh"
# include "components/PlayerInputComponent.hh"
# include "components/SolidityComponent.hh"
# include "components/ExplosiveComponent.hh"
# include "components/ExplosionComponent.hh"
# include "components/DestructibleComponent.hh"
# include "components/PowerUpComponent.hh"

class				EntityFactory
{
public:
  EntityFactory();
  ~EntityFactory();

  Entity			*createSolidBlock(const unsigned int &x,
						  const unsigned int &y,
						  const unsigned int &rotation);
  Entity			*createDestructibleBlock(const unsigned int &x,
							 const unsigned int &y,
							 const unsigned int &rotation);
  Entity			*createNormalBomb(const unsigned int &x,
						  const unsigned int &y,
						  const unsigned int &rotation,
						  const unsigned int &ownerId,
						  const ExplosiveComponent::Owner &ownerType);
  Entity			*createExplosion(const unsigned int &x,
						 const unsigned int &y,
						 const unsigned int &rotation);
  Entity			*createPlayer(const unsigned int &x,
					      const unsigned int &y,
					      const unsigned int &rotation,
					      const irr::EKEY_CODE &keyUp,
					      const irr::EKEY_CODE &keyDown,
					      const irr::EKEY_CODE &keyRight,
					      const irr::EKEY_CODE &keyLeft,
					      const irr::EKEY_CODE &keyBomb,
					      const unsigned int &maxBombs,
					      Display *display);
  Entity			*createPowerUp(const unsigned int &x,
					       const unsigned int &y,
					       PowerUpComponent::Type type);
private:
  unsigned int			_nextFreeId;
};

#endif /* !_ENTITY_FACTORY_HH_ */
