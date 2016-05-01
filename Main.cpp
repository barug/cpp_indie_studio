#include <irrlicht.h>
#include "driverChoice.h"

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

enum Action
  {
    STAND,
    WALK,
    DROP
  };

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
  // get driver choice
  irr::video::E_DRIVER_TYPE driverType = irr::driverChoiceConsole();
  if (driverType == irr::video::EDT_COUNT)
    return 1;

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


  // create a selector for collision
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

  // node for character
  irr::scene::IAnimatedMeshSceneNode *node =
    smgr->addAnimatedMeshSceneNode(smgr->getMesh("./media/BOMBERSTAND.b3d"));
  node->setMaterialTexture(0, driver->getTexture("./media/bomberman_red.png"));
  node->setPosition(irr::core::vector3df(-2000,600,5200));
  node->setAnimationSpeed(40);
  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  node->setScale(irr::core::vector3df(200.f,200.f,200.f));
  node->setRotation(irr::core::vector3df(0,270,0));

  // collision character
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
  long		timerDrop = 0;
  long		timerStand = 0;
  int		myRot = 360;
  long		walkingX = 0;
  long		standingX = 0;
  long		walkingZ = 0;
  long		standingZ = 0;
  Action	current = STAND;

  device->setEventReceiver(&receiver);
  while (device->run() && device)
    if (device->isWindowActive())
      {
	// timer
        const irr::u32 now = device->getTimer()->getTime();
        const irr::f32 frameDeltaTime = (irr::f32)(now - then) / 1000.f;
        then = now;

	// current position
	long gX = node->getAbsolutePosition().X;
	long gY = node->getAbsolutePosition().Y;
	long gZ = node->getAbsolutePosition().Z;
	// std::cout << gX << " && " << gY << " && " << gZ << std::endl;

	// get actual position
	irr::core::vector3df nodePosition = node->getPosition();

	// 3rd person view
	camera->setPosition(irr::core::vector3df(gX - 2000, gY + 2000, gZ));
	// camera->setTarget(irr::core::vector3df(gX + 2000, gY - 2000, gZ));

	if ((gX != walkingX || gZ != walkingZ) && (walkingX && walkingZ && current != WALK))
	  {
	    node->remove();
	    node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./media/BOMBERWALK.b3d"));
	    node->setMaterialTexture(0, driver->getTexture("./media/bomberman_red.png"));
	    node->setRotation(irr::core::vector3df(0,myRot,0));
	    node->setAnimationSpeed(40);
	    node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	    node->setScale(irr::core::vector3df(200.f,200.f,200.f));
	    current = WALK;
	  }
	if (gX == standingX && gZ == standingZ && current != STAND)
	  {
	    node->remove();
	    node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./media/BOMBERSTAND.b3d"));
	    node->setMaterialTexture(0, driver->getTexture("./media/bomberman_red.png"));
	    node->setRotation(irr::core::vector3df(0,myRot,0));
	    node->setAnimationSpeed(40);
	    node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	    node->setScale(irr::core::vector3df(200.f,200.f,200.f));
	    current = STAND;
	  }
	standingX = walkingX = gX;
	standingZ = walkingZ = gZ;
	if (timerDrop < device->getTimer()->getTime() && dropped)
	  {
	    current = DROP;
	    timerDrop = 0;
	    dropped = false;
	  }
	if (receiver.IsKeyDown(irr::KEY_KEY_W))
	  {
	    myRot = 270;
	    node->setRotation(irr::core::vector3df(0,myRot,0));
	    nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
	  }
	else if (receiver.IsKeyDown(irr::KEY_KEY_S))
	  {
	    myRot = 90;
	    node->setRotation(irr::core::vector3df(0,myRot,0));
	    nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
	  }
	else if (receiver.IsKeyDown(irr::KEY_KEY_A))
	  {
	    myRot = 180;
	    node->setRotation(irr::core::vector3df(0,myRot,0));
	    nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
	  }
	else if (receiver.IsKeyDown(irr::KEY_KEY_D))
	  {
	    myRot = 360;
	    node->setRotation(irr::core::vector3df(0,myRot,0));
	    nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
	  }
	else if (receiver.IsKeyDown(irr::KEY_SPACE))
	  {
	    if (!dropped && current != DROP)
	      {
		node->remove();
		timerDrop = device->getTimer()->getTime() + 700;
		node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./media/BOMBERDROP.b3d"));
		node->setMaterialTexture(0, driver->getTexture("./media/bomberman_red.png"));
		node->setRotation(irr::core::vector3df(0, myRot, 0));
		node->setAnimationSpeed(70);
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		node->setScale(irr::core::vector3df(200.f,200.f,200.f));
		dropped = true;
	      }
	  }
	else if (receiver.IsKeyDown(irr::KEY_ESCAPE))
	  exit(0);
	node->setPosition(nodePosition);
	driver->beginScene(true, true, 0);
	smgr->drawAll();
	driver->endScene();

	int fps = driver->getFPS();
	if (lastFPS != fps)
	  {
	    irr::core::stringw str = L"Bomberman - driver : [";
	    str += driver->getName();
	    str += "] FPS:[";
	    str += fps;
	    str += "]";
	    device->setWindowCaption(str.c_str());
	    lastFPS = fps;
	  }
      }
  device->drop();
  return 0;
}
