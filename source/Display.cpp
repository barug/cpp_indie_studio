//
// Display.cpp for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Mon May  2 17:12:27 2016 Thomas Bogard
// Last update Wed May 11 14:02:57 2016 Thomas Bogard
//

# include "Display.hh"

Display::Display()
  : _device(NULL), _driver(NULL), _camera(NULL),
    _smgr(NULL), _ground(NULL), _model(NULL),
    _rotation(0), _prev_x(0), _prev_z(0),
    _action(STAND), _mv_action(STAND), _collision(false),
    _iswarning(false), _dropped(false), _timer_drop(0)
{
}

Display::~Display()
{
}

int	Display::driverChoice()
{
  this->_driverType = irr::driverChoiceConsole();
  if (this->_driverType == irr::video::EDT_COUNT)
    return (-1);
  return (0);
}

void	Display::showFpsDriver(int last_tick)
{
  const int	&fps = this->_driver->getFPS();

  if (last_tick != fps)
    {
      /* stringw extended charset L"A" --> 00 41  && L"AB" --> 00 41 00 42 (accents for exemples)*/
      irr::core::stringw str = L"Bomberman - driver : [";
      str += this->_driver->getName();
      str += "] FPS:[";
      str += fps;
      str += "]";
      this->_device->setWindowCaption(str.c_str());
      last_tick = fps;
    }
}

int	Display::createDevice()
{
  irr::SIrrlichtCreationParameters params;

  params.DriverType = this->_driverType;
  params.WindowSize = irr::core::dimension2d<irr::u32>(1200, 800);
  this->_device = createDeviceEx(params);
  if (!this->_device)
    return (-1);
  return (0);
}

void	Display::createGround()
{
  for (int row = 0; row < 15; row++)
    for (int column = 0; column < 15; column++)
      {
	this->_smgr->addCubeSceneNode();
	this->_ground = this->_smgr->addCubeSceneNode();
	this->_ground->setPosition(irr::core::vector3df(500 * row, 0, 5200 + (500 * column)));
	this->_ground->setMaterialTexture(0, this->_driver->getTexture("./textures/box.png"));
	this->_ground->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	this->_ground->setScale(irr::core::vector3df(50, 50, 50));
      }
}

void	Display::createSkybox()
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

void	Display::createCamera()
{
  this->_camera = this->_smgr->addCameraSceneNodeFPS(0, 100, 1);
  this->_camera->setFarValue(42000.0f);
  this->_camera->setPosition(irr::core::vector3df(3600, 4800, 6100));
  this->_camera->setTarget(irr::core::vector3df(3600, -3300, 9100));
}

void	Display::init()
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
  this->_skin = this->_env->getSkin();
  this->_font = this->_env->getFont("./font/game_over.ttf");
  if (this->_font)
    this->_skin->setFont(this->_font);
  this->_skin->setFont(this->_env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
}

irr::scene::IAnimatedMeshSceneNode*	Display::createModel(const irr::io::path &model3d,
							     const irr::io::path &texture,
							     const int &x, const int &y, const int &z,
							     const irr::u32& rotation,
							     const irr::u32& scale)
{
  irr::scene::IAnimatedMeshSceneNode	*model;

  model = this->_smgr->addAnimatedMeshSceneNode(this->_smgr->getMesh(model3d));
  if (!model)
    puterr("Model cannot be loaded : ", model3d.c_str());
  model->setMaterialTexture(0, this->_driver->getTexture(texture));
  model->setPosition(irr::core::vector3df(x, y, z));
  model->setAnimationSpeed(40);
  model->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  model->setScale(irr::core::vector3df(scale, scale, scale));
  model->setRotation(irr::core::vector3df(0, rotation, 0));
  return model;
}

irr::scene::IAnimatedMeshSceneNode*	Display::updateModel(irr::scene::IAnimatedMeshSceneNode *model,
							     const irr::core::vector3df &model_position,
							     const int& x, const int& y, const int& z)
{
  const int& current_x = model->getAbsolutePosition().X;
  const int& current_z = model->getAbsolutePosition().Z;

  if (this->_timer_drop < this->_device->getTimer()->getTime() && this->_dropped)
    {
      this->_action = DROP;
      this->_timer_drop = 0;
      this->_dropped = false;
    }
  if (!this->_dropped)
    {
      if ((current_x != this->_prev_x || current_z != this->_prev_z) &&
	  (this->_prev_x && this->_prev_z && this->_action != RUN))
	{
	  model->remove();
	  model = createModel(M_RUN, T_RED, x, y, z, this->_rotation, 300);
	  this->_action = RUN;
	}
      if (current_x == this->_prev_x && current_z == this->_prev_z && this->_action != STAND)
	{
	  model->remove();
	  model = createModel(M_STAND, T_RED, x, y, z, this->_rotation, 300);
	  this->_action = STAND;
	}
    }
  this->_prev_x = current_x;
  this->_prev_z = current_z;
  model->setPosition(model_position);
  return model;
}

void			Display::run()
{
  const int&		last_tick = -1;
  Display::Event	receiver;

  this->_device->setEventReceiver(&receiver);

  for (int i = 0; i < 20; i++)
    {
      const int& x = rand()%(lim_max_x - lim_min_x + 1) + lim_min_x;
      const int& z = rand()%(lim_max_z - lim_min_z + 1) + lim_min_z;
      this->_mv_models.push_back(createModel(M_STAND, T_BLUE, x, 250, z, 90, 300));
    }

  const int& x = rand()%(lim_max_x - lim_min_x + 1) + lim_min_x;
  const int& z = rand()%(lim_max_z - lim_min_z + 1) + lim_min_z;

  this->_model = createModel(M_STAND, T_RED, x, 250, z, 270, 300);

  while (this->_device->run() && this->_device)
    if (this->_device->isWindowActive())
      {
	const long& X = this->_model->getAbsolutePosition().X;
	const long& Z = this->_model->getAbsolutePosition().Z;

	this->_camera->setPosition(irr::core::vector3df(3555, 5580, 8169));
	this->_camera->setTarget(irr::core::vector3df(3551, -4905, 8926));

	this->_model_position = this->_model->getPosition();

	for (int i = 0; i < this->_mv_models.size(); i++)
	  {
	    const long& X = this->_mv_models[i]->getAbsolutePosition().X;
	    const long& Z = this->_mv_models[i]->getAbsolutePosition().Z;
	    std::cout << "model = " << i << " | X = "
		      << X << " && Z = " << Z
		      << " && collision = " << _collision << std::endl;
	    const irr::core::vector3df& mv_models_position = this->_mv_models[i]->getPosition();
	    this->_collision = (collision(this->_mv_models[i], this->_model, 170) ? true : false);
	    if (collision(this->_mv_models[i], this->_model))
	      std::cout << "collision between : model and " << this->_mv_models[i]
			<< " model nb " << i << std::endl;
	    this->_mv_models[i]->setPosition(mv_models_position);
	    // this->_mv_models[i] = updateModel(this->_mv_models[i], mv_models_position, x, 250, z);
	  }

	eventPlayer(receiver);
	this->_model = updateModel(this->_model, this->_model_position, x, 250, z);
	this->_driver->beginScene(true, true, 0);
	this->_smgr->drawAll();
	this->_env->drawAll();
	this->_driver->endScene();
	showFpsDriver(last_tick);
      }
  this->_device->drop();
}

void	Display::createImage(irr::gui::IGUIImage *img)
{
  img = this->_env->addImage(irr::core::rect<irr::s32>(100, 100, 200, 225));
  img->setImage(this->_driver->getTexture("./textures/warning.png"));
  img->setScaleImage(true);
  this->_driver->removeTexture(this->_driver->getTexture("./textures/warning.png"));
  this->_iswarning = true;
}

void	Display::eventPlayer(const Display::Event &receiver)
{
  if (receiver.IsKeyDown(irr::KEY_ESCAPE))
    puterr("Exit program");
  else if (receiver.IsKeyDown(irr::KEY_SPACE))
    {
      if (this->_action != DROP && !this->_dropped)
  	{
  	  this->_timer_drop = this->_device->getTimer()->getTime() + 900;
	  this->_model->remove();
	  this->_model = createModel(M_DROP, T_BLACK, 0, 0, 0, this->_rotation, 300);
    	  this->_dropped = true;
    	}
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_W) || receiver.IsKeyDown(irr::KEY_KEY_Z))
    {
      if ((!(this->_model_position.Z > lim_max_z) &&
	   !(this->_collision)) || this->_rotation != 180)
	this->_model_position.Z += speed;
      this->_rotation = 180;
      this->_model->setRotation(irr::core::vector3df(0, this->_rotation, 0));
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_S))
    {
      if ((!(this->_model_position.Z < lim_min_z) &&
	   !(this->_collision)) || this->_rotation != 0)
	this->_model_position.Z -= speed;
      this->_rotation = 0;
      this->_model->setRotation(irr::core::vector3df(0, this->_rotation, 0));
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_D))
    {
      if ((!(this->_model_position.X > lim_max_x) &&
	   !(this->_collision)) || this->_rotation != 270)
	this->_model_position.X += speed;
      this->_rotation = 270;
      this->_model->setRotation(irr::core::vector3df(0, this->_rotation, 0));
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_A) || receiver.IsKeyDown(irr::KEY_KEY_Q))
    {
      if ((!(this->_model_position.X < lim_min_x) &&
	   !(this->_collision)) || this->_rotation != 90)
	this->_model_position.X -= speed;
      this->_rotation = 90;
      this->_model->setRotation(irr::core::vector3df(0, this->_rotation, 0));
    }
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
    return true;
  return false;
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
