//
// Display.cpp for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Mon May  2 17:12:27 2016 Thomas Bogard
// Last update Wed May 18 15:44:16 2016 Barthelemy Gouby
//

# include "Display.hh"

Display::Display()
  : _device(NULL), _driver(NULL), _camera(NULL),
    _smgr(NULL), _ground(NULL), _model(NULL),
    _action(STAND), _dropped(false), _timer_drop(0)
{
}

Display::~Display()
{
}

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

int		Display::createDevice()
{
  irr::SIrrlichtCreationParameters params;

  params.DriverType = this->_driverType;
  params.WindowSize = irr::core::dimension2d<irr::u32>(1200, 800);
  this->_device = createDeviceEx(params);
  if (!this->_device)
    return (-1);
  return (0);
}

void		Display::createGround()
{
  for (int row = 0; row < 15; row++)
    for (int column = 0; column < 15; column++)
      {
	this->_smgr->addCubeSceneNode();
	this->_ground = this->_smgr->addCubeSceneNode();
	this->_ground->setPosition(irr::core::vector3df(500 * row, 0, 500 * column));
	if (row == 0)
	  this->_ground->setMaterialTexture(0, this->_driver->getTexture("./textures/bomberman_pink.png"));
	else if (column == 0)
	  this->_ground->setMaterialTexture(0, this->_driver->getTexture("./textures/bomberman_blue.png"));
	else
	  this->_ground->setMaterialTexture(0, this->_driver->getTexture("./textures/box.png"));
	this->_ground->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	this->_ground->setScale(irr::core::vector3df(50, 50, 50));
      }
}

void		Display::createSkybox()
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

void		Display::createCamera()
{
  this->_camera = this->_smgr->addCameraSceneNodeFPS(0, 100, 1);
  this->_camera->setFarValue(42000.0f);
  this->_camera->setPosition(irr::core::vector3df(5350, 5400, 4000));
  this->_camera->setTarget(irr::core::vector3df(3350, -2930, 4000));
}

int		Display::init()
{
  if (driverChoice())
    puterr("Select an appropriate driver for your system");
  if (createDevice())
    puterr("Device cannot be created");
  this->_driver = this->_device->getVideoDriver();
  this->_smgr = this->_device->getSceneManager();
  this->_env = this->_device->getGUIEnvironment();
  this->_driver->setTextureCreationFlag(irr::video::ETCF_ALWAYS_32_BIT, true);
  this->_device->getCursorControl()->setVisible(false);
  createGround();
  createSkybox();
  createCamera();
  this->_device->setEventReceiver(&(this->_receiver));
}

int		Display::createModel(unsigned int id,
				     ModelComponent *model,
				     AnimationComponent *animation,
				     PositionComponent *pos)
{
  irr::scene::IAnimatedMeshSceneNode *
    node = this->_smgr->addAnimatedMeshSceneNode(this->_smgr->getMesh(model->getModel().c_str()));

  if (!node)
    {
      return (-1);
    }
  node->setMaterialTexture(0, this->_driver->getTexture(model->getTexture().c_str()));
  node->setPosition(irr::core::vector3df(pos->getX(), pos->getY(), 0));
  node->setAnimationSpeed(40);
  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  node->setScale(irr::core::vector3df(200, 200, 200));
  node->setRotation(irr::core::vector3df(0, pos->getRotation(), 0));
  _mapmodel.emplace(id, node);
}

int		Display::updateModel(unsigned int id,
				     ModelComponent *model,
				     AnimationComponent *animation,
				     PositionComponent *pos)
{
  auto search = _mapmodel.find(id);
  if (search != _mapmodel.end())
    {
      irr::scene::IAnimatedMeshSceneNode * node = search->second;
      const int& current_x = node->getAbsolutePosition().X;
      const int& current_y = node->getAbsolutePosition().Y;
      if (!node)
	{
	  return (-1);
	}
      node->setPosition(irr::core::vector3df(pos->getX(), pos->getY(), 0));
      node->setAnimationSpeed(40);
      node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      node->setScale(irr::core::vector3df(200, 200, 200));
      node->setRotation(irr::core::vector3df(0, pos->getRotation(), 0));
    }
  else
    std::cout << "id not found" << std::endl;
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
      showFpsDriver(last_tick);
    }
}

int		Display::closeDisplay()
{
  if (!this->_device)
    return (-1);
  this->_device->drop();
  return (0);
}

const bool	Display::getIfBlocked(Entity *entity)
{
  const int &id = entity->getId();
  auto search = _mapmodel.find(id);
  if (search != _mapmodel.end())
    {
      irr::scene::IAnimatedMeshSceneNode * node = search->second;
    }
  return (false);
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

void			Display::showPosModel()
{
  const long& X1 = this->_model_position.X;
  const long& Y1 = this->_model_position.Y;
  const long& Z1 = this->_model_position.Z;
  std::cout << "position == X=" << X1 << " && Y=" << Y1 << " && Z=" << Z1 << std::endl;
}

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

void				Display::createEventListener(unsigned int id, std::vector<irr::EKEY_CODE> keys)
{
  this->_listeners.emplace(id, new EventListener(keys, &(this->_receiver)));
}

std::vector<irr::EKEY_CODE>	*Display::getKeysDownForId(unsigned int id)
{
  return (this->_listeners.find(id)->second->getKeysDown());
}
