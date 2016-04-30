#include <irrlicht.h>
#include "driverChoice.h"

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

class MyEventReceiver : public irr::IEventReceiver
{
public:

  // ctor
  MyEventReceiver(irr::scene::ISceneNode *terrain,
		  irr::scene::ISceneNode *skybox,
		  irr::scene::ISceneNode *skydome)
    : Terrain(terrain), Skybox(skybox), Skydome(skydome),
      showBox(true), showDebug(false)
  {
    Skybox->setVisible(showBox);
    Skydome->setVisible(!showBox);
    for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
      KeyIsDown[i] = false;
  }

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

private:
  irr::scene::ISceneNode*	Terrain;
  irr::scene::ISceneNode*	Skybox;
  irr::scene::ISceneNode*	Skydome;
  bool				showBox;
  bool				showDebug;
  bool				KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};


int		main(int ac, char **av)
{
  irr::video::E_DRIVER_TYPE driverType = irr::driverChoiceConsole();
  if (driverType == irr::video::EDT_COUNT)
    return 1;

  // create device with full flexibility over creation parameters
  // you can add more parameters if desired, check irr::SIrrlichtCreationParameters
  irr::SIrrlichtCreationParameters params;
  params.DriverType = driverType;
  params.WindowSize = irr::core::dimension2d<irr::u32>(1200, 800);
  irr::IrrlichtDevice* device = createDeviceEx(params);
  if (!device)
    return 1;

  irr::video::IVideoDriver* driver = device->getVideoDriver();
  irr::scene::ISceneManager* smgr = device->getSceneManager();
  driver->setTextureCreationFlag(irr::video::ETCF_ALWAYS_32_BIT, true);

  // disable mouse cursor
  device->getCursorControl()->setVisible(false);

  // add terrain scene node
  smgr->addCubeSceneNode();
  irr::scene::ISceneNode* terrain = smgr->addCubeSceneNode();
  terrain->setPosition(irr::core::vector3df(0,400,5200));
  terrain->setMaterialTexture(0, driver->getTexture("./media/wall.bmp"));
  terrain->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  terrain->setScale(irr::core::vector3df(500, 40, 500));

  // irr::scene::ITriangleSelector* selector
  //   = smgr->createTriangleSelector(smgr->getMesh(""), terrain);
  // terrain->setTriangleSelector(selector);


  // // create collision response animator and attach it to the camera
  // irr::scene::ISceneNodeAnimator* anim =
  //   smgr->createCollisionResponseAnimator(selector, camera, irr::core::vector3df(60,100,60),
  // 					  irr::core::vector3df(0,0,0),
  // 					  irr::core::vector3df(0,50,0));
  // camera->addAnimator(anim);
  // anim->drop();

  // caracter
  // irr::scene::IAnimatedMesh *mesh =
  irr::scene::IAnimatedMeshSceneNode *node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./media/BOMBERRUN.b3d"));
  node->setMaterialTexture(0, driver->getTexture("./media/bomberman_green.png"));
  node->setPosition(irr::core::vector3df(-2000,600,5200));
  node->setAnimationSpeed(40);
  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  node->setScale(irr::core::vector3df(400.f,400.f,400.f));
  node->setRotation(irr::core::vector3df(0,270,0));
  // irr::scene::ISceneNodeAnimator* collision_character =
  //   smgr->createCollisionResponseAnimator(selector, node,
  // 					  irr::core::vector3df(10,10,10),
  // 					  irr::core::vector3df(0,0,0),
  // 					  irr::core::vector3df(0,0,0));
  // node->addAnimator(collision_character);
  // collision_character->drop();
  // selector->drop();

  // add camera
  irr::scene::ICameraSceneNode* camera =
    smgr->addCameraSceneNodeFPS(0,100.0f,1.2f);
  camera->setPosition(irr::core::vector3df(node->getAbsolutePosition().X - 2000,
					   node->getAbsolutePosition().Y + 2000,
					   node->getAbsolutePosition().Z));
  camera->setTarget(irr::core::vector3df(node->getAbsolutePosition().X + 2000,
					 node->getAbsolutePosition().Y - 2000,
					 node->getAbsolutePosition().Z));
  camera->setFarValue(42000.0f);

  // create skybox and skydome
  driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
  irr::scene::ISceneNode* skybox =
    smgr->addSkyBoxSceneNode(driver->getTexture("./media/planet.jpg"), // up
			     driver->getTexture("./media/space.jpg"),  // down
			     driver->getTexture("./media/space.jpg"),  // left
			     driver->getTexture("./media/space.jpg"),  // right
			     driver->getTexture("./media/space.jpg"),  // ft
			     driver->getTexture("./media/space.jpg")); // bk
  irr::scene::ISceneNode* skydome =
    smgr->addSkyDomeSceneNode(driver->getTexture("./media/skydome.jpg"), 16, 8, 0.95f, 2.0f);
  driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);

  MyEventReceiver receiver(terrain, skybox, skydome);
  int		lastFPS = -1;
  irr::u32	then = device->getTimer()->getTime();
  const irr::f32 MOVEMENT_SPEED = 1000.f;
  bool		dropped = false;
  long timeToPass = 0;
  device->setEventReceiver(&receiver);
  while (device->run() && device)
    if (device->isWindowActive())
      {

        const irr::u32 now = device->getTimer()->getTime();
        const irr::f32 frameDeltaTime = (irr::f32)(now - then) / 1000.f;
        then = now;

	// 3rd person view
	camera->setPosition(irr::core::vector3df(node->getAbsolutePosition().X - 2000,
						 node->getAbsolutePosition().Y + 2000,
						 node->getAbsolutePosition().Z));
	// camera->setTarget(irr::core::vector3df(node->getAbsolutePosition().X + 2000,
	// 				       node->getAbsolutePosition().Y - 2000,
	// 				       node->getAbsolutePosition().Z));

	if (ac > 1)
	  std::cout <<
	    "pos X : " << camera->getAbsolutePosition().X <<
	    " && Y : " << camera->getAbsolutePosition().Y <<
	    " && Z : " << camera->getAbsolutePosition().Z <<
	    std::endl;

	irr::core::vector3df nodePosition = node->getPosition();
	std::cout << timeToPass << " && " << device->getTimer()->getTime() << std::endl;
	if (timeToPass < device->getTimer()->getTime() && dropped)
	  {
	    node->remove();
	    node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./media/BOMBERRUN.b3d"));
	    node->setMaterialTexture(0, driver->getTexture("./media/bomberman_green.png"));
	    node->setPosition(irr::core::vector3df(-2000,600,5200));
	    node->setAnimationSpeed(40);
	    node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	    node->setScale(irr::core::vector3df(400.f,400.f,400.f));
	    timeToPass = 0;
	    dropped = false;
	  }
	if (receiver.IsKeyDown(irr::KEY_KEY_W))
	  {
	    node->setRotation(irr::core::vector3df(0,270,0));
	    nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
	  }
	else if (receiver.IsKeyDown(irr::KEY_KEY_S))
	  {
	    node->setRotation(irr::core::vector3df(0,90,0));
	    nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
	  }
	else if (receiver.IsKeyDown(irr::KEY_KEY_A))
	  {
	    node->setRotation(irr::core::vector3df(0,180,0));
	    nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
	  }
	else if (receiver.IsKeyDown(irr::KEY_KEY_D))
	  {
	    node->setRotation(irr::core::vector3df(0,360,0));
	    nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
	  }
	else if (receiver.IsKeyDown(irr::KEY_SPACE))
	  {
	    if (!dropped)
	      {
		node->remove();
		timeToPass = device->getTimer()->getTime() + 1100;
		node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./media/BOMBERDROP.b3d"));
		node->setMaterialTexture(0, driver->getTexture("./media/bomberman_green.png"));
		node->setPosition(irr::core::vector3df(-2000,600,5200));
		node->setAnimationSpeed(40);
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		node->setScale(irr::core::vector3df(400.f,400.f,400.f));
		dropped = true;
	      }
	  }
	else if (receiver.IsKeyDown(irr::KEY_ESCAPE))
	  exit(0);
	node->setPosition(nodePosition);
	driver->beginScene(true, true, 0 );
	smgr->drawAll();
	driver->endScene();

	int fps = driver->getFPS();
	if (lastFPS != fps)
	  {
	    irr::core::stringw str = L"Bomberman - [driver : ";
	    str += driver->getName();
	    str += " FPS:";
	    str += fps;
	    str += "]";
	    device->setWindowCaption(str.c_str());
	    lastFPS = fps;
	  }
      }
  device->drop();
  return 0;
}
