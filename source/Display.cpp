//
// Display.cpp for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Mon May  2 17:12:27 2016 Thomas Bogard
// Last update Mon May  2 18:16:53 2016 Thomas Bogard
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
}

void	Display::createGround()
{
  m_smgr->addCubeSceneNode();
  m_ground = m_smgr->addCubeSceneNode();
  m_ground->setPosition(irr::core::vector3df(0, 400, 5200));
  m_ground->setMaterialTexture(0, m_driver->getTexture("./textures/moon.jpg"));
  m_ground->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  m_ground->setScale(irr::core::vector3df(500, 40, 500));
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
  m_camera->setPosition(irr::core::vector3df(0, 100, 1));
  m_camera->setTarget(irr::core::vector3df(0, 100, 1));
}

void	Display::init()
{
  // get driver choice
  if (driverChoice() == -1)
    puterr("Select an appropriate driver for your system");

  // create device
  if (createDevice() == -1)
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
			     irr::u32 x, irr::u32 y, irr::u32 z, irr::u32 rotation)
{
  m_model = m_smgr->addAnimatedMeshSceneNode(m_smgr->getMesh(model));
  m_model->setMaterialTexture(0, m_driver->getTexture(texture));
  m_model->setPosition(irr::core::vector3df(x, y, z));
  // m_model->setPosition(irr::core::vector3df(-2000,600,5200));
  m_model->setAnimationSpeed(40);
  m_model->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  m_model->setScale(irr::core::vector3df(200.f, 200.f, 200.f));
  m_model->setRotation(irr::core::vector3df(0, rotation, 0));
}

void	Display::launch()
{
  int			last_tick = -1;
  Display::Event	receiver;
  m_device->setEventReceiver(&receiver);
  while (m_device->run() && m_device)
    if (m_device->isWindowActive())
      {
	if (receiver.IsKeyDown(irr::KEY_ESCAPE))
	  puterr("Exit prg");
	m_driver->beginScene(true, true, 0);
	m_smgr->drawAll();
	m_driver->endScene();
      }
  m_device->drop();
}
