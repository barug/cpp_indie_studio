#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Irrlicht.lib")
#endif

# include <irrlicht.h>
# include <driverChoice.h>

class EventReceiver : public irr::IEventReceiver
{
public:
  virtual bool OnEvent(const irr::SEvent& event)
  {
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
      KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    return false;
  }
  virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const
  {
    return KeyIsDown[keyCode];
  }
  EventReceiver()
  {
    for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
      KeyIsDown[i] = false;
  }
private:
  bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};


int		main()
{
  // erwan ne retire pas les commentaires merci :)

  // if you want to let choice for the driver (set 1st parameter of createDevice at driverType)

  // irr::video::E_DRIVER_TYPE driverType = irr::driverChoiceConsole();
  // if (driverType == irr::video::EDT_COUNT)
  //   return 1;

  EventReceiver receiver;
  irr::IrrlichtDevice* device = createDevice(irr::video::EDT_SOFTWARE,// driverType
					     irr::core::dimension2d<irr::u32>(640, 480),
					     16, false, false, false, &receiver);
  if (!device)
    return 1;
  irr::video::IVideoDriver *driver = device->getVideoDriver();
  irr::scene::ISceneManager *smgr = device->getSceneManager();
  irr::scene::IAnimatedMesh *mesh = smgr->getMesh("media/Archattack.md2");
  if (!mesh)
    {
      device->drop();
      return (1);
    }
  irr::scene::ISceneNode *node = smgr->addAnimatedMeshSceneNode(mesh);
  if (node)
    {
      node->setPosition(irr::core::vector3df(0,0,30));
      node->setMaterialTexture(0, driver->getTexture("./media/archattackpain1.png"));
      node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }
  smgr->addCameraSceneNodeFPS();
  device->getCursorControl()->setVisible(false);
  int lastFPS = -1;
  irr::u32 then = device->getTimer()->getTime();
  const irr::f32 MOVEMENT_SPEED = 50.f;
  // scanf()
  while (device->run())
    {
      const irr::u32 now = device->getTimer()->getTime();
      const irr::f32 frameDeltaTime = (irr::f32)(now - then) / 1000.f;
      then = now;
      // gestion des events
      irr::core::vector3df nodePosition = node->getPosition();
      if (receiver.IsKeyDown(irr::KEY_KEY_W))
	nodePosition.Y += MOVEMENT_SPEED * frameDeltaTime;
      else if (receiver.IsKeyDown(irr::KEY_KEY_S))
	nodePosition.Y -= MOVEMENT_SPEED * frameDeltaTime;
      if (receiver.IsKeyDown(irr::KEY_KEY_A))
	nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
      else if (receiver.IsKeyDown(irr::KEY_KEY_D))
	nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
      if (receiver.IsKeyDown(irr::KEY_ESCAPE))
	exit(0);
      node->setPosition(nodePosition);

      driver->beginScene(true, true, irr::video::SColor(255,113,113,133));
      smgr->drawAll();
      driver->endScene();
      int fps = driver->getFPS();
      if (lastFPS != fps)
	{
	  irr::core::stringw tmp(L"Bomberman - Irrlicht (");
	  tmp += fps;
	  tmp += "fps) (EchapKey for quit)";
	  device->setWindowCaption(tmp.c_str());
	  lastFPS = fps;
	}
    }
  device->drop();
  return 0;
}
