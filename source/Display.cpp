//
// Display.cpp for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Mon May  2 17:12:27 2016 Thomas Bogard
// Last update Fri May  6 03:47:47 2016 Thomas Bogard
//

# include "Display.hh"

Display::Display()
  : m_device(NULL), m_driver(NULL), m_camera(NULL),
    m_smgr(NULL), m_ground(NULL), m_model(NULL), m_action(STAND)
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
  m_smgr->addCubeSceneNode();
  m_ground = m_smgr->addCubeSceneNode();
  m_ground->setPosition(irr::core::vector3df(0, 400, 5200));
  m_ground->setMaterialTexture(0, m_driver->getTexture("./textures/moon.jpg"));
  m_ground->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  m_ground->setScale(irr::core::vector3df(500, 15, 500));
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
  m_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);
}

void	Display::createCamera()
{
  m_camera = m_smgr->addCameraSceneNodeFPS(0, 100 ,1);
  m_camera->setFarValue(42000.0f);
  m_camera->setPosition(irr::core::vector3df(53, 3800, 3090));
  m_camera->setTarget(irr::core::vector3df(53, -700, 5020));
}

void	Display::init()
{
  // get driver choice
  if (driverChoice())
    puterr("Select an appropriate driver for your system");

  // create device
  if (createDevice())
    puterr("Device cannot be created");

  // create scene
  m_driver = m_device->getVideoDriver();
  m_smgr = m_device->getSceneManager();
  m_driver->setTextureCreationFlag(irr::video::ETCF_ALWAYS_32_BIT, true);

  // disable mouse cursor
  m_device->getCursorControl()->setVisible(false);

  // create some Scene Node
  createGround();
  createSkybox();
  createCamera();
}

# define min_x -2300
# define max_x 2300
# define min_z 2780
# define max_z 7400

irr::scene::IAnimatedMeshSceneNode*	Display::createModel(const irr::io::path &model3d,
							     const irr::io::path &texture,
							     const int &x, const int &y, const int &z,
							     const irr::u32& rotation,
							     const irr::u32& scale)
{
  irr::scene::IAnimatedMeshSceneNode *model;

  model = m_smgr->addAnimatedMeshSceneNode(m_smgr->getMesh(model3d));
  model->setMaterialTexture(0, m_driver->getTexture(texture));
  model->setPosition(irr::core::vector3df(x, y, z));
  model->setAnimationSpeed(40);
  model->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  model->setScale(irr::core::vector3df(scale, scale, scale));
  model->setRotation(irr::core::vector3df(0, rotation, 0));
  return model;
}

void	Display::updateModel(irr::scene::IAnimatedMeshSceneNode *model,
			     const irr::core::vector3df &model_position)
{
  model->setPosition(model_position);
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


void			Display::launch()
{
  const int&		last_tick = -1;
  Display::Event	receiver;

  m_device->setEventReceiver(&receiver);

  for (int i = 0; i < 5; i++)
    {
      const int& rx = rand()%(max_x-min_x + 1) + min_x;
      const int& rz = rand()%(max_z-min_z + 1) + min_z;
      mv_models.push_back(createModel(M_STAND, T_BLUE, rx, 600, rz, 270, 200));
    }

  const int& rx = rand()%(max_x-min_x + 1) + min_x;
  const int& rz = rand()%(max_z-min_z + 1) + min_z;

  m_model = createModel(M_STAND, T_RED, rx, 600, rz, 270, 200);
  int		prevPosX = 0;
  int		prevPosZ = 0;
  while (m_device->run() && m_device)
    if (m_device->isWindowActive())
      {
	m_model_position = m_model->getPosition();

	const int& posX = m_model->getAbsolutePosition().X;
        const int& posZ = m_model->getAbsolutePosition().Z;
        if ((posX != prevPosX || posZ != prevPosZ) && (prevPosX && prevPosZ && m_action != RUN))
	  {
	    m_model->remove();
	    m_model = createModel(M_RUN, T_RED, rx, 600, rz, 270, 200);
	    m_action = RUN;
	  }
        if (posX == prevPosX && posZ == prevPosZ && m_action != STAND)
	  {
	    m_model->remove();
	    m_model = createModel(M_STAND, T_RED, rx, 600, rz, 270, 200);
	    m_action = STAND;
	  }
	prevPosX = posX;
	prevPosZ = posZ;
	eventPlayer(receiver);
	updateModel(m_model, m_model_position);


	// test collision with others meshes
	for (int i = 0; i < mv_models.size(); i++)
	  {
	    irr::core::vector3df mv_models_position = mv_models[i]->getPosition();
	    if (collision(mv_models[i], m_model))
	      std::cout << "collision == " << mv_models[i] << " && " << m_model << std::endl;
	    updateModel(mv_models[i], mv_models_position);
	  }

	m_driver->beginScene(true, true, 0);
	m_smgr->drawAll();
	m_driver->endScene();

	showFpsDriver(last_tick);

      }
  m_device->drop();
}

void	Display::eventPlayer(Display::Event receiver)
{
  if (receiver.IsKeyDown(irr::KEY_ESCAPE))
    puterr("Exit program");
  else if (receiver.IsKeyDown(irr::KEY_KEY_W))
    {
      m_model->setRotation(irr::core::vector3df(0, 180, 0));
      if (!(m_model_position.Z > max_z))
	m_model_position.Z += 17;
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_S))
    {
      m_model->setRotation(irr::core::vector3df(0, 0, 0));
      if (!(m_model_position.Z < min_z))
	m_model_position.Z -= 17;
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_D))
    {
      m_model->setRotation(irr::core::vector3df(0, 270, 0));
      if (!(m_model_position.X > max_x))
	m_model_position.X += 17;
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_A))
    {
      m_model->setRotation(irr::core::vector3df(0, 90, 0));
      if (!(m_model_position.X < min_x))
	m_model_position.X -= 17;
    }
}

bool	Display::collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
			   irr::scene::IAnimatedMeshSceneNode *mesh2)
{
  return (mesh1->getTransformedBoundingBox().intersectsWithBox(mesh2->getTransformedBoundingBox()));
}
