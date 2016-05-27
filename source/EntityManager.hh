//
// EntityManager.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Mon May  2 14:00:42 2016 Barthelemy Gouby
// Last update Fri May 27 14:30:10 2016 Erwan Dupard
//

#ifndef _ENTITY_MANAGER_HH_
# define _ENTITY_MANAGER_HH_

# include <initializer_list>
# include <vector>
# include <fstream> 
# include <iostream>
# include <sstream>
# include <string>
# include <stdexcept>
# include "Entity.hh"
# include "components/Component.hh"
# include "components/PositionComponent.hh"
# include "components/SpeedComponent.hh"
# include "components/ModelComponent.hh"
# include "components/HealthComponent.hh"
# include "components/ExplosiveComponent.hh"
# include "components/ExplosionComponent.hh"
# include "components/PowerUpComponent.hh"
# include "components/PlayerInputComponent.hh"

class				EntityManager
{
public:
  EntityManager();
  ~EntityManager();
  void				addEntity(Entity *entity);
  void				destroyEntity(const unsigned int &id);
  Entity			*getEntity(const unsigned int id);
  const std::vector<Entity*>	&getEntities();
  std::vector<Entity*>		*getEntitiesWithComponents(std::vector<Component::ComponentType> typeList);
  void				serialize(const std::string &fileName) const;
  void				unserialize(const std::string &fileName) const;
private:
  std::string			_intToString(unsigned int value) const;
  unsigned int			_stringToInt(const std::string &str) const;
  void				_serializeEntityComponents(std::string &out, Entity *entity) const;
  void				_serializeEntityComponent(std::string &out, Component *entity) const;
  void				_serializePositionComponent(std::string &out, PositionComponent *component) const;
  void				_serializeSpeedComponent(std::string &out, SpeedComponent *component) const;
  void				_serializeModelComponent(std::string &out, ModelComponent *component) const;
  void				_serializeHealthComponent(std::string &out, HealthComponent *component) const;
  void				_serializeExplosiveComponent(std::string &out, ExplosiveComponent *component) const;
  void				_serializeExplosionComponent(std::string &out, ExplosionComponent *component) const;
  void				_serializePowerUpComponent(std::string &out, PowerUpComponent *component) const;
  void				_serializePlayerInputComponent(std::string &out, PlayerInputComponent *component) const;
  Entity			*_addUnserializedEntity(std::vector<Entity *> &entities, const unsigned int &entityId) const;
  void				_addUnserializedComponent(Entity &entity, const std::string &componentString) const;
  void				_unserializePositionComponent(Entity &entity, const std::string &componentString) const;
  void				_unserializeSpeedComponent(Entity &entity, const std::string &componentString) const;
  void				_unserializeModelComponent(Entity &entity, const std::string &componentString) const;
  void				_unserializeHealthComponent(Entity &entity, const std::string &componentString) const;
  std::vector<Entity*>		_entities;
};

#endif /* !_ENTITY_MANAGER_HH_ */
