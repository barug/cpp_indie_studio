//
// Display.cpp for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Mon May  2 17:12:27 2016 Thomas Bogard
// Last update Mon May  9 15:20:14 2016 Erwan Dupard
//

# include "Display.hh"

Display::Display()
  : _device(NULL), _driver(NULL), _camera(NULL),
    _smgr(NULL), _ground(NULL), _model(NULL),
    _rotation(0), _prev_x(0), _prev_z(0),
    _action(STAND), mv_action(STAND), _collision(false), _iswarning(false)
{
}

Display::~Display()
{
}

int	Display::driverChoice()
{
  driverType = irr::driverChoiceConsole();
  if (driverType == irr::video::EDT_COUNT)
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

  params.DriverType = driverType;
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
	this->_ground->setScale(irr::core::vector3df(46, 46, 46));
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

  model = m_smgr->addAnimatedMeshSceneNode(m_smgr->getMesh(model3d));
  if (!model)
    puterr("Model cannot be loaded : ", model3d.c_str());
  model->setMaterialTexture(0, m_driver->getTexture(texture));
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

  if ((current_x != m_prev_x || current_z != m_prev_z) &&
      (m_prev_x && m_prev_z && m_action != RUN))
    {
      model->remove();
      model = createModel(M_RUN, T_RED, x, y, z, m_rotation, 200);
      m_action = RUN;
    }
  if (current_x == m_prev_x && current_z == m_prev_z && m_action != STAND)
    {
      model->remove();
      model = createModel(M_STAND, T_RED, x, y, z, m_rotation, 200);
      m_action = STAND;
    }
  m_prev_x = current_x;
  m_prev_z = current_z;
  model->setPosition(model_position);
  return model;
}

void			Display::run()
{
  const int&		last_tick = -1;
  Display::Event	receiver;

  m_device->setEventReceiver(&receiver);

  for (int i = 0; i < 5; i++)
    {
      const int& x = rand()%(lim_max_x - lim_min_x + 1) + lim_min_x;
      const int& z = rand()%(lim_max_z - lim_min_z + 1) + lim_min_z;
      mv_models.push_back(createModel(M_STAND, T_BLUE, x, 250, z, 270, 200));
    }

  const int& x = rand()%(lim_max_x - lim_min_x + 1) + lim_min_x;
  const int& z = rand()%(lim_max_z - lim_min_z + 1) + lim_min_z;

  m_model = createModel(M_STAND, T_RED, x, 250, z, 270, 200);
  while (m_device->run() && m_device)
    if (m_device->isWindowActive())
      {
	long X = m_model->getAbsolutePosition().X;
	long Z = m_model->getAbsolutePosition().Z;

	m_camera->setPosition(irr::core::vector3df(3600, 4800, 6100));
	m_camera->setTarget(irr::core::vector3df(3600, -3300, 9100));

	m_model_position = m_model->getPosition();
	for (int i = 0; i < mv_models.size(); i++)
	  {
	    irr::core::vector3df mv_models_position = mv_models[i]->getPosition();
	    if (collision(mv_models[i], m_model))
	      {
		std::cout << "COLLISION !!!" << std::endl;
	      }
	    mv_models[i]->setPosition(mv_models_position);
	    // mv_models[i] = updateModel(mv_models[i], mv_models_position, x, 250, z);
	  }
	eventPlayer(receiver);
	m_model = updateModel(m_model, m_model_position, x, 250, z);
	m_driver->beginScene(true, true, 0);
	m_smgr->drawAll();
	m_env->drawAll();
	m_driver->endScene();
	showFpsDriver(last_tick);
      }
  m_device->drop();
}

void	Display::createImage(irr::gui::IGUIImage *img)
{
  img = m_env->addImage(irr::core::rect<irr::s32>(100,100,200,225));
  img->setImage(m_driver->getTexture("./textures/warning.png"));
  img->setScaleImage(true);
  m_driver->removeTexture(m_driver->getTexture("./textures/warning.png"));
  m_iswarning = true;
}

void	Display::eventPlayer(const Display::Event &receiver)
{
  if (receiver.IsKeyDown(irr::KEY_ESCAPE))
    puterr("Exit program");
  // else if (receiver.IsKeyDown(irr::KEY_SPACE) && m_collision)
  //   m_img->drop();
  else if (receiver.IsKeyDown(irr::KEY_KEY_W) || receiver.IsKeyDown(irr::KEY_KEY_Z))
    {
      m_rotation = 180;
      m_model->setRotation(irr::core::vector3df(0, m_rotation, 0));
      if (!(m_model_position.Z > lim_max_z))
	m_model_position.Z += speed;
      else
	if (!m_iswarning)
	  createImage(m_img);
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_S))
    {
      m_rotation = 0;
      m_model->setRotation(irr::core::vector3df(0, m_rotation, 0));
      if (!(m_model_position.Z < lim_min_z))
	m_model_position.Z -= speed;
      else
	if (!m_iswarning)
	  createImage(m_img);
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_D))
    {
      m_rotation = 270;
      m_model->setRotation(irr::core::vector3df(0, m_rotation, 0));
      if (!(m_model_position.X > lim_max_x))
	m_model_position.X += speed;
      else
	if (!m_iswarning)
	  createImage(m_img);
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_A) || receiver.IsKeyDown(irr::KEY_KEY_Q))
    {
      m_rotation = 90;
      m_model->setRotation(irr::core::vector3df(0, m_rotation, 0));
      if (!(m_model_position.X < lim_min_x))
	m_model_position.X -= speed;
      else
	if (!m_iswarning)
	  createImage(m_img);
    }
}

bool	Display::collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
			   irr::scene::IAnimatedMeshSceneNode *mesh2)
{
  return (mesh1->getTransformedBoundingBox().
	  intersectsWithBox(mesh2->getTransformedBoundingBox()));
}

void			Display::showPosModel()
{
  long X1 = m_model_position.X;
  long Y1 = m_model_position.Y;
  long Z1 = m_model_position.Z;
  std::cout << "position == X=" << X1 << " && Y=" << Y1 << " && Z=" << Z1 << std::endl;
}

void			Display::showPosCam()
{
  irr::core::vector3df m_camera_position = m_camera->getPosition();
  irr::core::vector3df m_camera_target = m_camera->getTarget();

  long X1 = m_camera_position.X;
  long Y1 = m_camera_position.Y;
  long Z1 = m_camera_position.Z;
  std::cout << "position == " << X1 << " && " << Y1 << " && " << Z1 << std::endl;

  long X2 = m_camera_target.X;
  long Y2 = m_camera_target.Y;
  long Z2 = m_camera_target.Z;
  std::cout << "target == " << X2 << " && " << Y2 << " && " << Z2 << std::endl;
}
