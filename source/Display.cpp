//
// Display.cpp for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Mon May  2 17:12:27 2016 Thomas Bogard
// Last update Tue May 24 17:13:42 2016 Thomas Bogard
//

# include "Display.hh"

Display::Display()
{
}

Display::~Display()
{
}

// irrlicht device
int		Display::driverChoice()
{
  this->_driverType = irr::driverChoiceConsole();
  if (this->_driverType == irr::video::EDT_COUNT)
    return (-1);
  return (0);
}

void		Display::showFpsDriver(int last_tick)
{
  const int	&fps = this->_driver->getFPS();

  if (last_tick != fps)
    {
      irr::core::stringw str = L"Bomberman - driver : [";
      str += this->_driver->getName();
      str += "] FPS:[";
      str += fps;
      str += "]";
      this->_device->setWindowCaption(str.c_str());
      last_tick = fps;
    }
}

int		Display::initDevice()
{
  irr::SIrrlichtCreationParameters params;

  params.DriverType = this->_driverType;
  params.WindowSize = irr::core::dimension2d<irr::u32>(1200, 800);
  this->_device = createDeviceEx(params);
  if (!this->_device)
    return (-1);
  return (0);
}

void		Display::initGround()
{
  for (int row = 0; row < MAP_SIZE; row++)
    for (int column = 0; column < MAP_SIZE; column++)
      {
	this->_smgr->addCubeSceneNode();
	this->_ground = this->_smgr->addCubeSceneNode();
	this->_ground->setPosition(irr::core::vector3df(TILE_SIZE * row + TILE_SIZE / 2,
							0,
							TILE_SIZE * column + TILE_SIZE / 2));
	this->_ground->setMaterialTexture(0, this->_driver->getTexture("./textures/blockstone.jpg"));
	this->_ground->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	this->_ground->setScale(irr::core::vector3df(50, 50, 50));
      }
}

void		Display::initSkybox()
{
  this->_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
  this->_skybox =
    this->_smgr->addSkyBoxSceneNode(this->_driver->getTexture("./textures/planet.jpg"), // up
				    this->_driver->getTexture("./textures/space.jpg"),  // down
				    this->_driver->getTexture("./textures/space.jpg"),  // left
				    this->_driver->getTexture("./textures/space.jpg"),  // right
				    this->_driver->getTexture("./textures/space.jpg"),  // ft
				    this->_driver->getTexture("./textures/space.jpg")); // bk
  if (!this->_skybox)
    puterr("Skybox cannot be loaded");
  this->_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);
}

void		Display::initCamera()
{
  this->_camera =
    this->_smgr->addCameraSceneNode(0,
  				    irr::core::vector3df(4050, 6080, 2560), // position
  				    irr::core::vector3df(4050, -1570, 3730), // target
  				    -1, true);
  this->_camera->setFarValue(42000.0f);
}

int		Display::init()
{
  if (driverChoice())
    puterr("Select an appropriate driver for your system");
  if (initDevice())
    puterr("Device cannot be created");
  this->_driver = this->_device->getVideoDriver();
  this->_smgr = this->_device->getSceneManager();
  this->_env = this->_device->getGUIEnvironment();
  this->_driver->setTextureCreationFlag(irr::video::ETCF_ALWAYS_32_BIT, true);
  this->_device->getCursorControl()->setVisible(false);
  this->_device->setResizable(true);
  this->initGround();
  this->initSkybox();
  this->initCamera();
  this->_device->setEventReceiver(&(this->_receiver));
}

int		Display::refreshScreen()
{
  const int&	last_tick = -1;

  if (this->_device->run() && this->_device)
    {
      this->_driver->beginScene(true, true, 0);
      this->_smgr->drawAll();
      this->_env->drawAll();
      this->_driver->endScene();
      // showPosCam();
      showFpsDriver(last_tick);
    }
}

int		Display::closeDisplay()
{
  this->_device->drop();
  return (0);
}

const bool	Display::windowIsActive() const
{
  return ((!this->_device || !this->_device->run()) ? false : true);
}

// models
int		Display::createModel(Entity *entity)
{
  unsigned int				id = entity->getId();
  ModelComponent			*model = (ModelComponent*)entity->getComponent("ModelComponent");
  PositionComponent			*pos = (PositionComponent*)entity->getComponent("PositionComponent");
  irr::scene::IAnimatedMeshSceneNode	*node = this->_smgr->addAnimatedMeshSceneNode(this->_smgr->getMesh(model->getModel().c_str()));

  if (!node)
    {
      std::cerr << "model : " << model->getModel() << " cannot be open." << std::endl;
      return (1);
    }
  node->setMaterialTexture(0, this->_driver->getTexture(model->getTexture().c_str()));
  node->setPosition(irr::core::vector3df(pos->getX(), 300, pos->getY()));
  node->setAnimationSpeed(40);
  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  node->setScale(irr::core::vector3df(model->getScale(), model->getScale(), model->getScale()));
  node->setRotation(irr::core::vector3df(0, pos->getRotation(), 0));
  // node->setDebugDataVisible(irr::scene::EDS_BBOX);
  this->_models.emplace(id, node);
  this->_animation.emplace(id, NONE);
  return (0);
}

void		Display::removeModel(Entity *entity)
{
  unsigned int	id = entity->getId();
  auto		model = this->_models.find(id);

  if (model != this->_models.end())
    {
      model->second->remove();
      this->_models.erase(id);
    }
}

int		Display::updateModelAnimation(const unsigned int &id, const unsigned int &rotation,
                                              const unsigned int &posX, const unsigned int &oldX,
                                              const unsigned int &posY, const unsigned int &oldY)
{
  auto		model = this->_models.find(id);
  auto		anim = this->_animation.find(id);

  if (model != this->_models.end())
    {
      if (anim != this->_animation.end())
        {
          if ((oldX != posX || oldY != posY) && (oldX && oldY && anim->second != RUN))
            {
	      model->second->setMesh(this->_smgr->getMesh(M_RUN));
              model->second->setMaterialTexture(0, this->_driver->getTexture(T_GREEN));
              model->second->setMaterialFlag(irr::video::EMF_LIGHTING, false);
              anim->second = RUN;
            }
          if (oldX == posX && oldY == posY && anim->second != STAND)
            {
	      model->second->setMesh(this->_smgr->getMesh(M_STAND));
              model->second->setMaterialTexture(0, this->_driver->getTexture(T_GREEN));
              model->second->setMaterialFlag(irr::video::EMF_LIGHTING, false);
              anim->second = STAND;
            }
        }
    }
}

int		Display::updateModelPosition(const unsigned int &id, const unsigned int &rotation,
					     const unsigned int &x, const unsigned int &y)
{
  auto		search = _models.find(id);
  if (search != _models.end())
    {
      irr::scene::IAnimatedMeshSceneNode  *node = search->second;
      node->setPosition(irr::core::vector3df(x, 300, y));
      node->setRotation(irr::core::vector3df(0, rotation, 0));
      node->updateAbsolutePosition();
    }
}

const bool	Display::tileIsOccupiedBomb(const unsigned int &x,
					const unsigned int &y,
					Entity* entity)
{
  irr::scene::IAnimatedMeshSceneNode *node = this->_models.find(entity->getId())->second;
  return (node->getTransformedBoundingBox().isPointInside(irr::core::vector3df(x, 400, y)));
}


const bool	Display::tileIsOccupied(const unsigned int &x,
					const unsigned int &y,
					Entity* entity)
{
  irr::scene::IAnimatedMeshSceneNode *node = this->_models.find(entity->getId())->second;
  return (node->getTransformedBoundingBox().isPointInside(irr::core::vector3df(x, 400, y)));
}

const bool	Display::collision(const unsigned int &firstId, const unsigned int &secondId)
{
  irr::scene::IAnimatedMeshSceneNode *firstNode = this->_models.find(firstId)->second;
  irr::scene::IAnimatedMeshSceneNode *secondNode = this->_models.find(secondId)->second;

  return (firstNode->getTransformedBoundingBox().
	  intersectsWithBox(secondNode->getTransformedBoundingBox()));
}

const bool	Display::collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
				   irr::scene::IAnimatedMeshSceneNode *mesh2)
{
  return (mesh1->getTransformedBoundingBox().
	  intersectsWithBox(mesh2->getTransformedBoundingBox()));
}

const bool	Display::collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
				   irr::scene::IAnimatedMeshSceneNode *mesh2, const int& size)
{
  if (mesh1->getAbsolutePosition().getDistanceFrom(mesh2->getAbsolutePosition()) < size)
    return (true);
  return (false);
}

// event listener
void		Display::createEventListener(unsigned int id, std::vector<irr::EKEY_CODE> keys)
{
  this->_listeners.emplace(id, new EventListener(keys, &(this->_receiver)));
}

std::vector<irr::EKEY_CODE>	*Display::getKeysDownForId(unsigned int id)
{
  return (this->_listeners.find(id)->second->getKeysDown());
}

// private for debug
void			Display::showPosCam()
{
  const irr::core::vector3df& camera_position = this->_camera->getPosition();
  const irr::core::vector3df& camera_target = this->_camera->getTarget();

  const long& X1 = camera_position.X;
  const long& Y1 = camera_position.Y;
  const long& Z1 = camera_position.Z;
  std::cout << "position == " << X1 << " && " << Y1 << " && " << Z1 << std::endl;

  const long& X2 = camera_target.X;
  const long& Y2 = camera_target.Y;
  const long& Z2 = camera_target.Z;
  std::cout << "target == " << X2 << " && " << Y2 << " && " << Z2 << std::endl;
}
