//
// Display.cpp for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Mon May  2 17:12:27 2016 Thomas Bogard
// Last update Mon May  9 14:03:47 2016 Thomas Bogard
//

# include "Display.hh"

Display::Display()
  : m_device(NULL), m_driver(NULL), m_camera(NULL),
    m_smgr(NULL), m_ground(NULL), m_model(NULL),
    m_rotation(0), m_prev_x(0), m_prev_z(0),
    m_action(STAND), mv_action(STAND), m_collision(false), m_iswarning(false)
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
  const int	&fps = m_driver->getFPS();

  if (last_tick != fps)
    {
      irr::core::stringw str = L"Bomberman - driver : [";
      str += m_driver->getName();
      str += "] FPS:[";
      str += fps;
      str += "]";
      m_device->setWindowCaption(str.c_str());
      last_tick = fps;
    }
}

int	Display::createDevice()
{
  irr::SIrrlichtCreationParameters params;

  params.DriverType = driverType;
  params.WindowSize = irr::core::dimension2d<irr::u32>(1200, 800);
  m_device = createDeviceEx(params);
  if (!m_device)
    return (-1);
  return (0);
}

void	Display::createGround()
{
  for (int row = 0; row < 15; row++)
    for (int column = 0; column < 15; column++)
      {
	m_smgr->addCubeSceneNode();
	m_ground = m_smgr->addCubeSceneNode();
	m_ground->setPosition(irr::core::vector3df(500 * row, 0, 5200 + (500 * column)));
	m_ground->setMaterialTexture(0, m_driver->getTexture("./textures/box.png"));
	m_ground->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	m_ground->setScale(irr::core::vector3df(50, 50, 50));
      }
}

void	Display::createSkybox()
{
  m_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
  m_skybox =
    m_smgr->addSkyBoxSceneNode(m_driver->getTexture("./textures/planet.jpg"), // up
			       m_driver->getTexture("./textures/space.jpg"),  // down
			       m_driver->getTexture("./textures/space.jpg"),  // left
			       m_driver->getTexture("./textures/space.jpg"),  // right
			       m_driver->getTexture("./textures/space.jpg"),  // ft
			       m_driver->getTexture("./textures/space.jpg")); // bk
  if (!m_skybox)
    puterr("Skybox cannot be loaded");
  m_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);
}

void	Display::createCamera()
{
  m_camera = m_smgr->addCameraSceneNodeFPS(0, 100, 1);
  m_camera->setFarValue(42000.0f);
  m_camera->setPosition(irr::core::vector3df(3600, 4800, 6100));
  m_camera->setTarget(irr::core::vector3df(3600, -3300, 9100));
}

void	Display::init()
{
  if (driverChoice())
    puterr("Select an appropriate driver for your system");
  if (createDevice())
    puterr("Device cannot be created");
  m_driver = m_device->getVideoDriver();
  m_smgr = m_device->getSceneManager();
  m_env = m_device->getGUIEnvironment();
  m_driver->setTextureCreationFlag(irr::video::ETCF_ALWAYS_32_BIT, true);
  m_device->getCursorControl()->setVisible(false);
  createGround();
  createSkybox();
  createCamera();
  m_skin = m_env->getSkin();
  m_font = m_env->getFont("./font/game_over.ttf");
  if (m_font)
    m_skin->setFont(m_font);
  m_skin->setFont(m_env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
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

	// m_camera->setPosition(irr::core::vector3df(3600, 4800, 6100));
	// m_camera->setTarget(irr::core::vector3df(3600, -3300, 9100));

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

void	Display::eventPlayer(Display::Event receiver)
{
  if (receiver.IsKeyDown(irr::KEY_ESCAPE))
    puterr("Exit program");
  else if (receiver.IsKeyDown(irr::KEY_KEY_W))
    {
      m_rotation = 180;
      m_model->setRotation(irr::core::vector3df(0, m_rotation, 0));
      if (!(m_model_position.Z > lim_max_z))
	m_model_position.Z += speed;
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_S))
    {
      m_rotation = 0;
      m_model->setRotation(irr::core::vector3df(0, m_rotation, 0));
      if (!(m_model_position.Z < lim_min_z))
	m_model_position.Z -= speed;
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_D))
    {
      m_rotation = 270;
      m_model->setRotation(irr::core::vector3df(0, m_rotation, 0));
      if (!(m_model_position.X > lim_max_x))
	m_model_position.X += speed;
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_A))
    {
      m_rotation = 90;
      m_model->setRotation(irr::core::vector3df(0, m_rotation, 0));
      if (!(m_model_position.X < lim_min_x))
	m_model_position.X -= speed;
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
