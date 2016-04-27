#include <irrlicht.h>
#include <iostream>
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#ifdef _IRR_WINDOWS_
# pragma comment(lib, "Irrlicht.lib")
# pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

scene::ISceneNode * node = NULL;

// Event Irrlicht system
class MyEventReceiver : public IEventReceiver
{
public:
  virtual bool OnEvent(const SEvent& event)
  {
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
      KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    if (node != 0 && event.EventType == irr::EET_KEY_INPUT_EVENT &&
    	!event.KeyInput.PressedDown)
      return true;
    return false;
  }
  virtual bool IsKeyDown(EKEY_CODE keyCode) const
  {
    return KeyIsDown[keyCode];
  }
  MyEventReceiver()
  {
    memset(KeyIsDown, false, sizeof(KeyIsDown));
  }
private:
  bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

int			main()
{
  MyEventReceiver	receiver;
  IrrlichtDevice	*device =
    createDevice(video::EDT_SOFTWARE, dimension2d<u32>(640, 480),
		 16, false, false, false, &receiver);
  if (!device)
    return 1;
  IVideoDriver* driver = device->getVideoDriver();
  ISceneManager* smgr = device->getSceneManager();
  IAnimatedMesh* mesh = smgr->getMesh("media/Archattack.md2");

  if (!mesh)
    {
      device->drop();
      return (1);
    }

  node = smgr->addAnimatedMeshSceneNode(mesh);
  if (node)
    {
      node->setMaterialFlag(EMF_LIGHTING, false);
      // node->setMD2Animation(scene::EMAT_JUMP);
      node->setMaterialTexture( 0, driver->getTexture("media/archattackpain1.png") );
    }

  // mode sans cam
  smgr->addCameraSceneNode(0, vector3df(300, 30, -40), vector3df(0, 5, 0));

  // mode cam
  // scene::ICameraSceneNode * cam = smgr->addCameraSceneNodeFPS();
  // cam->setPosition(core::vector3df(-100, 50, 100));
  // cam->setTarget(core::vector3df(0, 0, 0));
  // device->getCursorControl()->setVisible(false);

  int lastFPS = -1;
  core::vector3df v;
  while (device->run())
    {
      if (device->isWindowActive())
	{
	  if (receiver.IsKeyDown(irr::KEY_KEY_Z))
	    {
	      v = node->getPosition();
	      v.Y += 2;
	      node->setPosition(v);
	    }
	  else if (receiver.IsKeyDown(irr::KEY_KEY_S))
	    {
	      v = node->getPosition();
	      v.Y -= 2;
	      node->setPosition(v);
	    }
	  else if (receiver.IsKeyDown(irr::KEY_KEY_Q))
	    {
	      v = node->getPosition();
	      v.Z += 2;
	      node->setPosition(v);
	    }
	  else if (receiver.IsKeyDown(irr::KEY_KEY_D))
	    {
	      v = node->getPosition();
	      v.Z -= 2;
	      node->setPosition(v);
	    }
	  else if (receiver.IsKeyDown(irr::KEY_ESCAPE))
	    {
	      std::cout << "Echap key end of program" << std::endl;
	      device->drop();
	      exit(2);
	    }
	  driver->beginScene(true, true, SColor(255, 0, 0, 0));
	  smgr->drawAll();
	  driver->endScene();
	  if (lastFPS != driver->getFPS())
	    {
	      wchar_t tmp[1024];
	      swprintf(tmp, 1024, L"Bomberman Indie Studio (fps: %d)", driver->getFPS());
	      device->setWindowCaption(tmp);
	      lastFPS = driver->getFPS();
	    }
	}
    }
  device->drop();
  return 0;
}
