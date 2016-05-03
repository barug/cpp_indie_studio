//
// Display.cpp for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Mon May  2 17:12:27 2016 Thomas Bogard
// Last update Tue May  3 01:58:06 2016 Thomas Bogard
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
  int	fps = m_driver->getFPS();
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
  m_camera->setPosition(irr::core::vector3df(0, 4000, 2000));
  m_camera->setTarget(irr::core::vector3df(0, 700, 5000));
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

void	Display::createModel(const irr::io::path &model, const irr::io::path &texture,
			     const int &x, const int &y, const int &z, const irr::u32& rotation,
			     const irr::u32& scale)
{
  m_model = m_smgr->addAnimatedMeshSceneNode(m_smgr->getMesh(model));
  m_model->setMaterialTexture(0, m_driver->getTexture(texture));
  m_model->setPosition(irr::core::vector3df(x, y, z));
  m_model->setAnimationSpeed(40);
  m_model->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  m_model->setScale(irr::core::vector3df(scale, scale, scale));
  m_model->setRotation(irr::core::vector3df(0, rotation, 0));
}

void	Display::updateModel(irr::scene::IAnimatedMeshSceneNode *model,
			     irr::core::vector3df model_position)
{
  model->setPosition(model_position);
}

void			Display::launch()
{
  const int&		last_tick = -1;
  Display::Event	receiver;

  m_device->setEventReceiver(&receiver);
  createModel("./models/BOMBERRUN.b3d", "./textures/bomberman_red.png", -2000, 600, 5200, 270, 200);
  while (m_device->run() && m_device)
    if (m_device->isWindowActive())
      {
	if (receiver.IsKeyDown(irr::KEY_ESCAPE))
	  puterr("Exit program");

	m_model_position = m_model->getPosition();
	eventPlayer(receiver);
	updateModel(m_model, m_model_position);

	m_driver->beginScene(true, true, 0);
	m_smgr->drawAll();
	m_driver->endScene();

	showFpsDriver(last_tick);
      }
  m_device->drop();
}

void	Display::eventPlayer(Display::Event receiver)
{
  if (receiver.IsKeyDown(irr::KEY_KEY_W))
    {
      m_model->setRotation(irr::core::vector3df(0, 180, 0));
      m_model_position.Z += 17;
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_S))
    {
      m_model->setRotation(irr::core::vector3df(0, 0, 0));
      m_model_position.Z -= 17;
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_A))
    {
      m_model->setRotation(irr::core::vector3df(0, 90, 0));
      m_model_position.X -= 17;
    }
  else if (receiver.IsKeyDown(irr::KEY_KEY_D))
    {
      m_model->setRotation(irr::core::vector3df(0, 270, 0));
      m_model_position.X += 17;
    }
}
